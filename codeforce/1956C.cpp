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
   int sm = 0;
   for(int i = 1; i <= n; i++){
        sm += i*(2*i-1);
   }
   cout << sm << " " << (2*n-1) <<"\n";
   auto permu = [&](){
        for(int i = 1; i <= n; i++) {cout << i << " ";}
        cout << "\n";
   };
   int row = n, col = n-1;
   for(int i = 1; i <= 2*n-1;i++){
      if(i%2){
        cout << 1 << " " << row-- << " ";
        permu();
      }
      else {
        cout << 2 << " " << col-- << " ";
        permu();
      }
   }
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