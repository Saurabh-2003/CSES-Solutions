#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
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
 
 //Recursive
    int helper(int i, int amount, vector<int> &coins, vector<vector<int>>&dp){
        if(amount == 0){
            return 1;
        }
        if(dp[i][amount] != -1)
            return dp[i][amount];
        int op1 = 0, op2 = 0;
        if(amount - coins[i] >= 0)
            op1 =  helper(i, amount - coins[i], coins, dp);
        if( i+1 < coins.size())
            op2 = helper(i+1, amount, coins, dp);

        return dp[i][amount] = op1 + op2;
    }


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vi coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vi dp(x + 1);
    dp[0] = 1;
    
    for (ll &coin : coins) {
        for (int weight = coin; weight <= x; weight++) {
            dp[weight] = (dp[weight] + dp[weight - coin])%mod;        }
    }

    cout << dp[x] << endl;
    return 0;
}