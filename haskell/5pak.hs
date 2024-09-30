newtype Union a = Union { getUnion :: [a] } deriving (Eq, Show)
-- ( ͡° ͜ʖ ͡°)
instance Eq a => Semigroup (Union a) where
  (<>) :: Eq a => Union a -> Union a -> Union a
  (<>) xs ys = Union (getUnion xs `union` getUnion ys)
    where 
        union [][] = []
        union [] (y:ys) = let c = union [] ys in 
            if y `notElem` c then y : c else c 
        union (x:xs) ys = let c = union xs ys in
            if x `notElem` c then x : c else c

instance (Eq a) => Monoid (Union a) where
    mempty = Union []
    mappend = (<>)

unique :: Eq a => [a] -> [a]
unique = getUnion . foldr (<>) mempty . listOfUnion
  where
    singleton x = [x]
    listOfUnion = fmap (Union . singleton)

