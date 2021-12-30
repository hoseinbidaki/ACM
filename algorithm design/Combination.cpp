ll add(ll x, ll y) {
    x += y;
    if (x >= mod) return x - mod;
    return x;
}
ll sub(ll x, ll y) {
    x -= y;
    if (x < 0) return x + mod;
    return x;
}
ll mult(ll x, ll y) {
    return (x * y) % mod;
}
ll bin_pow(ll x, ll p) {
    if (p == 0) return 1;
    if (p & 1) return mult(x, bin_pow(x, p - 1));
    return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
    return bin_pow(x, mod - 2);
}
ll fact(ll a) {
    ll S = 1;
    for (ll I = 1 ; I <= a; I++)S = S *  I % mod;
    return S;
}
ll Combin(ll x, ll y) {
    return mult(fact(x), rev(mult(fact(sub(x, y)), fact(y))));
} 