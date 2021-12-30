#include<bits/stdc++.h>
using namespace std; 
#define ll long long
bool isPrime(int n) { 
  if (n <= 1)  return false; 
  if (n <= 3)  return true; 
  if (n % 2 == 0 || n % 3 == 0) return false; 
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false; 
  }
  return true; 
}

vector<ll> getDivisors(ll n) {
  vector<ll> res;
  for (ll i = 1; i <= sqrt(n); i++) { 
    if (n % i == 0) { 
      if (n / i == i) {
        res.push_back(i);
      } else {
        res.push_back(i);
        res.push_back(n/i);
      }
    } 
  }
  return res; 
}

int primeCounter(vector<int> a) {
  int cnt = 0;
  for (auto el : a) {
    cnt += isPrime(el);
  }
  return cnt; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  long long  p, q;
  cin >> p >> q;
  vector<ll> s = getDivisors(p);
  for(auto it : s) cout << it << " ";
}