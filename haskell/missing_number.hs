main :: IO ()
main = do
  inputN <- getLine
  inputA <- getLine
  let n = read inputN :: Int in print . (n * (n + 1) `div` 2 - ) . sum . map read . words $ inputA