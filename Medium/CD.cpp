#include <iostream>
#include <cstring>
using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; i++)
const int MAX = 1000000000 / 32;
int F[MAX];

void set_bit(int index) {
    F[index / 32] |= (1 << (index % 32));
}

bool get_bit(int index) {
    return (F[index / 32] >> (index % 32)) & 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, JACK, JILL, ans;
    while(1) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        else {
            ans = 0;
            memset(F, 0, sizeof(F));
            rep(i, 1, n) {
                cin >> JACK; set_bit(JACK - 1);
            }
            rep(i, 1, m) {
                cin >> JILL; if (get_bit(JILL - 1)) ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}