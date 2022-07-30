main :: IO ()
main = do
  _ <- getLine
  input <- getLine
  print . solve . map read . words $ input
 
solve :: [Integer] -> Integer
solve
  = solveTR 0 0
  where
    solveTR :: Integer -> Integer -> [Integer] -> Integer
    solveTR curMax moves (x : xs)
      = let newMax = max curMax x in solveTR newMax (moves + newMax - x) xs 
    solveTR _ moves _
      = moves