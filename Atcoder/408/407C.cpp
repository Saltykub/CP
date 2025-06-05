#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> qs(n+2,0);
    while(m--){
        int l, r;
        cin >> l >> r;
        qs[l]++;
        qs[r+1]--;
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++){
        qs[i] += qs[i-1];
        ans = min(ans,qs[i]);
    }
    cout << ans;
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}