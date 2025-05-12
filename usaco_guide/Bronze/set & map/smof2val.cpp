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
  map<int,int> mp;
  vector<int> arr(n+1,0);
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    mp[arr[i]] = i;
  }
  for(int i = 1; i <= n; i++){
     if(mp[k-arr[i]] != i && mp[k-arr[i]] > 0) {
        cout << mp[k-arr[i]] << " " << i;
        return;
     }
  }
  cout << "IMPOSSIBLE" << "\n";
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
