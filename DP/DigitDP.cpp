// Q: How many numbers x in range 1 <= [a, b] <= 1e18 have digit d occur exactly k times?

#include <bits/stdc++.h>
using namespace std;

// Current position in sequence, # of times d has been used, smaller or equal to b
int d, k;
long long dp[20][20][2];
vector<int> digits;

void findDigitsInNumber(long long N) {
    digits.clear();

    while (N > 0) {
        digits.push_back(N % 10);
        N /= 10;
    }
    
    reverse(digits.begin(), digits.end());
}

// Constructs valid numbers with the restriction of <= N and digit d occuring exactly k times
long long recur(int pos, int cnt, int withinBounds) {
    if (dp[pos][cnt][withinBounds] != -1) return dp[pos][cnt][withinBounds];
    if (cnt > k) return 0LL;
    
    if (pos == digits.size()) {
        return 1LL * (cnt == k);
    }
    
    long long ret = 0;
    int bound = withinBounds ? 9 : digits[pos];
    
    for (int cur_digit = 0; cur_digit <= bound; cur_digit++) {
        if (cur_digit == d) {
            if (cnt == k) continue;
            ret += (cur_digit < bound) ? recur(pos + 1, cnt + 1, 1) : recur(pos + 1, cnt + 1, withinBounds);
        } else {
            ret += (cur_digit < bound) ? recur(pos + 1, cnt, 1) : recur(pos + 1, cnt, withinBounds);
        }
    }
    
    return dp[pos][cnt][withinBounds] = ret;
}

// Calculates the number of valid x from 0 to N
long long solve(long long N) {
    memset(dp, -1, sizeof(dp));
    findDigitsInNumber(N);
    return recur(0, 0, 0);
}

// Note: possible to solve w/ single recursion by including lower bound restriction of a when calculating the dp states
int main() {
    long long a, b;
    cin >> a >> b >> d >> k;
    
    long long ans = solve(b) - solve(a - 1);
    
    cout << ans << endl;
    return 0;
}
