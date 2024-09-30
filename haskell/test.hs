main = putStrLn "Hello, World!"

f151 (-1) = error "error!!!"
--f151 x =
--  let a = x^2 
--      b = 1 + x in
--    a / b
f151 x =
    a / b
    where a = x^2
          b = 1+x


f154 x = 
    if x < (-2) || x > 2 then
      log $ x^2 - 4
    else error "x in exceptional range"

lg = logBase 10

-- 152 165.3 167 

f152 x = 
    if 3*x - x^3 > 0 then
      sqrt $ 3*x - x^3
    else error "error!!!"

f167 x = 
    if 1 - 2 * cos x > 0 then 
      lg $ 1 - 2 * cos x
    else error "error"

f165_3 x = 
    if sin 2*x > 0 || sin 3*x > 0 then
      sqrt(sin 2*x) + sqrt(sin 3*x)
    else error "error"

f431 n = sum [x ^ 2 | x <- [1, 3 .. (2 * n - 1)]] / sum [y ^ 2 | y <- [2, 4 .. (2 * n)]]

factorial 0 = 1
factorial 1 = 1
factorial n = n * factorial (n - 1)
-- 
factorial2 n | n == 0 || n == 1 = 1
factorial2 n = n * factorial (n -1)

fibonachi 0 = 0
fibonachi 1 = 1
fibonachi n = fibonachi(n-1) + fibonachi(n-2)

fibonachi2 n | n >= 2 = fibonachi2(n-1) + fibonachi2(n-2)
fibonachi2 n | n >= 0 = n

fib n
  | n < 0     = error "n must be greater than or equal to 0"
  | otherwise = fibHelper n 0 1

fibHelper 0 a b = a
fibHelper n a b = fibHelper (n - 1) b (a + b)
-------
arctan x n =  if n > 1
            then arctan x (n-1) + ((-1)**(n-1)) * (x**(2*n-1)) / (2*n - 1)
            else x

limArctan :: (Ord t, Floating t) => t -> t -> t -> t
limArctan x n eps =     if abs(arctan x n - arctan x (n+1)) > eps 
                        then limArctan x (n+1) eps 
                        else arctan x n



f n x = (x ** (2 * n - 1)) * (((-1) ** (n - 1)) / (2 * n - 1))

atan' :: (Ord t, Floating t) => t -> t -> t -> t
atan' n x eps
  | -1 <= x && x <= 1 =
      if abs (f n x) >= eps
        then f n x + atan' (n + 1) x eps
        else f n x

fib2 n = helper 0 1 n
  where helper curr prev n
          | n == 0   = curr
          | n > 0    = helper (curr+prev) curr (n-1)
          | n < 0    = helper prev (curr-prev) (n+1)

sh :: Double -> Double
sh x = 0.5 * (exp x - exp (-x))

--

replaceAt :: a -> [a] -> Int -> [a]
replaceAt v [] i = error "error: index out of range"
replaceAt v xs 0 = v : tail xs
replaceAt v (x:xs) i = x : replaceAt v xs (i-1)

-- 1 Контрольная
ff :: Double -> Double
ff x = (sqrt(9 + 2 * x) - 5) / (x**(1/3) - 2)
--  2
enumerate :: [a] -> [(a, Int)]
enumerate = flip zip $ [0..]

onlyOddElements :: [a] -> [a]
onlyOddElements xs = map fst (filter (\(_, x) -> even x) (enumerate xs)) 
-- 3
count :: Eq a => a -> [a] -> Int
count _ [] = 0
count y (x:xs)
    | y == x = 1 + count y xs
    | otherwise = count y xs
-- 4
unique :: Eq a => [a] -> [a]
unique [] = []
unique (x:xs) = x : unique (filter (/= x) xs)
-- Контрольная 
