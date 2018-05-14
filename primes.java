import java.util.ArrayList;
import java.util.List;

public class Primes {

    private static long MAX_DURATION = 20000; // milliseconds
    private static int PRIMES_PER_ROW = 10;

    public static void main(String[] args) {
        int newline = 0;
        List<Integer> primes = new ArrayList<>();
        primes.add(2);
        long start = System.currentTimeMillis();

        for (int i = 3; ; i++) {
            boolean isPrime = true;
            for (int prime : primes) {
                if (i % prime == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (!isPrime) {
                continue;
            }

            primes.add(i);
            System.out.printf("%d, ", i);
            newline = ++newline % PRIMES_PER_ROW;
            if (newline == 0) {
                System.out.println();
            }

            if (System.currentTimeMillis() - start > MAX_DURATION) {
                System.out.printf("found %d primes \n", primes.size());
                System.out.printf("version: %s\n", System.getProperty("java.version"));
                System.exit(0);
            }
        }
    }
}
