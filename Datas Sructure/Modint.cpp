#include<bits/stdc++.h>
using namespace std;

struct ModInt
{
    const long long mod = int(1e9) + 7;
    long long val;
    
    ModInt(long long x){val = x >= 0 ? x % mod : x + (-x + mod - 1) / mod * mod;}
    ModInt() : val(0){}
   
    ModInt& operator+=(const ModInt& y){val = val + y.val - ((val + y.val) >= mod ? mod : 0); return *this;}
    ModInt& operator-=(const ModInt& y){val = val - y.val + (val - y.val < 0 ? mod : 0); return *this;}
    ModInt& operator*=(const ModInt& y){val = (val * y.val) % mod; return *this;}

    ModInt& operator=(const ModInt& y){val = y.val;return *this;}

    ModInt operator+(const ModInt& y) const{ModInt x = *this; return x += y;}
    ModInt operator-(const ModInt& y) const{ModInt x = *this; return x -= y;}
    ModInt operator*(const ModInt& y) const{ModInt x = *this; return x *= y;}

    friend ostream& operator<<(ostream& stream, const ModInt& x){
        stream << x.val;
        return stream;
    }

   friend istream& operator>>(istream& stream, ModInt& x){
        stream >> x.val;
        return stream;
    }
    ModInt& operator++(){val = (val + 1) % mod; return *this;}
    ModInt& operator--(){val = (val - 1 + mod) % mod; return *this;}

    bool operator==(const ModInt& y) const{return val == y.val;}
    bool operator!=(const ModInt& y) const{return val != y.val;}

    const long long& operator*() const{return val;}
    long long& operator*(){return val;}
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    ModInt *ar = new ModInt[1000001];
    for (int i = 1; i < 1000001; ++i) {
        if (i <= 2) {
            ar[i] = 1;
        }
        else {
            ar[i] = ar[i - 1] + ar[i - 2];
        }
    }

    int q;
    cin >> q;
    while (q --) {
        ModInt a, b, c;
        cin >> a >> b >> c;
        if (c == 1) {
            cout <<  a << "\n";
        }
        else if (c == 2) {
            cout << b << "\n";
        }
        else {
            --c;
            cout << a * ar[c.val - 1] + ar[c.val] * b << "\n";
        }
    }
    

}
