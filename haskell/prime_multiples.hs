import Data.Maybe ( fromJust )
import Data.Char ( isSpace )
import Data.List (subsequences)
import Control.Monad ( ap, replicateM )
import qualified Data.ByteString.Char8 as BS

primeMultiples :: Integer -> [Integer] -> Integer
primeMultiples n
  = sum . map getIntersection . tail . subsequences
  where
    getIntersection :: [Integer] -> Integer
    getIntersection xs
      = (n `div` product xs) * if odd $ length xs then 1 else -1

main :: IO ()
main = readInput >>= print . uncurry primeMultiples

-- FAST INPUT PARSING:

readInput :: IO (Integer, [Integer])
readInput = evalState parseInput <$> BS.getContents

parseInput :: State BS.ByteString (Integer, [Integer])
parseInput = do
  n <- readInteger
  k <- readInt
  xs <- replicateM k readInteger
  return (n, xs)

readInt :: State BS.ByteString Int
readInt = state $ fromJust . BS.readInt . BS.dropWhile isSpace

readInteger :: State BS.ByteString Integer
readInteger = state $ fromJust . BS.readInteger . BS.dropWhile isSpace

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