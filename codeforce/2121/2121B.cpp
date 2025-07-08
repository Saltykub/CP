#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> mp;
    for(int i = 1; i < n-1; i++){
        mp[s[i]]++;
    }
    for(auto u:mp){
        if(u.nd >= 2){
            cout << "Yes\n";
            return;
        }
    }
    if(mp[s[0]] || mp[s[n-1]]){
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}