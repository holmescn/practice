open System.IO

let digits =
    File.ReadAllLines(@"p8.txt")
    |> Seq.concat
    |> Seq.map (fun c -> int64(c.ToString()))
    |> List.ofSeq

let first n digits =
    let rec inner n result digits =
        match digits with
        | [] ->
            if n = 0 then result
            else []
        | _ ->
            if n > 0 then inner (n - 1) ((List.head digits)::result) ((List.tail digits))
            else result
    inner n [] digits

let rec f digits max_prod =
    let d = first 13 digits
    match d with
    | [] -> max_prod
    | _ ->
        let prod = List.reduce (fun p x -> p * x) d

        let tail = List.tail digits
        if prod > max_prod then
            f tail prod
        else f tail max_prod

printfn "%A" (f digits 1L)
