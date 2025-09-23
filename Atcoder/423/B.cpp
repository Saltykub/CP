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
   int n;
   cin >> n;
   vector<int> v(n);
   for(auto &x:v) cin >> x;
   int f = -1;
   for(int i = 0; i < n; i++){
        if(v[i] == 1) {
            f = i;
            break;
        }
   }
  // cout << f << " ";
   int s = -1;
   for(int i = n-1; i >= 0; i--){
        if(v[i] == 1){
            s = i;
            break;
        }
   }
   if(f == -1){
    cout << 0;
   }
   else cout << s-f;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}