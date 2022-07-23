#include <iostream>
#include <vector>
using namespace std;
void solve() {
	int N;
	cin >> N;
	vector<int> ans;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			ans.push_back(i);
			ans.push_back(j);
		}
	}
	ans.push_back(0);
	cout << ans.size() << '\n';
	for(int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i] << " \n"[i == (int)ans.size() - 1];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
