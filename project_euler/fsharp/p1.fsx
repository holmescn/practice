let rec f s n =
    if n < 1000 then
        if n % 3 = 0 || n % 5 = 0 then f (s + n) (n + 1)
        else f s (n + 1)
    else s
printfn "%A" (f 0 1)

