// some assumptions: we know the first two prime numbers, 2 and 3, and we start from there
'use strict';

const EOL = require('os').EOL;

const MAX_DURATION = 20000; // milliseconds
const PRIMES_PER_ROW = 10;

// used for output formatting
let newline = 0;
// primes container, start with 2
let primes = [2];
// mark the start time, execution will end in predefined time
let start = Date.now();

for (let i = 3; ; i++) {
  let isPrime = true;
  for (let prime of primes) {
    // if i is divisible by any previous prime, throw it away
    if (i % prime === 0) {
      isPrime = false;
      break;
    }
  }

  if (!isPrime) {
    continue;
  }

  primes.push(i);
  process.stdout.write(`${i}, `);
  newline = ++newline % PRIMES_PER_ROW;
  if (newline === 0) {
    process.stdout.write(EOL);
  }

  if (Date.now() - start > MAX_DURATION) {
    process.stdout.write(`found ${primes.length} primes ${EOL}`);
    process.stdout.write(`version: ${process.version}${EOL}`);
    process.exit(0);
  }
}
