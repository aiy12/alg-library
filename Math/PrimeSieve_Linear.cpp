int is_prime[MAXK];
vi primes;

void sieve(int MX) {
    for (int i = 2; i <= MX; i++) {
        if (is_prime[i] == 0) {
            is_prime[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < sz(primes) && primes[j] <= is_prime[i] && i * primes[j] <= MX; j++) {
            is_prime[i * primes[j]] = primes[j];
        }
    }
}

// note: somewhat costly on memory to reduce loglogN factor
