main :: IO ()
main = do
  _ <- getLine
  input <- getLine
  print . maximum . sequence [(2 *) . maximum, sum] . map read . words $ input