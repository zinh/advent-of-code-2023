module Main (main) where

import System.Environment
import qualified Data.Map as M
import qualified Data.Set as S
import qualified Lib as L

main :: IO ()
main = do
  args <- getArgs
  content <- readFile (head args)
  putStrLn (show . processContent . lines $ content)

processContent :: [String] -> Int
processContent lines = 
  let result = foldl processLine (M.empty :: M.Map Int Int) (map L.parseLine lines)
  in 0

processLine :: (M.Map Int Int) -> L.Card -> (M.Map Int Int)
processLine m card@(L.Card id  _ _) =
  let nWins = calculateNWins card
  in if nWins == 0 then m else foldl insertCard m [(id + 1)..(id + nWins)]

insertCard :: M.Map Int Int -> Int -> M.Map Int Int
insertCard m cardId

calculateNWins :: L.Card -> Int
calculateNWins (L.Card _ wining_numbers my_numbers) =
  let wining_set = S.fromList wining_numbers
      nWins = sum [1 | my_number <- my_numbers, S.member my_number wining_set]
  in nWins
