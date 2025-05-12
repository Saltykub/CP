#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
   int n;
   cin >> n;
   vector<ll> v(n,0);
   for(int i = 0; i < n; i++) cin >> v[i];
   for(int i = 0; i < n-2; i++){
      v[n-2] -= v[i];
   }
   cout << v[n-1] - v[n-2] << "\n";
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