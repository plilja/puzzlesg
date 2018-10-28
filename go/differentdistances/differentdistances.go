package main

import (
    "fmt"
    "math"
)

func main() {
    for true {
        var x1, y1, x2, y2, p float64
        fmt.Scanf("%f", &x1)
        if (x1 == 0.0) {
            break
        }
        fmt.Scanf("%f %f %f %f", &y1, &x2, &y2, &p)
        var ans = math.Pow(
            math.Pow(math.Abs(x1 - x2), p) +
            math.Pow(math.Abs(y1 - y2), p),
            1 / p)
        fmt.Printf("%.10f\n", ans)
    }
}
