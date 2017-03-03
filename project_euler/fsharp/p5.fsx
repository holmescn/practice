let rec gcd a b =
    if a < b then gcd b a
    elif a % b <> 0 then gcd (a % b) b
    else b

let lcm a b = a * b / (gcd a b)

let rec f n p =
    if n < 10 then f (n + 1) (lcm p n)
    else p

printfn "%A" (f 1 1)

