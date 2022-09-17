import Data.List (subsequences)

solve :: [Int] -> Int
solve xs 
  = minimum [abs (sum xs - 2 * sum ys) | ys <- subsequences xs]

main :: IO ()
main = do
  _ <- getLine
  getLine >>= print . solve . map read . words