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
      seeds = getSeeds (head lstLine)
      m = getMapLst . drop 2 $ lstLine
   in minimum . map (processSeed m) $ seeds

