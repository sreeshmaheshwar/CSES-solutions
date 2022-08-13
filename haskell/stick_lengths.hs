import Data.List ( sort )
import Data.Maybe ( fromJust )
import Data.Char ( isSpace )
import Control.Monad ( ap, replicateM )
import qualified Data.ByteString.Char8 as BS

getMinCost :: (Int, [Int]) -> Int
getMinCost (n, xs)
  = sum [abs (median - x) | x <- xs]
  where
    median    = take (medianPos + 1) (sort xs) !! medianPos
    medianPos = n `div` 2
 
main :: IO ()
main = readInput >>= print . getMinCost
 
-- FAST INPUT PARSING:

readInput :: IO (Int, [Int])
readInput = evalState parseInput <$> BS.getContents
 
parseInput :: State BS.ByteString (Int, [Int])
parseInput = do
  n <- readInt
  l <- replicateM n readInt
  return (n, l)
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
