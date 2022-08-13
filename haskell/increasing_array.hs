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

main :: IO ()
main = do
  _ <- getLine
  getLine >>= print . minStepsRequired . map read . words