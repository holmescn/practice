let rec fib lst =
    match lst with
    | x::xs when x < 4000000 ->
        match xs with
        | y::ys -> fib ((x + y) :: lst)
    | _ -> lst

let result =
    fib [1; 1]
    |> List.filter (fun x -> x % 2 <> 0 && x < 4000000)
    |> List.reduce (fun acc elem -> acc + elem)

printfn "%A" result

