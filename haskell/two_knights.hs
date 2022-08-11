main :: IO ()
main = do
  input <- getLine 
  let n = read input :: Int in mapM_ print [i*(i+5)*(i*i-i+2)`div`2 | i<-[0..n-1]]