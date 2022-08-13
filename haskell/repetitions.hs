longestRepetition :: [Char] -> Int
longestRepetition 
  = longestRepetitionTR 0 0 '?'
  where
    longestRepetitionTR :: Int -> Int -> Char -> [Char] -> Int
    longestRepetitionTR _ curAns _ []
      = curAns
    longestRepetitionTR curCnt curAns prevC (c : cs)
      = longestRepetitionTR newCnt (max curAns newCnt) c cs
      where
        newCnt = if c == prevC then curCnt + 1 else 1

main :: IO ()
main = getLine >>= print . longestRepetition