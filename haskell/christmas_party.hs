modulo :: Int
modulo 
  = 1000000007

solve :: Int -> Int 
solve 0 
  = 1
solve n 
  = n * solve (n - 1) `mod` modulo + if odd n then -1 else 1

main :: IO ()
main 
  = getLine >>= print . solve . read