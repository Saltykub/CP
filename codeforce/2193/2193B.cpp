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
    int target = n;
    int idx = n-1;
    for(int i = 0; i < n; i++){
        if(target == v[i]){
            target--;
        }
        else {
            idx = i;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(v[i] == target){
            reverse(v.begin()+idx,v.begin()+i+1);
            break;
        }
    }
    for(auto u:v) cout << u << " ";
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