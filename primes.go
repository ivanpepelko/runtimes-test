package main

import (
	"time"
	"fmt"
	"os"
	"runtime"
)

const maxDuration = 20 * time.Second
const primesPerRow = 10

// some assumptions: we know the first two prime numbers, 2 and 3, and we start from there
func main() {
	// used for output formatting
	newline := 0
	// primes container, start with 2
	primes := []int{2}
	// mark the start time, execution will end in predefined time
	start := time.Now()

	for i := 3; ; i++ {
		isPrime := true
		for _, p := range primes {
			// if i is divisible by any previous prime, throw it away
			if i%p == 0 {
				isPrime = false
				break
			}
		}

		if !isPrime {
			continue
		}

		primes = append(primes, i)
		fmt.Printf("%d, ", i)
		newline = (newline + 1) % primesPerRow
		if newline == 0 {
			fmt.Println()
		}

		if time.Now().Sub(start) > maxDuration {
			fmt.Printf("found %d primes\n", len(primes))
			fmt.Printf("version: %s\n", runtime.Version())
			os.Exit(0)
		}
	}
}
