#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
void solve (){
   int n, k;
   cin >> n >> k;
   vector<int> arr(n);
   for(int i = 0; i < n; i++) cin >> arr[i];
   sort(arr.rbegin(),arr.rend());
   for(int i = 1; i < n; i++){
      if(i%2 && k!=0){
          int add = min(k,arr[i-1]-arr[i]);
          arr[i] += add;
          k-=add;
      }
   }
   int ans = 0;
   for(int i = 0; i < n; i++){
    if(i%2) ans -= arr[i];
    else ans += arr[i];
   }
   cout << ans << "\n";
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