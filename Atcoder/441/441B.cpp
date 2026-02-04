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
bool CASE = false;
void solve (){
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    map<char,int> mps, mpt;
    for(auto u:s) mps[u]++;
    for(auto u:t) mpt[u]++;
    int q;
    cin >> q;
    while(q--){
        string x;
        cin >> x;
        bool bs = true, bt = true;
        for(auto u:x){
            if(!mps[u]) bs = false;
            if(!mpt[u]) bt = false;
        }
        if(bs && bt){
            cout << "Unknown\n";
        }
        else if(bs){
            cout << "Takahashi\n";
        }
        else {
            cout << "Aoki\n";
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