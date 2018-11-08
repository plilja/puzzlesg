package main

import (
    "fmt"
)

const HALF = 250 * 250 / 4.0

func main() {
    var x1, y1, x2, y2 float64
    fmt.Scanf("%f %f", &x1, &y1)
    if x1 == 0 {
        if y1 <= 125 {
            x2 = 2 * HALF / (250 - y1);
            y2 = -x2 + 250
        } else {
            x2 = 2 * HALF / y1;
            y2 = 0
        }
    } else if y1 == 0 {
        if x1 <= 125 {
            y2 = 2 * HALF / (250 - x1);
            x2 = 250 - y2
        } else {
            y2 = 2 * HALF / x1;
            x2 = 0
        }
    } else if x1 < 125 {
        x2 = 250 - 2 * HALF / y1
        y2 = 0
    } else {
        x2 = 0
        y2 = 250 - 2 * HALF / x1
    }
    fmt.Printf("%.2f %.2f\n", x2, y2)
}
