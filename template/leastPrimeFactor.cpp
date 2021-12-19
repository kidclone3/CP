const int N = 5*1e6+5;

vi prime;
vi lpf(N, 2);

void sieve() {
    prime.assign(1,2);
    lpf[1] = -2;
    for(int i = 3; i <= N; i+=2) {
        if (lpf[i] == 2) prime.push_back(lpf[i] = i);
        for(int j = 0; j < (int) prime.size() && prime[j] <= lpf[i] && i * prime[j] <= N; ++j) {
            lpf[prime[j]*i] = prime[j];
        }
    }
}