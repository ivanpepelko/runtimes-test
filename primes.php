<?php

// some assumptions: we know the first two prime numbers, 2 and 3, and we start from there

const MAX_DURATION = 20; // seconds
const PRIMES_PER_ROW = 10;

// used for output formatting
$newline = 0;
// primes container, start with 2
$primes = [2];
// mark the start time, execution will end in predefined time
$start = microtime(true);

for ($i = 3; ; $i++) {
    foreach ($primes as $prime) {
        // if i is divisible by any previous prime, throw it away
        if ($i % $prime == 0) {
            continue 2;
        }
    }

    $primes[] = $i;
    printf('%d, ', $i);
    $newline = ++$newline % PRIMES_PER_ROW;
    if ($newline === 0) {
        echo PHP_EOL;
    }

    if ((microtime(true) - $start) > MAX_DURATION) {
        printf('found %d primes%s', count($primes), PHP_EOL);
        printf('version: %s%s', PHP_VERSION, PHP_EOL);
        exit(0);
    }
}
