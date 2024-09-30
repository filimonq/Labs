-- 1
a_zip :: [a] -> [b] -> [(a, b)]
a_zip [] _ = []
a_zip _ [] = []
a_zip (x:xs)(y:ys) = (x, y) : a_zip xs ys
-- 2
a_find :: Eq a => [(a, b)] -> a -> b
a_find [] _ = error "no such key"
a_find ((x, y):xs) n = if n == x then y else a_find xs n
-- 3

