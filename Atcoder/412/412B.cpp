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
    string s,t;
    cin >> s >> t;
    map<char,int> mp;
    for(auto u:t) mp[u] = 1;
    for(int i = 1; i < s.size(); i++){
        if(isupper(s[i])){
            if(mp[s[i-1]] == 0) {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
    return;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}