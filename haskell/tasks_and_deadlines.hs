import Data.Maybe ( fromJust )
import Data.Char ( isSpace )
import Data.List (sort)
import Control.Monad ( ap, replicateM )
import qualified Data.ByteString.Char8 as BS

maxReward :: [(Int, Int)] -> Int 
maxReward
  = maxRewardTR 0 0 . sort
  where
    maxRewardTR :: Int -> Int -> [(Int, Int)] -> Int
    maxRewardTR _ curAns []
      = curAns
    maxRewardTR curTime curAns ((duration, deadline) : tasks)
      = maxRewardTR newTime (curAns + deadline - newTime) tasks
      where 
        newTime = curTime + duration

main :: IO ()
main = readInput >>= print . maxReward
 
-- FAST INPUT PARSING:

readInput :: IO [(Int, Int)]
readInput = evalState parseInput <$> BS.getContents
 
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