#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int t(int x){
    cout << "throw " << x << endl;
    int ret;
    cin >> ret;
    return ret;
}
void s(int x){
    cout << "swap " << x << endl;
}
void solve (){
    int n;
    cin >> n;
    vector<int> ans(n+10,0);
    vector<int> dp(n+2,0);
    dp[n-1] = t(n-1);
    if(dp[n-1] == 2) ans[n-1] = 1;
    else ans[n-1] = 2;
    s(n-1);
    dp[n-1] = t(n-1);
    if(dp[n-1] == 2) ans[n] = 1;
    else ans[n] = 2;
    for(int i = n-2; i >= 1; i-=2){
        int t1 = t(i);
        int t2 = t(i-1);
        if(ans[i+1] == ans[i+2]){
            if(ans[i+1] == 1){

            }
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}