open System.IO

let initArray =
    File.ReadAllLines(@"p11.txt")
    |> Seq.map (fun l -> l.Split(' ') |> Seq.map int32 |> Seq.toArray)
    |> Seq.toArray

let productOfSeq array =
    Seq.reduce (fun p x -> p * x) array

let matrix = Array2D.init 20 20 (fun i j -> initArray.[i].[j])
let maxProductOfRows =
    let mutable maxProd = 0
    for i = 0 to 19 do
        for j = 0 to 16 do
            maxProd <- List.max [(productOfSeq matrix.[i, j .. (j+3)]); maxProd;]
    maxProd

let maxProductOfCols =
    let mutable maxProd = 0
    for i = 0 to 16 do
        for j = 0 to 19 do
            maxProd <- List.max [(productOfSeq matrix.[i..(i+3), j]); maxProd;]
    maxProd

let maxProductOfLeftDiagonal =
    let mutable maxProd = 0
    for i = 0 to 16 do
        for j = 0 to 16 do
            let diagonal = [| for k in 0 .. 3 -> matrix.[i+k, j+k] |]
            maxProd <- List.max [(productOfSeq diagonal); maxProd;]
    maxProd

let maxProductOfRightDiagonal =
    let mutable maxProd = 0
    for i = 0 to 16 do
        for j = 19 downto 3 do
            let diagonal = [| for k in 0 .. 3 -> matrix.[i+k, j-k] |]
            maxProd <- List.max [(productOfSeq diagonal); maxProd;]
    maxProd

printfn "%A" (List.max [maxProductOfRows; maxProductOfCols; maxProductOfLeftDiagonal; maxProductOfRightDiagonal])

