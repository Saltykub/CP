#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    vector<int> qs(n+2,0);
    while(m--){
        int l,r;
        cin >> l >> r;
        qs[l-1]++;
        qs[r]--;
    }
    for(int i = 1; i < n; i++) qs[i]+=qs[i-1];
    string ans = "";
    for(int i = 0; i < n; i++){
        if(qs[i]%2) ans += t[i];
        else ans += s[i];
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}