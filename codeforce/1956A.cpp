#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    int n,q;
    cin >> n >> q;
    int mn;
    cin >> mn;
    for(int i = 0; i < n-1; i++){int x;cin>>x;}
    while(q--){
        int a;
        cin >> a;
        cout << min(a,mn-1) << " ";
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