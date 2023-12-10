module Lib
    ( parseFile,
      parseLine,
      Card (..)
    ) where

import qualified Data.Set as S

data Card = Card Int [Int] [Int] deriving Show

parseFile :: String -> IO Int
parseFile s = do
  content <- readFile s
  return (sum . (map calcScore) . (map parseLine ) . lines $ content)

listToInt :: [String] -> [Int]
listToInt s = map read s

parseLine :: String -> Card
parseLine line =
  let (card, rest) = break (==':') line
      card_id = (read :: String -> Int) $ (words card) !! 1
      (wining, my_nums) = break (=='|') rest
      wining_numbers = listToInt . words $ tail wining
      numbers = listToInt .words $ tail my_nums
  in Card card_id wining_numbers numbers

calcScore :: Card -> Int
calcScore (Card _ wining_numbers my_numbers) = 
  let wining_set = S.fromList wining_numbers
      n_wins = sum [1 | my_number <- my_numbers, S.member my_number wining_set]
  in if n_wins == 0 then 0 else 2^(n_wins - 1)
