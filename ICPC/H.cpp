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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    vector <string> vec;
    forn(i, n) 
    {
        string tt; cin >> tt;
        vec.pb(tt);
    }
    forn(i, s)
    {
        string tt;
        cin >> tt;
        if (tt == "insert") 
        {
            string name; int pos;
            cin >> name >> pos;
            vec.insert(vec.begin() + pos, name);
        } 
        else if (tt == "depart") 
        {
            string name; cin >> name;
            auto f = find(vec.begin(), vec.end(), name);
            vec.erase(f);
        } 
        else 
        {
            string name; int pos;
            cin >> name >> pos;
            if (pos == 0) continue;
            auto f = find(vec.begin(), vec.end(), name);
            vec.erase(f);
            int idx = f - vec.begin();
            idx += pos;
            vec.insert(vec.begin() + idx, name);
        }
    }
    for (auto it : vec)
        cout << it << " ";
}
/*
3 15
m1 m2 f
insert m3 0
relocate m2 -2
relocate m1 -2
relocate m3 -2
relocate m2 -2
relocate m1 -2
relocate m3 -2
depart m2
relocate m1 1
relocate f 0
relocate m3 0
relocate f -1
relocate m3 -1
relocate m1 -2
relocate f -1
*/