-- 1
arctan :: (Ord a, Floating a) => a -> a -> a
arctan x n =  if n > 1 then arctan x (n-1) + ((-1)**(n-1)) * (x**(2*n-1)) / (2*n - 1) else x
atan' :: (Ord t, Floating t) => t -> t -> t -> t
atan' x n eps = 
    if - 1 <= x && x <= 1 then
        if abs (arctan x n - arctan x (n+1)) > eps then
            atan' x (n + 1) eps
        else
            arctan x n
    else
        error "Ошибка!"

-- 2
f :: Floating a => a -> a
f x = 2 ** x - x ** 2
solver :: (Double -> Double) -> Double -> Double -> Double -> Double
solver f a b eps = 
    let c = (a + b) / 2 in if abs(f c) < eps then c else
            if signum (f c) /= signum (f b)
            then solver f c b eps 
            else solver f a c eps
-- 3

helper :: (Ord t1, Num t1, Num t2) => t2 -> t2 -> t1 -> t2
helper n1 n2 len = if len > 1 then 
                        helper (n1 + n2) n1 (len-1)
                   else n1
                   
fibonachi :: Integer -> Integer
fibonachi = helper 1 1
