#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
   int n;
   cin >> n;
   int a[n];
   vector<int> cnt(n+1,0);
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < n; i++) cnt[a[i]]++;
   bool can = false;
   for(int i = 1; i <= n; i++){
        if(cnt[i]%2) {
            can = true;
        }
   }
   if(can) cout << "Yes\n";
   else cout << "No\n";
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