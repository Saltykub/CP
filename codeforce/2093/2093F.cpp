#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n,m;
    cin >> n >> m;
    map<pair<string,int>,bool> mp;
    map<int,int> ch;
    ll mx = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        mp[{s,i}] = true;
    }
    for(int i = 0; i < m; i++){
        ll cnt = 0;
        for(int j = 0; j < n; j++){
            string s;
            cin >> s;
            if(mp[{s,j}]) {
                cnt++;
                ch[j] = 1;
            }
        }
        mx = max(mx,cnt);
    }
    if(ch.size() < n){
        cout << -1 << "\n";
    }
    else {
        cout << n + (n-mx)*2 << "\n";
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}