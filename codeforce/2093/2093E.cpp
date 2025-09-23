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
    ll n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    ll l = 0, r = n+10;
    while(l < r){
        ll mid = (l+r+1)/2;
        int cnt = 0;
        vector<int> check(n,0);
        int mex = 0;
        for(int i = 0; i < n; i++){
            if(v[i] < mid && !check[v[i]]) mex++,check[v[i]] = 1;
            if(mex == mid){
                for(int j = 0; j < mex; j++){
                    check[j] = 0;
                }
                mex = 0;
                cnt++;
            }
        }
        if(cnt >= k) l = mid;
        else r = mid-1;
    }
    cout << l << "\n";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}