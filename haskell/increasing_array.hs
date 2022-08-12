main :: IO ()
main = do
  _ <- getLine
  input <- getLine
  print . minStepsRequired . map read . words $ input

minStepsRequired :: [Int] -> Int
minStepsRequired
  = minStepsRequiredTR 0 0
  where
    minStepsRequiredTR :: Int -> Int -> [Int] -> Int
    minStepsRequiredTR _ moves []
      = moves
    minStepsRequiredTR curMax moves (x : xs)
      = minStepsRequiredTR newMax (moves + newMax - x) xs 
      where
        newMax = max curMax x