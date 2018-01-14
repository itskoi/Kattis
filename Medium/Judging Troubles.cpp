#include <iostream>
#include <map>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; i++)
int n, ans;
map<string, int> ds;

int main() {
	cin >> n;
	rep(i, 1, n) {
		string s; cin >> s;
		ds[s]++;
	}
	rep(i, 1, n) {
		string s; cin >> s;
		if (ds[s] > 0) {
			ds[s]--;
			ans++;
		}
	}
	cout << ans;
	return 0;
}