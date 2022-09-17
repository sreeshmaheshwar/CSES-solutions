solve :: [Int] -> Int
solve
  = solve' 0 0
  where
    solve' :: Int -> Int -> [Int] -> Int
    solve' s0 s1 []
      = abs (s0 - s1)
    solve' s0 s1 (x : xs)
      = min (solve' (s0 + x) s1 xs) (solve' s0 (s1 + x) xs)

main :: IO ()
main = do
  _ <- getLine
  getLine >>= print . solve . map read . words