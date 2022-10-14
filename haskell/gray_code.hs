grayCode :: Int -> [String]
grayCode 0
  = [""]
grayCode n
  = map ('0' :) prvCode ++ ['1' : last prvCode] ++ map ('1' :) (tail . reverse $ prvCode)
  where
    prvCode = grayCode (n -1)

main :: IO ()
main
  = getLine >>= mapM_ putStrLn . grayCode . read