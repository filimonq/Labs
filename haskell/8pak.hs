import Control.Monad (guard)

change :: Int -> [Int] -> [[Int]]
change 0 _ = [[]]
change a coins = do
  b <- coins
  guard (b <= a)
  next <- change (a - b) coins
  return (b : next)
