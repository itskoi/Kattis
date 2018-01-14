#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const ll MOD = (1ll << 31ll) - 1;
#define rep(i, a, b) for (int i = a; i <= b; i++)

int n;
ll F[1010][1010];
bool grid[1010][1010];

void Input() {
    cin >> n;
    string s;
    rep(i, 1, n) {
        cin >> s; s = " " + s;
        rep(j, 1, n) if (s[j] == '.') grid[i][j] = true; else grid[i][j] = false;
    }
}

bool bfs() {
    bool visit[1010][1010]; memset(visit, 0, sizeof visit);
    queue<pii> Q; Q.push(pii(1,1)); visit[1][1] = true;
    const int foot[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    while(!Q.empty()) {
        pii tmp = Q.front(); Q.pop();
        int x = tmp.first, y = tmp.second;
        if (x == n && y == n) return true;
        rep(i, 0, 3) {
            int u = x + foot[i][0], v = y + foot[i][1];
            if (u > n || u < 1 || v < 1 || v > n) continue;
            if (visit[u][v] || !grid[u][v]) continue;
            visit[u][v] = true;
            Q.push(pii(u, v));
        }
    }
    return false;
}

void Compute() {
    F[1][1] = 1;
    rep(i, 1, n) {
        rep(j, 1, n) {
            if (i != 1 || j != 1) {
                if (grid[i][j]) F[i][j] = (F[i - 1][j] + F[i][j - 1]) % MOD;
                else F[i][j] = 0;
            }
        }
    }
    if (F[n][n]) {
        cout << F[n][n]; return;
    } else if (bfs()) {
        cout << "THE GAME IS A LIE"; return;
    }
    cout << "INCONCEIVABLE";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("test.inp", "r", stdin);
    Input();
    Compute();
    return 0;
}