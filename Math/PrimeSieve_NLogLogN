bool is_prime[MAXK];
vi primes;
 
void sieve(int MX) {
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = true;
    primes.push_back(2);
    for (int i = 3; i <= MX; i+=2) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        if (is_prime[i] && (ll) i * i <= MX) {
            for (ll j = (ll) i * i; j <= MX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
