main :: IO ()
main = do
  inpN <- getLine
  inpA <- getLine
  let n = read inpN in print . (n * (n + 1) `div` 2 - ) . sum . map read . words $ inpA