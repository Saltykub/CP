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
    string t = s;
    sort(all(t));
    vll move;
    for(int i = 0; i < n; i++){
        if(t[i] != s[i]){
            move.pb(i+1);
        }
    }
    if(move.empty()) cout << "Bob\n";
    else {
        cout << "Alice\n";
        cout << sz(move) << "\n";
        for(auto u:move) cout << u << " ";
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