toSpaceSeparatedString :: Show a => [a] -> String
toSpaceSeparatedString
  = unwords . map show

printListWithLength :: Show a => [a] -> IO ()
printListWithLength xs = do
  print . length $ xs
  putStrLn . toSpaceSeparatedString $ xs

type TwoSetsAnswer = Maybe ([Int], [Int])

twoSets :: Int -> TwoSetsAnswer
twoSets n 
  | odd naturalSum = Nothing
  | otherwise      = Just (twoSets' n (naturalSum `div` 2))
  where
    naturalSum = n * (n + 1) `div` 2
    twoSets' :: Int -> Int -> ([Int], [Int])
    twoSets' 0 _
      = ([], [])
    twoSets' a b
      | b < a     = (a : xs, ys)
      | otherwise = (xs, a : ys)
      where
        (xs, ys) = twoSets' (a - 1) (if b < a then b else b - a)

printAnswer :: TwoSetsAnswer -> IO ()
printAnswer Nothing = do
  putStrLn "NO"
printAnswer (Just (xs, ys)) = do
  putStrLn "YES"
  printListWithLength xs
  printListWithLength ys

main :: IO ()
main
  = getLine >>= printAnswer . twoSets . read
