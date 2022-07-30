modulo :: Int
modulo = 1000000007
 
twoPow :: Int -> Int
twoPow
  = twoPow' 1
  where 
    twoPow' :: Int -> Int -> Int
    twoPow' curAns 0
      = curAns
    twoPow' curAns n 
      = twoPow' (curAns * 2 `mod` modulo) (n - 1)
 
main :: IO ()
main = do
  input <- getLine
  print . twoPow . read $ input