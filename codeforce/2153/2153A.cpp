#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define vll vector<ll> 
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    set<int> s;
    int n;
    cin >> n;
    vll v(n);
    for(auto &u:v) cin >> u;
    for(auto u:v){
        s.insert(u);
    }
    cout << s.size() << "\n";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}