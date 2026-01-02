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
bool CASE = false;
void solve (){
   int n;
   cin >> n;
   for(int i = 0; i <= 21; i++){
    for(int j = 0; j <= 21; j++){
      for(int k = 0; k <= 21; k++){
        if(i+j+k <= n){
            cout << i << " " << j << " " << k << "\n";
        }
      }
    }
   }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}