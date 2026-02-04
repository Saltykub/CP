#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
ll cal(string bit){
    ll ans = 0;
    for(int i = 0; i < bit.size(); i++){
        if(bit[i] == '1') ans += pow(2,i);
    }
    return ans;
}
void solve (){
   ll n;
   cin >> n;
   string bit = "";
   while(n){
     bit += n%2 + '0';
     n/=2;
   }
   vector<ll> ans;
   ll c = cal(bit);
   ans.pb(c);
   string temp = bit;
   for(int i = 0; i < bit.size(); i++){
      if(bit[i] == '1') {
          temp[i] = '0';
          for(int j = 0; j < i; j++) {
            if(bit[j] != temp[j]) temp[j] = bit[j];
          }
          c = cal(temp);
          if(c == 0) break;
          ans.pb(c);
      }
   }
   cout << ans.size() << "\n";
   reverse(ans.begin(),ans.end());
   for(auto u:ans){
    cout << u << " ";
   }
   cout << "\n";
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