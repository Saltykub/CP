#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    vector<int> gcd(n+1,0);
    vector<int> ans(n,0);
    int mx = 0, cur = 0, prev = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= sqrt(v[i]); j++){
            if(v[i]%j == 0){
                gcd[j]++;
                if(gcd[j] != i+1) mx = max(gcd[j],mx);
                else cur++, prev--;
                if(v[i]/j != j){
                    int idx = v[i]/j;
                    gcd[idx]++;
                    if(gcd[idx] != i+1) mx = max(gcd[idx],mx);
                    else cur++, prev--;
                }
            }
        }
        ans[i] = mx;
        if(prev > 0) ans[i] = i, mx = i;
        prev = cur;
        cur = 0;
    }
    for(auto u:ans) cout << u << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}