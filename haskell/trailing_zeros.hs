trailingZeros :: Int -> Int
trailingZeros 
  = sum . tail . takeWhile (/= 0) . iterate (`div` 5)

main :: IO ()
main 
  = getLine >>= print . trailingZeros . read