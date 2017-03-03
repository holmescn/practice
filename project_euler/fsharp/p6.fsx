let numbers = [1 .. 100]
let sum = List.reduce (fun a x -> a + x)
let square = (fun x -> x*x)
let squareOfSum =
    numbers
    |> sum
    |> square

let sumOfSquare =
    numbers
    |> List.map square
    |> sum

let result = squareOfSum - sumOfSquare
printfn "%A" result
