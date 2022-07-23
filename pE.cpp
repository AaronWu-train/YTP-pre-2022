#include <iostream>
using namespace std;
typedef long long int ll;
const int MAXN = 5e5 + 5, MOD = 1e9 + 7;
int a[MAXN], BIT[MAXN];
int mabs(ll a) { return (a % MOD + MOD) % MOD; }
int madd(int a, int b) { return mabs(a + b); }
int mmin(int a, int b) { return mabs(a - b); }
int query(int k) {
	int ret = 0;
	for(; k > 0; k -= k & -k) ret = madd(ret, BIT[k]);
	return ret;
}
void modify(int k, int val) {
	for(; k < MAXN; k += k & -k) BIT[k] = madd(BIT[k], val);			
}
void solve() {
	int N;
	cin >> N;
	int sum = 0;
	for(int i = 1; i <= N; ++i) {
		cin >> a[i];
		int cnt = 1;
		cnt = madd(cnt, mmin(query(a[i] + 2), query(a[i] - 3)));
		modify(a[i], cnt);
		sum = madd(sum, cnt);
	}
	cout << sum << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
