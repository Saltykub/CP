#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
   ll n, f, a, b;
   cin >> n >> f >> a >> b;
   ll mess[n+1];
   mess[0]=0;
   ll ans = 0;
   for(int i = 1; i <= n; i++)cin >> mess[i];
   for(int i = 1; i <= n; i++){
      ans += min(b,a*(mess[i]-mess[i-1]));   
   }
   if(ans < f)cout<<"YES";
   else cout << "NO";
   cout<<"\n";

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