let filterList n lst = List.filter (fun x -> x % n <> 0) lst
let rec f sum numbers =
    match numbers with
    | x::xs ->
        f (sum + (int64 x)) (filterList x xs)
    | [] -> sum

printfn "%A" (f 0L [2 .. 2000000])
