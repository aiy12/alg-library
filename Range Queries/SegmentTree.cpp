#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
 
const int MAXN = 5e5 + 10;
const int MOD = 1e9 + 7;

int N;
int seg[4 * MAXN];

void init(int arr[], int node, int left, int right) {
    if (left == right) {
        seg[node] = arr[left];
    } else {
        int mid = (left + right) / 2;
        init(arr, 2*node, left, mid);
        init(arr, 2*node+1, mid+1, right);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

void upd(int index, int delta, int left, int right, int node) {
    if (left == right) {
        seg[node] += delta;
    } else {
        int mid = (left + right) / 2;
        if (index <= mid)
            upd(index, delta, left, mid, 2*node);
        else
            upd(index, delta, mid+1, right, 2*node+1);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

int query(int node, int left, int right, int start, int end) {
    if (start > end) return 0;
    if (right < start || end < left) return 0;
    if (start <= left && right <= end) return seg[node];
    int mid = (left + right) / 2;
    return query(2*node, left, mid, start, end) + query(2*node+1, mid+1, right, start, end);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int arr[N=10] = {1,2,3,4,5,6,7,8,9,10};
    init(arr, 1, 0, N-1); // root of segtree is node 1
    cout << query(1, 0, N-1, 0, 4) << endl;
    upd(3, 1, 0, N-1, 1);
    cout << query(1, 0, N-1, 0, 4) << endl;

    return 0;
}
