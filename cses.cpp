#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> a, b, c, d;

ll digit_num(ll a) {
    ll count = 0;
    while (a > 0) {
        a /= 10;
        count++;
    }
    return count;
}

void findRange() {
    ll l = 1, r = 9;
    ll lp = 0, rp = 9;
    a.push_back(1), b.push_back(9), c.push_back(1);
    d.push_back(9);
    while (r <= 1e16) {
        l = r + 1;
        r = (l * 10 - 1);
        lp = rp + 1;
        rp = (r - l +1) * digit_num(l) + rp;
        a.push_back(l), b.push_back(r);
        c.push_back(lp), d.push_back(rp);
    }
}

int main() {
    findRange();
    int q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;
        if (k < 10) {
            cout << k << endl;
            continue;
        }
        ll l, r;
        ll i;
        for (i = 1; i < c.size(); i++) {
            // Check in What number of digits the current K falls 
            if (k >= c[i] && k <= d[i]) {
                l = a[i], r = b[i];
                // Use Binary search to find the number in which K falls
                while (l <= r) {
                    
                    ll mid = (l + r) / 2;
                    ll pos = ((mid - a[i]) * digit_num(a[i])) + c[i];
                    if (k < pos) {
                        r = mid - 1;
                    } else {
                        l = mid+1;
                    }
                }

                // Find the digit at current K
                ll pos = (r-a[i])*digit_num(a[i]) + c[i] + (digit_num(a[i]) - 1);
                ll ans = 0;
                while(r != 0){
                    ans = r%10;
                    if(pos == k){
                        cout<<to_string(ans)<<endl;
                        break;
                    }
                    --pos;
                    r = r/10;
                }

                break;
            }
        }

    }
    return 0;
}
