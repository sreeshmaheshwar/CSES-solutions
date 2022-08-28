modulo :: Int
modulo 
  = 1000000007

-- slowest out of 5 solutions, but most elegant? --
twoPow :: Int -> Int
twoPow
  = (!!) (iterate ((`mod` modulo) . (* 2)) 1)

main :: IO ()
main 
  = getLine >>= print . twoPow . read