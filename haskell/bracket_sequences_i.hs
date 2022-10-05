modulo :: Int
modulo
  = 1000000007

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

factorial :: Int -> Int
factorial 0
  = 1
factorial n
  = multiply n (factorial (n - 1))

solve :: Int -> Int
solve n
  | odd n     = 0
  | otherwise = divide (divide (factorial (2 * k)) (factorial k)) (factorial (k + 1))
  where
    k = n `div` 2

main :: IO ()
main
  = getLine >>= print . solve . read