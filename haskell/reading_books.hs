main :: IO ()
main = do
  _ <- getLine
  getLine >>= print . maximum . sequence [(2 *) . maximum, sum] . map read . words