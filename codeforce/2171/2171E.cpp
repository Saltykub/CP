#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vll v[3];
    for(int i = 1; i <= n; i++){
        if(i%2 == 0) v[0].pb(i);
        else if(i%3==0) v[1].pb(i);
        else v[2].pb(i);
    }
    while(v[2].size() >= 1 && v[0].size() >= 2){
        cout << v[2].back() << " ";
        v[2].pop_back();
        cout << v[0].back() << " ";
        v[0].pop_back();
        cout << v[0].back() << " ";
        v[0].pop_back();
    }
    while(v[2].size() >= 1 && v[1].size() >= 2){
        cout << v[2].back() << " ";
        v[2].pop_back();
        cout << v[1].back() << " ";
        v[1].pop_back();
        cout << v[1].back() << " ";
        v[1].pop_back();
    }
    for(auto u:v[0]) cout << u << " ";
    for(auto u:v[1]) cout << u << " ";
    for(auto u:v[2]) cout << u << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}