module Main where

import Data.List (find, isInfixOf)
import qualified Data.Map as M
import Debug.Trace (trace)
import System.Environment (getArgs)

data Range = Range {from :: Int, to :: Int, range :: Int} deriving (Show)

main :: IO ()
main = do
  args <- getArgs
  content <- readFile (head args)
  putStrLn (show . process $ content)

process :: String -> Int
process content =
  let lstLine = lines content
      seeds = getSeeds (head lstLine)
      m = getMapLst . drop 2 $ lstLine
   in trace (show m) 10

getSeeds :: String -> [Int]
getSeeds s = map read . words . snd . (break (== ' ')) $ s

getMapLst :: [String] -> M.Map String [Range]
getMapLst content = snd (foldl fn ("", M.empty) content)
  where
    fn (current, m) line
      | null line = (current, m)
      | isInfixOf "map" line = (takeWhile (/= ' ') line, m)
      | otherwise =
          let values = intToRange . (map read) . words $ line
              currentValue = case M.lookup current m of
                Just v -> values : v
                Nothing -> [values]
           in (current, M.insert current currentValue m)

intToRange :: [Int] -> Range
intToRange (destStart : srcStart : len : _) = Range {from = srcStart, to = destStart, range = len}

getMapValue :: Int -> [Range] -> Int
getMapValue n ranges =
  let isInsideRange item (Range f _ r) = item >= f && item <= (f + r)
   in case find (isInsideRange n) ranges of
        Just (Range f t _) -> t + (n - f)
        Nothing -> n
