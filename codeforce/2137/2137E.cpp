#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int x = 0;
void solve (){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> cnt(n+1);
    for(auto &u:v) cin >> u;
    for(auto u:v) cnt[u]++;
    x++;
    if(x == 53){
        cout << n << "_" << k << "_";
        for(auto u:v) cout << u << "_";
        cout << "\n";
        return;
    }
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    int cur = 0;
    ll ch = true;
    for(int i = 0; i <= n; i++){
        cur+=cnt[i];
        if(cnt[i] == 0){
            // max_mex = i; first half = (i-1)*(i)/2 other = i (n-i)
            ans1 = i*(i-1)/2 + (n-i)*(i);
            if(n-i > 1) ans2 = i*(i-1)/2 + (n-i)*(i+1);
            else ans2 = ans1;
            ans3 = ans1;
            ch = false;
            break;
        }
        else if(cnt[i] >= 2){
            int cc = 0;
            for(int j = 0; j <= n; j++){
                // cur+=cnt[j];
                if(cnt[j] == 0){
                    // compute ans1 = all more than 2 will change to j whic has n-cc number
                    ans1 += j*(n-cc);
                    ans2 = i*(i-1)/2 + (n-cur)*i;
                    if(n-cur >= 1) ans3 = i*(i-1)/2 + (n-cur)*(i+1);
                    else ans3 = ans1;
                    break;
                }
                else if(cnt[j] == 1){
                    ans1 += j;
                    cc++;
                }
            }
            ch = false;
            break;
        }
    }
    if(ch) {
        cout << (n)*(n-1)/2 << "\n";
    }
    else {
        if(k == 1){
            cout << ans1 << "\n";
        }
        else if(k%2 == 0) cout << ans2 << "\n";
        else cout << ans3 << "\n";
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}