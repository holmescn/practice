let rec f s a b =
    if a < 4000000 then
        if a % 2 <> 0 then f (s + a) b (a + b)
        else f s b (a + b)
    else s

printfn "%A" (f 0 1 1)

