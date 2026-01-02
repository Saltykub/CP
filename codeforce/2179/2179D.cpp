#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
   ll n;
   cin >> n;
   int cnt = 1;
   int shift = n;
   cout << (1LL<<n)-1 << " ";
   for(ll i = n-1; i >= 0; i--){
      for(ll j = 0; j < (1LL<<(cnt-1)); j++){
          cout << (1LL<<i)-1+j*(1LL<<shift) << " ";
      }
      cnt++;
      shift--;
   }
   cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}