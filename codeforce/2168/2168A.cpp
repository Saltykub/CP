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
    string s;
    cin >> s;
    if(s == "first"){
        int n;
        cin >> n;
        vll v(n);
        for(auto &u:v) cin >> u;
        string ret = "";
        for(auto u:v){
            string tmp = to_string(u);
            for(auto x:tmp){
                ret += (x-'0')+'a';
            }
            if(tmp != "1000000000"){
                ret += "z";
            }
        }
        cout << ret;
    }
    else {
        vll v;
        string tmp;
        cin >> tmp;
        string cur = "";
        for(int i = 0; i < tmp.size(); i++){
            if(tmp[i] == 'z'){
                v.pb(stoi(cur));
                cur = "";
            }
            else if(cur.size() == 10){
                v.pb(stoi(cur));
                cur = to_string(tmp[i]-'a');
            }
            else {
                cur += to_string(tmp[i]-'a');
                //cout << cur << " ";
            }
        }
       // cout << to_string('b'-'a');
       // cout << cur << " ";
        if(cur != "") v.pb(stoi(cur));
        cout << v.size() << "\n";
        for(auto u:v) cout << u << " ";
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