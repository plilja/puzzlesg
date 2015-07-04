package main

import "fmt"

func set(arr []int, y int, x int, cols int, v int) {
	arr[y*cols+x] = v
}

func get(arr []int, y int, x int, cols int) int {
	return arr[y*cols+x]
}

type Emp struct {
	name string
	x1   int
	y1   int
	x2   int
	y2   int
}

func main() {
	for true {
		var w, h, n int
		r, _ := fmt.Scanf("%d %d", &w, &h)
		if r == 0 {
			break
		}
		fmt.Scanf("%d", &n)
		floor := make([]int, w*h)

		for i := 0; i < h; i++ {
			for j := 0; j < w; j++ {
				set(floor, i, j, w, 0)
			}
		}

		total := w * h
		unallocated := total
		contested := 0

		var emps []Emp
		for k := 0; k < n; k++ {
			var name string
			var x1, y1, x2, y2 int
			fmt.Scanf("%s %d %d %d %d", &name, &x1, &y1, &x2, &y2)
			for i := y1; i < y2; i++ {
				for j := x1; j < x2; j++ {
					c := get(floor, i, j, w)
					if c == 0 {
						unallocated -= 1
					} else if c == 1 {
						contested += 1
					}
					set(floor, i, j, w, c+1)
				}
			}
			emps = append(emps, Emp{name: name, x1: x1, y1: y1, x2: x2, y2: y2})
		}
		fmt.Printf("Total %d\n", total)
		fmt.Printf("Unallocated %d\n", unallocated)
		fmt.Printf("Contested %d\n", contested)
		for i := 0; i < n; i++ {
			e := emps[i]
			g := 0
			for i := e.y1; i < e.y2; i++ {
				for j := e.x1; j < e.x2; j++ {
					c := get(floor, i, j, w)
					if c <= 1 {
						g += 1
					}
				}
			}
			fmt.Printf("%s %d\n", e.name, g)

		}
		fmt.Printf("\n")
	}

}
