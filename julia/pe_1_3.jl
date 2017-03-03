# Problem 1
println("Problem 1:")
reduce(+, 0, filter(x -> x % 3 == 0 || x % 5 == 0, 1:999))

# Problem 2
# It seams that the problem is wrong.
# The Fib Seq starts with 1, 1, 2, 3, ...
println("Problem 2:")
a, b, s = 1, 1, 0
while a < 4000000
    if iseven(a)
        s += a
    end
    a, b = b, a+b
end
println(s)

# Problem 3
println("Problem 3:")
function  next_prime(primes)
    x = maximum(primes) + 1
    while true
        found_prime = true
        for prime in primes
            if x % prime == 0
                found_prime = false
                break
            end
        end

        if found_prime
            break
        end

        x = x + 1
    end
    return x
end

function p3()
    n = 600851475143
    primes = IntSet([2])
    prime = 2

    while n > 1.0
        if n % prime == 0
            n = n / prime
        else
            prime = next_prime(primes)
            union!(primes, [prime])
        end
    end
    println(prime)
end
@time p3()
