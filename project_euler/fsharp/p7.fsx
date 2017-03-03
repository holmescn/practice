let notPrime x primes = List.exists (fun p -> x % p = 0) primes
let rec f n primes cnt =
    if (notPrime n primes) then f (n + 1) primes cnt
    else
        if cnt + 1 = 10001 then n
        else f (n + 1) (n::primes) (cnt + 1)

printfn "%A" (f 3 [2] 1)
