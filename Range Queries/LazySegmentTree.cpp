int N;
int seg[4 * MAXN];
int lazy[4 * MAXN];

void init(int arr[], int node, int left, int right) {
    if (left == right) {
        seg[node] = arr[left];
    } else {   
        int mid = (left + right) / 2;
        init(arr, 2 * node, left, mid);
        init(arr, 2 * node + 1, mid + 1, right);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
}

void prop(int left, int right, int node) {
    if (lazy[node] == 0) return;
    seg[node] += (right - left + 1) * lazy[node];
    if (left != right) {
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
    }
    lazy[node] = 0;
}

void upd(int node, int delta, int left, int right, int start, int end) {
    if (start > end || right < start || end < left) return;
    prop(left, right, node);
    if (start <= left && right <= end) {
        lazy[node] += delta;
        prop(left, right, node);
        return;
    }

    int mid = (left + right) / 2;
    upd(2 * node, delta, left, mid, start, end);
    upd(2 * node + 1, delta, mid + 1, right, start, end);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

int query(int node, int left, int right, int start, int end) {
    if (start > end || right < start || end < left) return 0;
    prop(left, right, node);
    if (start <= left && right <= end) return seg[node];
    int mid = (left + right) / 2;
    return query(2 * node, left, mid, start, end) + query(2 * node + 1, mid + 1, right, start, end);
}

int main() {
    int arr[N = 10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    init(arr, 1, 0, N - 1); // root of segtree is node 1
    cout << query(1, 0, N - 1, 0, 4) << endl;
    upd(1, -1, 0, N - 1, 1, 3);
    cout << query(1, 0, N - 1, 0, 4) << endl;
    return 0;
}
