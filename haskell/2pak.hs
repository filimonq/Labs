integrate :: (Double -> Double) -> Double -> Double -> Double
integrate f a b = integrate' f a b 1000 where
  integrate' f a b 0 = 0
  integrate' f a b n = (f a + f (a + h)) / 2 * h + integrate' f (a + h) b (n - 1)
    where h = (b - a) / n

f1 :: Double -> Double
f1 = \x -> 2 * x ** 2 + 3 * x - 1

f2 :: Double -> Double
f2 = (* 2) . (**2) -- 2 * x**2

f3 :: Double -> Double
f3 = (1/) . ((^2) . cos)

f4 :: Double -> Double
f4 = exp . (*(-1)) . (^2)

f5 :: Double -> Double
f5 = \x -> 
  if x > 0 && x <= 1
    then integrate(\t -> sin t / t) (10 ** (-100)) x
    else error "Ошибка"

