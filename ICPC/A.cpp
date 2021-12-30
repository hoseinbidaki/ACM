#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back 
#define eb emplace_back
#define mp make_pair

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(s) (int)s.size()
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define forn(i, n) for(int i = 0; i < int(n); ++i)

int n, m;
vector <string> s;
vector<vector<pii>> store;
int x, y;
int ans = -1;

void go(int a, int b, vector<pii> vec) 
{
    if (a >= n || b >= m) return;
    if (a < 0 || b < 0) return;
    if (s[a][b] != '.') return;
    if (a == x && b == y) {
        store.pb(vec);
        return;
    }
    if (a < x) 
    {
        vector<pii> hp = vec; hp.push_back({a+1, b});
        go(a + 1, b, hp);
    }
    else
    {
        vector<pii> hp = vec; hp.push_back({a-1, b});
        go(a - 1, b, hp);
    }
    if (b < y) 
    {
        vector<pii> hp = vec; hp.push_back({a, b + 1});
        go(a, b + 1, hp);
    }
    else 
    {
        vector<pii> hp = vec; hp.push_back({a, b - 1});
        go(a, b - 1, hp);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int stars = 0;
    int fa, fb;
    forn(i, n) 
    {
        string tt; cin >> tt;
        stars += count(all(tt), '*');
        s.pb(tt);
        forn(j, m) {
            if (s[i][j] == 'S') fa = i, fb = j;
            if (s[i][j] == 'E') x = i, y = j;
        }
    }
    if (stars == 0) {
        cout << "safe";
        return 0;
    }
    vector<pii> nu;
    go(fa, fb, nu);
    for (auto it : store) {
        for (auto k : it) cout << "(" << k.first << ", " << k.second << ") ";
        cout << "\n";
    }
}

/*
4 5
.*#..
.*..E
..##.
S....

----- 2


6 8
.......E
........
........
.....**.
........
S.......

------3

3 3
S..
...
..E

------- safe
*/
