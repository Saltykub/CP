#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
   int x,y;
   long long ans = 0;
   cin >> x >> y;
   for(int i = 0; i < 30; i++){
      if(((1<<i)&x) == ((1<<i)&y)) {
         ans++;
      }
      else break;
   }
   cout << int(pow(2,ans)) << "\n";

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
