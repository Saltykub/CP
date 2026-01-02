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
    vll v(n);
    for(auto &u:v) cin >> u;
    if(v[0] == -1 && v[n-1] == -1){
       cout << 0 << "\n";
       for(auto u:v){
           if(u == -1) cout << 0 << " ";
           else cout << u << " ";
       }
       cout << "\n";
    }
    else if(v[0] == -1){
       cout << 0 << "\n";
       v[0] = v[n-1];
       for(auto u:v){
           if(u == -1) cout << 0 << " ";
           else cout << u << " ";
       }
       cout << "\n";
    }
    else if(v[n-1] == -1){
       cout << 0 << "\n";
       v[n-1] = v[0];
       for(auto u:v){
           if(u == -1) cout << 0 << " ";
           else cout << u << " ";
       }
       cout << "\n";
    }
    else {
        cout << abs(v[0]-v[n-1]) << "\n";
        for(auto u:v){
           if(u == -1) cout << 0 << " ";
           else cout << u << " ";
       }
       cout << "\n";
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