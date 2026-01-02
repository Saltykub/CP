#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int ask(int u,int v){
    cout << u << " " << v << endl;
    int x;
    cin >> x;
    return x;
}
void solve (){
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            v.pb({i,j});
        }
    }
    sort(v.begin(),v.end(),[&](pii a, pii b){
        return (a.nd - a.st) < (b.nd-b.st);
    });
    for(auto [u,x]:v){
        if(ask(u,x)){
            return;
        }
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