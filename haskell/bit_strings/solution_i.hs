modulo :: Int
modulo 
  = 1000000007

twoPow :: Int -> Int
twoPow
  = twoPowTR 1
  where 
    twoPowTR :: Int -> Int -> Int
    twoPowTR curAns 0
      = curAns
    twoPowTR curAns n 
      = twoPowTR (curAns * 2 `mod` modulo) (n - 1)

main :: IO ()
main 
  = getLine >>= print . twoPow . read