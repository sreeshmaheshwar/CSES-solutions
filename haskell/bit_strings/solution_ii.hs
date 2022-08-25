modulo :: Int
modulo 
  = 1000000007

twoPow :: Int -> Int
twoPow 
  = foldr ($) 1 . flip replicate ((`mod` modulo) . (* 2))

main :: IO ()
main 
  = getLine >>= print . twoPow . read