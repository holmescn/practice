(* a + b + c = 1000
   a^2 + b^2 = c^2
             = (1000 - a - b)^2
             = 1000000 - 2000a - 2000b + a^2 + 2ab + b^2

   2000a + 2000b + 2ab = 1000000, a < b
   2b(1000 + a) = 1000000 - 2000a
   b = (500000 - 1000a) / (1000 - a)
 *)

let rec f a =
    let b = (500000 - 1000 * a) / (1000 - a)
    let c = 1000 - a - b
    if a < b && b < c && a*a + b*b = c*c then a * b * c
    else f (a + 1)

printfn "%A" (f 1)
