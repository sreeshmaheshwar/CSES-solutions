modulo :: Int
modulo
  = 1000000007

-- third fastest out of 5 solutions --
twoPow :: Int -> Int
twoPow 0
  = 1
twoPow n
  = 2 * twoPow (n - 1) `mod` modulo

main :: IO ()
main
  = getLine >>= print . twoPow . read