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
   string s;
   cin >> n >> s;
   vector<int> v;
   for(int i = 0; i < n; i++){
    if(s[i] == '0') v.push_back(i+1);
   }
   if(v.size() == n) {
    cout << 0 << "\n";
   }
   else {
    cout << v.size() << "\n";
    for(auto u:v) cout << u << " ";
    cout << "\n";
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