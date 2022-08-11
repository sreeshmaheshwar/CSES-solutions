import Data.Maybe ( fromJust )
import Data.Char ( isSpace )
import Control.Monad ( ap, replicateM )
import qualified Data.ByteString.Char8 as BS

getKthRemoved :: Int -> Int -> Int
getKthRemoved 1 _
  = 1
getKthRemoved n k
  | nextK <= 0 = if ans > n then ans `mod` n else ans
  | otherwise  = nextAns * 2 + if odd n then 1 else -1
  where
    nextK   = k - (n + 1) `div` 2
    ans     = k * 2
    nextAns = getKthRemoved (n `div` 2) nextK

main :: IO ()
main = do
  inputs <- evalState parseInput <$> BS.getContents
  mapM_ (print . uncurry getKthRemoved) inputs

-- FAST INPUT PARSING:

parseInput :: State BS.ByteString [(Int, Int)]
parseInput = do
  n <- readInt
  replicateM n parsePair

parsePair :: State BS.ByteString (Int, Int)
parsePair = do
  a <- readInt
  b <- readInt
  return (a, b)

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