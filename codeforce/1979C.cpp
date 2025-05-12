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
   ll k[n];
   for(int i = 0; i < n;i++) cin >> k[i];
   ll l = 1, r = 1000000000;
   while(l < r){
      ll mid = (l+r)/2;
      ll coin = 0;
      for(int i = 0; i < n; i++){
         coin += mid/k[i] + 1;
      }
      if(coin < mid){
        for(int i = 0; i < n; i++){
            cout << mid/k[i] + 1 << " ";
        }
        cout << "\n";
        return;
      }
      else {
         l = mid+1;
      }
   }
   cout << -1 <<"\n";

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
