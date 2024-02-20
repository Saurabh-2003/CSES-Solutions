#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vpi = vector<pair<int, int>>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mod 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); 
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
 
 // Recursive code :

ll countMatchingArrays(vi &arr, int ind, int n, int m, vvi &dp) {
    // Base Case: All elements checked, one valid array found
    if (ind == n) return 1;

    // If the result is already calculated, return it
    if (dp[ind][arr[ind - 1]] != -1) return dp[ind][arr[ind - 1]];

    // Initialize the count of matching arrays
    ll count = 0;

    // If the current element is unknown (0), try all possible values
    if (arr[ind] == 0) {
        // Try all possible values for arr[ind]
        for (int val = max(1, arr[ind - 1] - 1); val <= min(m, arr[ind - 1] + 1); val++) {
            arr[ind] = val;
            count = (count + countMatchingArrays(arr, ind + 1, n, m, dp)) % mod;
            arr[ind] = 0; // Backtrack for the next iteration
        }
    } else if (arr[ind] >= max(1, arr[ind - 1] - 1) && arr[ind] <= min(m, arr[ind - 1] + 1))
        // If the current element is known, proceed to the next element
        count = (count + countMatchingArrays(arr, ind + 1, n, m, dp)) % mod;

    // Store the result in the dp array and return the count
    dp[ind][arr[ind - 1]] = count;
    return count;
}

int main() {
    SPEED;

    int n, m;
    cin >> n >> m;
    vi arr(n);

    // Input the array elements
    for (auto &elem : arr) cin >> elem;

    ll ans = 0;

    vvi dp(n, vi(m + 1, -1)); // DP array to store intermediate results

    if (arr[0] == 0) {
        // If the first element is unknown, try all possible values
        for (int val = 1; val <= m; val++) {
            arr[0] = val;
            ans = (ans + countMatchingArrays(arr, 1, n, m, dp)) % mod;
            arr[0] = 0; // Backtrack for the next iteration
        }
        cout << ans << endl; // Output the total count of matching arrays
    } else {
        // If the first element is known, proceed with the helper function
        cout << countMatchingArrays(arr, 1, n, m, dp) % mod << endl;
    }


    // Iterative Approach  : 
    
    return 0;
}