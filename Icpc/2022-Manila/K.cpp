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
    string qw = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string a,b,c;
    cin >> a >> b >> c;
    string tmp = a+b+c;
    set<char> ch;
    for(int i = 0; i < tmp.size(); i++){
        if(tmp[i] == '*'){
            ch.insert(qw[i]);
        }
    }
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        set<char> ss;
        for(auto u:s) ss.insert(u);
        if(ss == ch){
            cout << "POSSIBLE\n";
        }
        else {
            cout << "IMPOSSIBLE\n";
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