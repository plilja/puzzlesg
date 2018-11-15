package main

import (
    "fmt"
)

func main() {
    var t int
    fmt.Scanf("%d", &t)
    for i := 0; i < t; i++ {
        var s string
        checksum := 0
        fmt.Scanf("%s", &s)
        for i := len(s) - 1; i >= 0; i-- {
            d := int(s[i]) - int('0')
            if (len(s) - i) % 2 == 0 {
                tmp := 2 * d
                checksum += tmp % 10
                checksum += tmp / 10
            } else {
                checksum += d
            }
        }
        if checksum % 10 == 0 {
            fmt.Printf("PASS\n")
        } else {
            fmt.Printf("FAIL\n")
        }
    }
}
