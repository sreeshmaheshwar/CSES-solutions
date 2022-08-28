modulo :: Int
modulo
  = 1000000007

modPow :: Int -> Int -> Int
modPow _ 0
  = 1
modPow a b
  | odd b     = (evenAnswer * a) `mod` modulo
  | otherwise = evenAnswer
  where
    evenAnswer = (halfPow * halfPow) `mod` modulo
    halfPow    = modPow a (b `div` 2)

-- fastest out of 4 solutions, works in O(log n) time! --
twoPow :: Int -> Int
twoPow 
  = modPow 2

main :: IO ()
main
  = getLine >>= print . twoPow . read