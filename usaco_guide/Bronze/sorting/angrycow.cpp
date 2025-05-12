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
   freopen("angry.in", "r", stdin);
   int ans = 0,n;
   cin >> n;
   vector<int> arr(n);
   for(int i = 0; i < n; i++) cin >> arr[i];
   sort(arr.begin(),arr.end());
   for(int i = 0; i < n; i++){
        
   }

   freopen("angry.out", "w", stdout);
   cout << ans;
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
