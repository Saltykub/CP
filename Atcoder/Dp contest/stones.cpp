#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
int dp[N]; // dp[i] = 0 means the first player loss at ith and dp[i] = 1 means the player won at ith
void solve (){
    int n,k;
    cin >> k >> n;
    vector<int> arr(k,0);
    for(int i = 0; i < k; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            if(i-arr[j]>=0) dp[i] |= (~dp[i-arr[j]]);
        }
    }
    cout << (dp[n] ? "First" : "Second");
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}