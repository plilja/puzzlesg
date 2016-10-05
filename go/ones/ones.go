package main

import "fmt"

func main() {
    var n int
    for {
        _, err := fmt.Scanf("%d\n", &n)
        if err != nil { break }
        if n == 0 {
            fmt.Printf("1\n")
            continue
        }
        var mult = 1 % n
        var digits = 1
        for mult != 0 {
            mult = (10 * mult + 1) % n
            digits++
        }
        fmt.Printf("%d\n", digits)
    }
}
