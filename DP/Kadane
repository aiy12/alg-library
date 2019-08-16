int arr[MAXN];

int Kadane() {
    int best = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += arr[i];
        if (cur < 0) cur = 0;
        best = max(best, cur);
    }
    return best;
}
