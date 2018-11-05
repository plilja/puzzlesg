package main

import (
    "fmt"
)

func main() {
    var inp string
    fmt.Scanf("%s", &inp)
    suits := map[byte]int{
        'P' : 13,
        'K' : 13,
        'H' : 13,
        'T' : 13,
    }
    seen := make(map[string]bool)
    greska := false
    for i := 0; i < len(inp); i+=3 {
        card := string(inp[i]) + string(inp[i + 1]) + string(inp[i + 2])
        if (seen[card]) {
            greska = true
            break
        } else {
            suits[inp[i]] -= 1
            seen[card] = true
        }
    }
    if (greska) {
        fmt.Printf("GRESKA\n")
    } else {
        fmt.Printf("%d %d %d %d\n", suits['P'], suits['K'], suits['H'], suits['T'])
    }
}
