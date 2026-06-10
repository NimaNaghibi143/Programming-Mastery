package main

import (
	"bytes"
	"fmt"
)

const (
	NOTHING = 0
	WALL    = 1
	PLAYER  = 69
)

type game struct {
}

func (g *game) update() {

}

func (g *game) render() {

}

func main() {
	width := 20
	height := 20
	level := make([][]byte, height)

	for h := 0; h < height; h++ {
		for w := 0; w < width; w++ {
			level[h] = make([]byte, height)
		}
	}
	for h := 0; h < height; h++ {
		for w := 0; w < width; w++ {
			level[h][w] = WALL
		}
	}

	buf := new(bytes.Buffer)

	for h := 0; h < height; h++ {
		for w := 0; w < width; w++ {
			if level[h][w] == WALL {
				buf.WriteString("H")
			}
		}

		buf.WriteString("\n")
	}

	fmt.Printf(buf.String())
}
