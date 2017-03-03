let isPrime x primes =
    let s =
        primes
        |> List.map (fun p -> if x % p = 0L then 1 else 0)
        |> List.reduce (fun acc x -> acc + x)
    if s > 0 then false else true

let rec f x n primes =
    if (isPrime n primes) then
        if x % n = 0L then
            if x = n then n
            else f (x / n) (n + 1L) (n :: primes)
        else f x (n + 1L) (n :: primes)
    else
        f x (n + 1L) primes

printfn "%A" (f 600851475143L 3L [2L])

