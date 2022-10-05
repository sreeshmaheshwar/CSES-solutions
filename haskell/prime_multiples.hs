import Data.List (subsequences)

primeMultiples :: Integer -> [Integer] -> Integer
primeMultiples n
  = sum . map getIntersection . tail . subsequences
  where
    getIntersection :: [Integer] -> Integer
    getIntersection xs
      = (n `div` product xs) * if odd $ length xs then 1 else -1

main :: IO ()
main = do
  line <- getLine
  let (n : _) = map read . words $ line :: [Integer]
  getLine >>= print . primeMultiples n . map read . words