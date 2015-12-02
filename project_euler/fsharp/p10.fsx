let rec f sum numbers =
    match numbers with
    | x::xs ->
        f (sum + x) (List.filter (fun y -> y % x <> 0L) xs)
    | [] -> sum

printfn "%A" (f 0L [2L .. 2000000L])
