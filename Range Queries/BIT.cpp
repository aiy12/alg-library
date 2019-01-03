template<int sz> struct BIT {
	int tree[sz+10];
	init() {
		memset(tree, 0, sizeof(tree));
	}
	void upd(int k, int x) {
		++k;
		while(k < sz+10) {
			tree[k] += x;
			k += (k&-k);
		}
	}
	int query(int l, int r) {
		return sum(r) - sum(l-1);
	}
	int sum(int q) {
		++q;
		int res = 0;
		while(q >= 1) {
			res += tree[q];
			q -= (q&-q);
		}
		return res;
	}
};
