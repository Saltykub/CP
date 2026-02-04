#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
void solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    ll e = 0, o = 0, mxo = 0;
    for(auto x:arr) {
        if(x%2){
           o++;
           mxo = max(mxo,x);
        } 
        else e++;

    }
    if(e == 0 || o == 0) cout << 0;
    else {
      if(arr[n-1]%2) cout << e;
      else {
         for(int i = 0; i < n; i++){
            if(arr[i]%2 == 0) {
                if(arr[i] <= mxo){
                    mxo += arr[i];
                }
                else {
                    e++;
                    break;
                }
            }
         }
         cout << e;
      }
    }
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}