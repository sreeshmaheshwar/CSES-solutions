import Data.Maybe ( fromJust )
import Data.Char ( isSpace )
import Control.Monad ( ap, replicateM )
import qualified Data.ByteString.Char8 as BS

modulo :: Int
modulo = 1000000007

modPow :: Int -> Int -> Int -> Int
modPow _ 0 _ 
  = 1
modPow a b m
  | odd b     = (evenAnswer * a) `mod` m
  | otherwise = evenAnswer
  where
    evenAnswer = (halfPow * halfPow) `mod` m
    halfPow    = modPow a (b `div` 2) m

solve :: (Int, Int, Int) -> Int
solve (a, b, c) 
  = modPow a (modPow b c (modulo - 1)) modulo
 
main :: IO ()
main = readInput >>= mapM_ (print . solve) 
 
-- FAST INPUT PARSING:

readInput :: IO [(Int, Int, Int)]
readInput = evalState parseInput <$> BS.getContents
 
parseInput :: State BS.ByteString [(Int, Int, Int)]
parseInput = do
  n <- readInt
  replicateM n parseTriple
  
parseTriple :: State BS.ByteString (Int, Int, Int)
parseTriple = do
  a <- readInt
  b <- readInt
  c <- readInt
  return (a, b, c)
 
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