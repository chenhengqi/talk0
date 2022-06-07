package main

import (
	"fmt"
	"os"
)

//go:noinline
func hello(s string, ss string) {
	fmt.Println(s, ss)
}

func main() {
	hello(os.Args[1], os.Args[2])
}
