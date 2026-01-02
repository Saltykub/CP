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
    string s,t;
    cin >> s >> t;
    multiset<char> ms;
    for(auto u:t)ms.insert(u);
    for(auto u:s){
        if(ms.find(u) == ms.end()){
            cout << "Impossible\n";
            return;
        }
        ms.erase(ms.find(u));
    }
    string tmp = "";
    for(auto u:ms) tmp += u;
    int j = 0;
    string ans = "";
    for(auto u:s){
        while(j < tmp.size() && tmp[j] < u){
            ans += tmp[j];
            j++;
        }
        ans += u;
    }
    while(j < tmp.size()) {
        ans += tmp[j];
        j++;
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}