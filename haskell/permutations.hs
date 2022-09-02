toSpaceSeparatedString :: Show a => [a] -> String
toSpaceSeparatedString
  = unwords . map show

maybeToString :: Show a => Maybe [a] -> String
maybeToString Nothing 
  = "NO SOLUTION"
maybeToString (Just xs)
  = toSpaceSeparatedString xs

beautifulPermutation :: Int -> Maybe [Int]
beautifulPermutation n
  | n == 2 || n == 3 = Nothing
  | otherwise        = Just (filter even [1..n] ++ filter odd [1..n])

main :: IO ()
main
  = getLine >>= putStrLn . maybeToString . beautifulPermutation . read
