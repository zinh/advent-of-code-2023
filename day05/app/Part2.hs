module Main where

import Lib
import System.Environment (getArgs)

main :: IO ()
main = do
  args <- getArgs
  content <- readFile (head args)
  print (process content)

process :: String -> Int
process content =
  let lstLine = lines content
      seedRanges = (split 2) . getSeeds . head $ lstLine
      seeds = [i | r <- seedRanges, i <- [(head r) .. ((head r) + (r !! 1) - 1)]]
      m = getMapLst . drop 2 $ lstLine
   in minimum . map (processSeed m) $ seeds

split :: Int -> [a] -> [[a]]
split n [] = []
split n lst = take n lst : split n (drop n lst)
