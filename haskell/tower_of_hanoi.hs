getNumberOfMoves :: Int -> Int
getNumberOfMoves n
  = 2 ^ n - 1

getMoves :: Int -> [(Int, Int)]
getMoves
  = getMoves' (1, 3)
  where
    getMoves' :: (Int, Int) -> Int -> [(Int, Int)]
    getMoves' p 1
      = [p]
    getMoves' p@(l, r) n
      = getMoves' (l, mid) (n - 1) ++ [p] ++ getMoves' (mid, r) (n - 1)
      where 
        mid = 6 - (l + r)

pairToString :: (Show a, Show b) => (a, b) -> String
pairToString (x, y)
  = show x ++ " " ++ show y

main :: IO ()
main = do
  line <- getLine
  let n = read line :: Int
  print . getNumberOfMoves $ n
  mapM_ (putStrLn . pairToString) . getMoves $ n