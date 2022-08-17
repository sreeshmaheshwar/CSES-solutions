executeWeirdAlgorithm :: Int -> [Int]
executeWeirdAlgorithm 1 
  = [1]
executeWeirdAlgorithm n 
  | even n    = n : executeWeirdAlgorithm (n `div` 2)
  | otherwise = n : executeWeirdAlgorithm (3 * n + 1)

toSpaceSeparatedString :: Show a => [a] -> String
toSpaceSeparatedString
  = unwords . map show

main :: IO ()
main
  = getLine >>= putStrLn . toSpaceSeparatedString . executeWeirdAlgorithm . read
