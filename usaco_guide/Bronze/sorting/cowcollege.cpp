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
  
   ll n,ans = 0,anstut = 0;
   cin >> n;
   vector<ll> arr(n);
   for(int i = 0; i < n; i++) cin >> arr[i];
   sort(arr.begin(),arr.end(),greater<int>());
   for(int i = 0; i < n; i++){
        if(arr[i]*(i+1) >= ans){
            ans = arr[i]*(i+1);
            anstut = arr[i];
        }
   }
   cout << ans << " " << anstut;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
   
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }
 
}
