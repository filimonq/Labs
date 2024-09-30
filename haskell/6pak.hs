-- 6.1 
fmap :: Monad f => (a -> b) -> f a -> f b
fmap f x =
    let f' = \x' -> return $ f x'
    in x >>= f'
    
pure :: Monad f => a -> f a
pure = return

(<*>) :: Monad f => f (a -> b) -> f a -> f b
f <*> x = do
    f' <- f
    f' <$> x
-- 6.2
e=2.718

ln :: Double -> Double
ln = log

helper1 :: Double -> Maybe Double
helper1 x
    |x <= 0 = Nothing
    |cos (ln x)**e == 0 = Nothing
    |otherwise = Just $ tan $ ln x **e

helper2 :: Double -> Maybe Double
helper2 x
    |x == 0 = Nothing 
    |otherwise =Just $ (1/) $ (2*) $ cos x

helper3 :: Double -> Maybe Double
helper3 x
    |x**2 + 2*x - 10 == 0 = Nothing
    |otherwise = Just (x**2 + 2*x - 10)

--fSafe :: Double -> Maybe Double
--fSafe x = 
--     (/) <$> ((+) <$> helper1 x <*> helper2 x) <*> helper3 x
