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
    int n,k;
    cin >> n >> k;
    vector<pii> v;
    for(int i = 0; i < n; i++){
        int l,r,re;
        cin >> l >> r >> re;
        v.pb({l,re});
    }
    sort(v.begin(),v.end(),[&](pii a, pii b){
        if(a.st == b.st){
            return a.nd > b.nd;
        }
        return a.st < b.st;
    });
    for(int i = 0; i < n; i++){
        //cout << v[i].st << v[i].nd << "\n";
        if(v[i].st <= k){
            if(v[i].nd > k){
                k = v[i].nd;
            }
        }
    }
    cout << k << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}