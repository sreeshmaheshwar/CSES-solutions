import Data.List ( subsequences )
import Data.Maybe ( fromJust )
import Data.Char ( isSpace )
import Control.Monad ( ap, replicateM )
import qualified Data.ByteString.Char8 as BS

solve :: [Int] -> Int
solve xs = minimum [abs (sum xs - 2 * sum ys) | ys <- subsequences xs]

main :: IO ()
main = readInput >>= print . solve

-- FAST INPUT PARSING:

readInput :: IO [Int]
readInput = evalState parseInput <$> BS.getContents
 
parseInput :: State BS.ByteString [Int]
parseInput = do
  n <- readInt
  replicateM n readInt
  where
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