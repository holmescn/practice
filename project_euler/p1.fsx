let sum =
    [ 1 .. 999 ]
    |> List.filter (fun x -> x % 3 = 0 || x % 5 = 0)
    |> List.reduce (fun acc x -> acc + x)
printfn "%A" sum
