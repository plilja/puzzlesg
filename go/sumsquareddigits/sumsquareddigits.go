package main

import (
    "fmt"
)

func main() {
    var p int
    fmt.Scanf("%d", &p)
    for i := 0; i < p; i++ {
        var k, b, n, res int
        fmt.Scanf("%d %d %d", &k, &b, &n)
        res = 0
        for n > 0 {
            var digit = n % b
            res += digit * digit
            n /= b
        }
        fmt.Printf("%d %d\n", k, res)
    }
}
