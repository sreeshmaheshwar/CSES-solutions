import Data.Maybe ( fromJust )
import Data.Char ( isSpace )
import Control.Monad ( ap, replicateM )
import qualified Data.ByteString.Char8 as BS

modulo :: Int
modulo = 1000000007
 
modPow :: Int -> Int -> Int
modPow _ 0
  = 1
modPow a b
  | odd b     = (evenAnswer * a) `mod` modulo
  | otherwise = evenAnswer
  where
    evenAnswer = (halfPow * halfPow) `mod` modulo
    halfPow    = modPow a (b `div` 2)
 
main :: IO ()
main = do
  inputs <- evalState parseInput <$> BS.getContents
  mapM_ (print . uncurry modPow) inputs
 
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