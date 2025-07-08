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
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &x:v) cin >> x;
    set<string> s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            s.insert(v[i]+v[j]);
        }
    }
    cout << s.size();
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}