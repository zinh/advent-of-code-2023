{-# LANGUAGE GADTs #-}

module Lib
  ( processSeed,
    getSeeds,
    getMapLst,
  )
where

import Data.List (find, isInfixOf)
import qualified Data.Map as M
import qualified Data.Maybe

data Range where
  Range :: {from :: Int, to :: Int, range :: Int} -> Range
  deriving (Show)

processSeed :: M.Map String [Range] -> Int -> Int
processSeed m seedId =
  let pipelines = ["seed-to-soil", "soil-to-fertilizer", "fertilizer-to-water", "water-to-light", "light-to-temperature", "temperature-to-humidity", "humidity-to-location"]
      fn currentValue step =
        let ranges = Data.Maybe.fromMaybe [] (M.lookup step m)
         in getMapValue currentValue ranges
   in foldl fn seedId pipelines

getSeeds :: String -> [Int]
getSeeds = map read . words . dropWhile (/= ' ')

getMapLst :: [String] -> M.Map String [Range]
getMapLst content = snd (foldl fn ("", M.empty) content)
  where
    fn (current, m) line
      | null line = (current, m)
      | "map" `isInfixOf` line = (takeWhile (/= ' ') line, m)
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
  let isInsideRange item (Range f _ r) = item >= f && item < (f + r)
   in case find (isInsideRange n) ranges of
        Just (Range f t _) -> t + (n - f)
        Nothing -> n
