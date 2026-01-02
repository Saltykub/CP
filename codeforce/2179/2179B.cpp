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
    ll sm = 0;
    for(int i = 1; i < n; i++) sm += abs(v[i]-v[i-1]);
    ll mn = INT_MAX;
    for(int i = 0; i < n; i++){
        if(i == 0){
            mn = min(mn,sm-abs(v[0]-v[1]));
        }
        else if( i ==  n-1){
            mn = min(mn,sm-abs(v[n-1]-v[n-2]));
        }
        else {
            mn = min(mn,sm-abs(v[i]-v[i+1])-abs(v[i]-v[i-1])+abs(v[i+1]-v[i-1]));
        }
    }
    cout << mn << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}