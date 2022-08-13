import Data.List ( sort )
import Data.Maybe ( fromJust )
import Data.Char ( isSpace )
import Control.Monad ( ap, replicateM )
import qualified Data.ByteString.Char8 as BS
 
smallestSum :: [Int] -> Int
smallestSum
  = smallestSum' 1 . sort 
  where 
    smallestSum' :: Int -> [Int] -> Int
    smallestSum' curSmallestSum []
      = curSmallestSum
    smallestSum' curSmallestSum (x : xs) 
      | x > curSmallestSum = curSmallestSum
      | otherwise          = smallestSum' (curSmallestSum + x) xs
      
 
main :: IO ()
main = do
  inputList <- evalState parseInput <$> BS.getContents
  print . smallestSum $ inputList
  
-- FAST INPUT PARSING:
 
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