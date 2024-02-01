#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<long long>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mod 1000000007
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
 

// Recursive Approach : Main condition is when remainder is zero should be taken care
ll helper(ll n, vi& dp) {
    // Base Case:
    if (n < 0) return INT_MAX;
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    ll ans = INT_MAX;
    ll temp = n;

    while (temp ) {
        ll rem = temp % 10;
        temp = temp / 10;
        if(rem == 0) continue;
        ans = min(ans, 1 + helper(n - rem, dp));     
    }
    dp[n] = ans;
    return dp[n];
}

// Iterative approach
int main() {
    ll n;
    cin >> n;
    vi dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(ll i =1; i <= n; i++){
        ll temp = i;
        while(temp){
            ll rem =  temp%10;
            dp[i] = min(dp[i], 1+ dp[i-rem]);
            temp/=10;
        }
    }
    cout<<dp[n];
    return 0;
}