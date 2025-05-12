#include<bits/stdc++.h>
#define int long long 
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
vector<int> fw(N,0);
void solve (){
   int n;
   cin >> n;
   vector<int> arr(n);
   for(int i = 0; i < n; i++) cin >> arr[i];
   set<int> s;
   for(int i = 1; i < n; i++){
      s.insert(arr[i]-arr[i-1]);
   }
   if(s.size() > 2) cout << "NO\n";
   else {
     if(s.size() == 1 && *s.begin() > 1 && n == 2) cout << "YES\n";
     else {
        auto it = s.begin();
        it++;
        if(*(it)/2 == *(s.begin())) cout << "YES\n";
        else cout << "NO\n";
     }
   }
}
signed main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {   
        solve();
    }

}