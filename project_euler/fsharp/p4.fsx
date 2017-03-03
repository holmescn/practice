
let rec factorize a b n =
    if a < 100 || b < 100 || a > 999 || b > 999 then (0, 0)
    else
        let product = a * b
        if product > n then factorize (a - 1) b n
        elif product < n then factorize a (b + 1) n
        else (a, b)

let palindrome a b c =
    a * 100000 + b * 10000 + c * 1000 + c * 100 + b * 10 + a

let rec f a b c =
    let n = palindrome a b c
    let s = (int (sqrt (float n)))
    let (f1, f2) = (factorize s (s + 1) n)

    if f1 = 0 && f2 = 0 then
        if c = 0 then
            if b = 0 then f (a - 1) 9 9
            else f a (b - 1) 9
        else f a b (c - 1)
    else (n, f1, f2)

printfn "%A" (f 9 9 9)

