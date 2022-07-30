import Data.List ( group, sort )
import Data.Maybe ( fromJust )
import Data.Char ( isSpace )
import Control.Monad ( ap, replicateM )
import qualified Data.ByteString.Char8 as BS
 
main :: IO ()
main = do
  (_, l) <- evalState parseInput <$> BS.getContents
  print . length . group . sort $ l
  
-- FAST INPUT PARSING:
 
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
  pure = return
  (<*>) = ap
 
instance Monad (State s) where
  return a = State $ \s -> (a, s)
  m >>= k  = State $ \s -> let (a, s') = runState m s in runState (k a) s'
 
evalState :: State s a -> s -> a
evalState m s = fst (runState m s)
 
state :: (s -> (a, s)) -> State s a
state = State
