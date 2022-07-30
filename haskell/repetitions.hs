main :: IO ()
main = do
  s <- getLine
  print . solve $ s
 
solve :: [Char] -> Int
solve 
  = solveTR 0 0 '?'
  where
    solveTR :: Int -> Int -> Char -> [Char] -> Int
    solveTR curCnt curAns prevC (c : cs)
      = solveTR newCnt (max curAns newCnt) c cs
      where
        newCnt = if c == prevC then curCnt + 1 else 1
    solveTR _ curAns _ _
      = curAns