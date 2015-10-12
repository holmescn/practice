open System

Console.WriteLine("Hello, Fsharp")

[ "String1"
  "String2" ]
|> Seq.iter (printfn "%s")
