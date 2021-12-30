#include<bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
    return '"' + s + '"';
}
 
string to_string(const char* s) {
    return to_string((string) s);
}
 
string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(char ch) {
    string s = "'";
    s += ch;
    s += "'";
    return s;
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

string to_string(vector<char> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)

#define ll long long
#define ull unsigned long long
#define ld long double

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(s) (int)s.size()
#define bs(x) (bitset<32>(x)).to_string()
#define bs64(x) (bitset<64>(x)).to_string()
#define ubs64(x) (bitset<65>(x)).to_string()
#define bit(x) __builtin_popcount(x)
#define bit64(x) __builtin_popcountll(x)
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define forn(i, n) for(int i = 0; i < int(n); ++i)

typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pair<ll, ll>> plll;

const double PI = 3.14159265359;
const int mod = 1e9 + 7;
const int inf = 2e9;
const ll inf64 = 2e18;
const int N = 2e5 + 14;

vector<ll> g[100000LL];

int main()
{
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<ll> a(1LL << n);
	for (ll i = 0LL; i < (1LL << n); ++i) {
		cin >> a[i];
	}

	for (ll i = 0LL; i < (1LL << n); ++i) {
		for (ll j = i + 1LL; j < (1LL << n); ++j) {
	        ll x = (i ^ j);
			if ((x & (x - 1LL)) == 0LL) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}

    int N = 1LL << n;
    int i = 0;
    while (!is_sorted(all(a)))
    {
        if (i + 1 < N) 
        {
            
        }
    }
        
    
    
}

/*
2
3 2 10 4

1
10 100

*/

