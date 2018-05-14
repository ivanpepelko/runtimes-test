using System;
using System.Collections.Generic;

namespace Primes {
    public static class Program {
        private const long MaxDuration = 20000; // milliseconds
        private const int PrimesPerRow = 10;

        public static void Main()
        {
            var newline = 0;
            var primes = new List<int> {2};
            var start = DateTime.Now;

            for (var i = 3;; i++) {
                var isPrime = true;
                foreach (var prime in primes) {
                    if (i % prime == 0) {
                        isPrime = false;
                        break;
                    }
                }

                if (!isPrime) continue;

                primes.Add(i);
                Console.Write($"{i}, ");
                newline = ++newline % PrimesPerRow;
                if (newline == 0) {
                    Console.WriteLine();
                }

                if (DateTime.Now.Subtract(start).TotalMilliseconds > MaxDuration) {
                    Console.WriteLine($"found {primes.Count} primes");
                    Console.WriteLine($"version: {Environment.Version}");
                    Environment.Exit(0);
                }
            }
        }
    }
}
