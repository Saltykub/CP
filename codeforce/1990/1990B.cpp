#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
   int n,x,y;
    cin >> n >> x >> y;
    int l = y - 1, r = n-x;
    for(int i = 1; i < y; i++) {
        if(l%2){
            if(i%2) cout << -1 << " ";
            else cout << 1 << " ";
        }
        else {
            if(i%2) cout << 1 << " ";
            else cout << -1 << " ";
        }
    }
    for(int i = y; i <= x; i++) cout << 1 << " ";
    for(int i = x+1; i <= n; i++) {
        if(i%2 == (x+1)%2) cout << -1 << " ";
        else cout << 1 << " ";
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