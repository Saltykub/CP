#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
const int N = 2e5+10;
void solve(){
   int n;
   cin >> n;
   vector<int> a;
   int ans = INT_MAX;
   for(int i = 2; i <= n; i++){
       cout << "? " << 1 << " "<< i << endl;
       int x;
       cin >> x;
       ans = min(ans,x);
       a.push_back(x);
   }
   sort(a.begin(),a.end());
   for(int i = 0; i < a.size()-1; i++){
    ans = min(ans,a[i]^a[i+1]);
   }
   cout << "!" << " " << ans << endl;
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