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
   freopen("cowqueue.in", "r", stdin);
   ll n,ans = 0;
   cin >> n;
   vector<pii> arr(n);
   for(int i = 0; i < n; i++) cin >> arr[i].st >> arr[i].nd;
   sort(arr.begin(),arr.end());
   int curtime = 0;
   for(int i = 0; i < n; i++){
        //cout << arr[i].st << "";
        if(curtime < arr[i].st) curtime = arr[i].st + arr[i].nd;
        else curtime += arr[i].nd;
   }
   freopen("cowqueue.out", "w", stdout);
   cout << curtime << "\n";
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
