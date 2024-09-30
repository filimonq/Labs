-- 1 вариант
import System.Random
main :: IO ()
main = do
    digit <- randomRIO (1, 100)
    f digit 1

f :: Int -> Int -> IO ()
f digit attempt = do
    putStrLn "Я загадал число от 1 до 100 (включительно). Попробуй отгадать его."

    putStr "Пользователь> "
    input <- getLine

    if input == show digit
        then do
            putStrLn $ "Ура, вы угадали! Количество попыток: " ++ show attempt
        else do
            putStrLn $ "Увы, вы не угадали. Ваше число " ++ compareGuesses (read input) digit
            f digit (attempt + 1)

compareGuesses :: Int -> Int -> String
compareGuesses input digit
    | input < digit = "меньше, чем загаданное."
    | input > digit = "больше, чем загаданное."
