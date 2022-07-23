#include <iostream>
#include <map>
using namespace std;
const int MAXN = 2e5 + 5;
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		cout << i + 1 << '\n';
	}
	int cur = N - 1;
	map<int, int> mp;
	for(int i = N - 1; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		if(mp.count(u)) {
			cur += mp[u] - u;
			mp[u] = max(v, mp[u]);
		} else mp[u] = v;
		for(auto it = mp.upper_bound(u); it != mp.upper_bound(v); it = next(it)) {
			mp[u] = max(mp[u], it -> second); 
			mp.erase(it);
			cur += it -> second - it -> first;
		}
		cur -= mp[u] - u;
		cout << cur << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
