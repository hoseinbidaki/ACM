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

const int N = 5e5 + 14;

vector<int> g[100000LL];
bool seen[100000LL];
vector <int> a(N);
vector <pii> ans;
int n;
vector<int> s;
void dfs(int v, vector<int> p, vector<int> ans,int par = -1)
{
    seen[v] = true;
    vector<pii> vc;
    for (int u : g[v]) {
        if (u == par) continue;
        vc.emplace_back(a[u], u);
    }
    if (sz(p) == (1LL << n)) {
        if (is_sorted(all(p))) {
            s = ans;
        }
            for (auto it : p) cout << it << " ";
            cout << "\n";
        return;
    }
    //sort(all(vc));
    for (auto it : vc) {
        vector<int> hp = p;
        hp.push_back(it.first);
        vector<int> h = ans;
        h.push_back(it.second);
        dfs(it.second, hp, h, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int N = 1LL << n;

    vector <int> b(N);
    int mn = 0;
    forn(i, N) {
        cin >> a[i];
        if (a[mn] > a[i]) mn = i;
    }
    forn(i, N) for (int j = i + 1 ; j < N; j++) {
        int x = (i ^ j);
        if ((x & (x - 1LL)) == 0LL) {
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    forn(i, N) {
        vector<int> q;
        q.push_back(a[i]);
        dfs(i, q, s);
    }
    cout << sz(s) << "\n";
    for (auto it : s) cout << it <<  "\n";
}

/*
2
1 4 2 3

2
3 2 10 4

1
10 100
*/