import qualified Data.ByteString.Char8 as BS
import qualified Data.Map as M
import Data.Maybe

main = do content <- fmap BS.lines BS.getContents
          let (dict, foreignLang) = parseInp content
              def = BS.pack "eh"
              english = map (\x -> fromMaybe def $ M.lookup x dict) foreignLang
          mapM_ BS.putStrLn english

parseInp :: [BS.ByteString] -> (M.Map BS.ByteString BS.ByteString, [BS.ByteString])
parseInp xs = go xs M.empty
   where
     go (x:xs) m = case BS.words x of
                     [v, k] -> go xs (M.insert k v m)
                     otherwise -> (m, xs)
