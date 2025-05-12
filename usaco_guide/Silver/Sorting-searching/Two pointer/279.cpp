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
    int n,k;
    cin >> n >> k;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    ll ans = 0, cur = 0, time = 0, j = 0;
    for(int i = 1; i <= n; i++){
        if(time + arr[i] <= k){
            if(cur == 0) j = i;
            time += arr[i];
            cur++;
            ans = max(ans,cur);
        }
        else {
            while(time + arr[i] > k){
                if(cur == 0) break;
                cur--;
                time-=arr[j];
                j++;
            }
            if(time + arr[i] <= k){
                cur++;
                time += arr[i];
            }
        }
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