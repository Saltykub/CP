#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
   int n,x,y,z;
   cin >> n >> x >> y >> z;
   if(x >= z && z >= y) cout << "Yes";
   else if(x <= z && z <=y) cout << "Yes";
   else cout << "No";
}
int main(){   
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}