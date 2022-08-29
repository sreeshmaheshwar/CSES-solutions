diceFaces :: Int
diceFaces = 6

modulo :: Int
modulo = 1000000007

addUnderMod :: Int -> Int -> Int
addUnderMod x y = (x + y) `mod` modulo

sumListUnderMod :: [Int] -> Int
sumListUnderMod = foldr addUnderMod 0

-- applies memoization by carrying previous six results as a parameter --
diceCombinations :: Int -> Int
diceCombinations
  = diceCombinationsMemTR [1]
  where
    diceCombinationsMemTR :: [Int] -> Int -> Int
    diceCombinationsMemTR (x : _) 0
      = x
    diceCombinationsMemTR xs n
      = diceCombinationsMemTR nxs (n - 1)
      where
        nxs = sumListUnderMod xs : (if length xs == diceFaces then init else id) xs

main :: IO ()
main = getLine >>= print . diceCombinations . read