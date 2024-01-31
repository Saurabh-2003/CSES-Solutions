#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second

 
 
ll mod = 1e9 + 7;
// #################### Useful Functions ########################3
 
// Find Factorial :
void precomputeFactorials(ll N) {
	vector<ll> fact(N+1);fact[0] = 1;
    for (ll i = 1; i <= N; i++) {
     	fact[i] = (fact[i - 1] * i) % mod;}
}
// Eucleiden Algo
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a%b);}
// Extended Eucleiden Algo
ll gcdE(ll a, ll b, ll& x, ll& y) {
    if (b == 0) { x = 1;y = 0;return a;}
    ll x1, y1;ll d = gcdE(b, a % b, x1, y1);
    x = y1;y = x1 - y1 * (a / b);
    return d;
}
// Modular Multiplicative Inverse :
ll modInverse(ll a, ll m) {
    ll x, y;ll g = gcdE(a, m, x, y);
	if (g != 1) {return 0;}
	else {return (x+mod)%mod;}
}
// Binary Exponentiation  :
 
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
// ##################### Start Code From Here Noob  ########################
 

 
int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];
 
    ll dp[x + 1] = {0};
    dp[0] = 1;
 
    for (ll i = 1; i <= x; i++) {
        for (ll j = 0; j < n; j++) {
            if (arr[j] <= i) {
                dp[i] += dp[i - arr[j]];
                dp[i] %= mod;
            }
        }
    }
 
    cout << dp[x] << endl;
    return 0;
}