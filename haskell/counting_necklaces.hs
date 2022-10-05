modulo :: Int
modulo
  = 1000000007

add :: Int -> Int -> Int
add a b
  = (a + b) `mod` modulo

multiply :: Int -> Int -> Int
multiply a b
  = a * b `mod` modulo

modPow :: Int -> Int -> Int
modPow _ 0
  = 1
modPow a b
  | odd b     = multiply evenAnswer a
  | otherwise = evenAnswer
  where
    evenAnswer = multiply halfPow halfPow
    halfPow    = modPow a (b `div` 2)

inverse :: Int -> Int
inverse
  = flip modPow (modulo - 2)

divide :: Int -> Int -> Int
divide a b
  = multiply a (inverse b)

solve :: Int -> Int -> Int
solve n m
  = divide (foldr add 0 [modPow m (gcd i n) | i <- [0..n-1]]) n

main :: IO ()
main = do
  line <- getLine
  let [n, m] = map read . words $ line :: [Int]
  print $ solve n m