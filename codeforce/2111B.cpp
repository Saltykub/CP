#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int fibo[11];

void solve (){
    int n,m;
    cin >> n >> m;
    string ans = "";
    for(int i = 0; i < m; i++){
        vector<int> v;
        for(int i = 0; i < 3; i++){
            int x;
            cin >> x;
            v.pb(x);
        }
        sort(v.begin(),v.end());
        if(v[2] >= fibo[n]+fibo[n-1] && v[0] >= fibo[n]) ans+="1";
        else ans += "0";
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    fibo[1] = 1;
    fibo[2] = 2;
    for(int i = 3; i <= 10; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}