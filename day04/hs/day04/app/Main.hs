module Main (main) where

import System.Environment
import Lib

main :: IO ()
main = do
  args <- getArgs
  result <- parseFile (head args)
  putStrLn (show result)
