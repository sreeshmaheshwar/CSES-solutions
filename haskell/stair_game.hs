import Data.Bits ( xor )
import Data.Maybe ( fromJust )
import Data.Char ( isSpace )
import Control.Monad ( ap, replicateM )
import qualified Data.ByteString.Char8 as BS

solve :: [Int] -> String
solve xs
  | not (null odds) && foldr1 xor odds > 0 = "first"
  | otherwise                              = "second"
  where
    odds = [x | (x, i) <- zip xs [0..], odd i]

main :: IO ()
main = do
  inputLists <- evalState parseInput <$> BS.getContents
  mapM_ (putStrLn . solve) inputLists

-- FAST INPUT PARSING:

parseInput :: State BS.ByteString [[Int]]
parseInput = do
  t <- readInt
  replicateM t parseList

parseList :: State BS.ByteString [Int]
parseList = do
  n <- readInt
  replicateM n readInt

readInt :: State BS.ByteString Int
readInt = state $ fromJust . BS.readInt . BS.dropWhile isSpace

newtype State s a = State { runState :: s -> (a, s) }

instance Functor (State s) where
  fmap f m = State $ \s -> let (a, s') = runState m s in (f a, s')

instance Applicative (State s) where
  pure  = return
  (<*>) = ap

instance Monad (State s) where
  return a = State $ \s -> (a, s)
  m >>= k  = State $ \s -> let (a, s') = runState m s in runState (k a) s'

evalState :: State s a -> s -> a
evalState m s = fst (runState m s)

state :: (s -> (a, s)) -> State s a
state = State