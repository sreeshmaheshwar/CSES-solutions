grayCode :: Int -> [String]
grayCode 0
  = [""]
grayCode n
  = map ('0' :) xs ++ (('1' : last xs) : map ('1' :) ys)
  where
    xs       = grayCode (n - 1)
    (_ : ys) = reverse xs

main :: IO ()
main
  = getLine >>= mapM_ putStrLn . grayCode . read