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
 // Its 0-1 Knapsack Problem 

int knapsackRecursive(vpi &items, int currentIndex, int remainingWeight, vector<vi> &memo) {
    // Base Case:
    if (currentIndex < 0 || remainingWeight <= 0) return 0;

    // Check if the result is already memoized
    if (memo[currentIndex][remainingWeight] != -1) return memo[currentIndex][remainingWeight];

    // Calculate the value when including the current item
    int includeCurrent = 0;
    if (items[currentIndex].first <= remainingWeight) {
        includeCurrent = items[currentIndex].second + knapsackRecursive(items, currentIndex - 1, remainingWeight - items[currentIndex].first, memo);
    }

    // Calculate the value when excluding the current item
    int excludeCurrent = knapsackRecursive(items, currentIndex - 1, remainingWeight, memo);

    // Choose the maximum between the two options
    memo[currentIndex][remainingWeight] = max(includeCurrent, excludeCurrent);

    return memo[currentIndex][remainingWeight];
}


int knapsackIterative(vpi &items, int capacity) {
    int n = items.size();
    vector<vi> dp(n, vi(capacity + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            int includeCurrent = 0;
            if (items[i].first <= w) {
                includeCurrent = items[i].second + (i > 0 ? dp[i - 1][w - items[i].first] : 0);
            }

            int excludeCurrent = i > 0 ? dp[i - 1][w] : 0;

            dp[i][w] = max(includeCurrent, excludeCurrent);
        }
    }

    return dp[n - 1][capacity];
}

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vpi items(n);

    for (int i = 0; i < n; i++) {
        cin >> items[i].first;  // Weight of item
    }

    for (int i = 0; i < n; i++) {
        cin >> items[i].second; // Value of item
    }

    // Recursive Approach
    // vector<vi> memo(n, vi(capacity + 1, -1));
    // int recursiveResult = knapsackRecursive(items, n - 1, capacity, memo);
    // cout << "Recursive Result: " << recursiveResult << endl;

    // Iterative Approach
    int iterativeResult = knapsackIterative(items, capacity);
    cout << iterativeResult << endl;

    return 0;
}