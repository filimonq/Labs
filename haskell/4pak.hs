-- 1 
toSeries :: String -> [String]
toSeries [] = [] 
toSeries [x, y] = if x == y then [x:[y]]  else [[x], [y]] 
toSeries (x:xs) = 
    let y = toSeries xs in 
        if x == head (head y) then (x:head y) : tail y else [x] : y
-- 2
encodeSeries :: [String] -> [(Int, Char)]
encodeSeries [] = []
encodeSeries xs = map (\ x -> (length x, head x)) xs
-- 3 
writeCode :: [(Int, Char)] -> String
writeCode = foldl (\acc (x,y) -> acc ++ show x ++ [y]) []
-- 4
makeAssoc :: Eq a => [(a, b)] -> a -> b 
makeAssoc xs key = foldr (\(x, y) acc -> if x == key then y else acc) (error "no such key") xs
