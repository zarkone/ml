import Data.Ratio
o x = 0
s x = x + 1

sg x =  if x > 0 
        then 1
        else 0

add x 0 = x
add x y = s (add x (y-1))

mul x 0 = o x
mul x y = add (mul x (y-1)) x

p x 0 = s (o x)
p x y = mul (p x (y-1)) x                   
---------------------------------------

--ch x i = add ( add (p x i) (p (s (s (s (o x)))) i) ) (p i x) 

--zn x i = add (add (mul (s (s (o x))) x) (s (s (o x))) ) i 

---------------------------------------

myMin x y = if x > y then y
          else x

pre x y z = fromRational (x % z)          

main = do
       putStr (o 3)