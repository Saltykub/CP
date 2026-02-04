#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    string x,y;
    cin >> x >> y;
    int n = sz(x);
    vll dp1(n+1,0), dp0(n+1,0); // min op that make bit from 1 to i correct
    dp1[0] = INT_MAX;
    for(int i = 0; i < n; i++){
        int idx = i+1;
        if(y[i] == '0'){
            if(x[i] == '0'){
                dp0[idx] = min(dp0[idx-1],dp1[idx-1]+1);
                dp1[idx] = 1 + min(dp1[idx-1],dp0[idx-1]+1);
            }
            if(x[i] == '1'){
                dp0[idx] = min(dp1[idx-1],dp0[idx-1]+1);
                dp1[idx] = 1 + min(dp1[idx-1]+1,dp0[idx-1]);
            }
        }
        else {
            if(x[i] == '0'){
                dp0[idx] = 1+min(dp0[idx-1],dp1[idx-1]+1);
                dp1[idx] = min(dp1[idx-1],dp0[idx-1]+1);
            }
            if(x[i] == '1'){
                dp0[idx] = 1 + min(dp1[idx-1],dp0[idx-1]+1);
                dp1[idx] = min(dp1[idx-1]+1,dp0[idx-1]);
            }
        }
    }
    cout << min(dp0[n],dp1[n]) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}