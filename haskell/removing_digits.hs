import Data.Char ( digitToInt ) 

minStepsRequired :: Int -> Int
minStepsRequired 0 
  = 0
minStepsRequired n 
  = 1 + minStepsRequired (n - (digitToInt . maximum . show $ n))

main :: IO ()
main = do
  input <- getLine 
  let n = read input :: Int in print . minStepsRequired $ n
