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
    string s;
    cin >> s;
    bool t1 = false, t2 = false;
    for(int i = 0; i < sz(s); i++){
        if(i+4 <= sz(s)){
            if(s.substr(i,4) == "2025") t1 = true;
            if(s.substr(i,4) == "2026") t2 = true;
        }
    }
    if(t2 || !t1) {
        cout << 0 << "\n";
    }
    else cout << 1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}