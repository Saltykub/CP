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
   ll n, ans = INT_MAX;
   cin >> n;
   n*=2;
   vector<int> arr(n);
   for(int i = 0; i < n; i++) cin >> arr[i];
   for(int i = 0; i < n; i++){
     for(int j = i+1; j < n; j++){
        vector<int> v;
        for(int k = 0; k < n; k++){
            if(k == i || k == j) continue;
            v.pb(arr[k]);
        }
        sort(v.begin(),v.end());
        ll cnt = 0;
        for(int k = 0; k < v.size(); k+=2){
            cnt += v[k+1]-v[k];
        }
        //cout << i << " " << j << " " << cnt << "\n";
        ans = min(ans,cnt);
     }
   }
   cout << ans;
    
}
int main(){   
   // ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }
 
}
