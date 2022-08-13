solve :: Int -> [Int] 
solve n
  = [i * (i + 5) * (i * i - i + 2) `div` 2 | i <- [0..n-1]]

main :: IO ()
main = getLine >>= mapM_ print . solve . read