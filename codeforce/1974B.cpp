#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb emplace_back
using namespace std;
void solve (){
    int n;
    string s;
    cin >> n >> s;
    string temp = s;
    sort(temp.begin(),temp.end());
    vector<char> v;
    for(int i = 0; i < n; i++){
        if(i == 0) v.pb(temp[i]);
        else {
          if(temp[i] == temp[i-1]) continue;
          v.pb(temp[i]);
        }
    }
    map<char,char> mp;
    int sz = v.size();
    for(int i = 0, j = sz-1; i < sz, j >= 0; i++, j--){
       mp[v[i]] = v[j];
    }
    for(int i = 0; i < n; i++){
       s[i] = mp[s[i]];
    }
    cout << s << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // if(t!=11){
    //     for(int i = 1; i <= t; i++) {
    //         int x,y;
    //         cin >> x >> y;
    //         if(i == 1002) cout << x << " " << y;
    //     }
    //     return 0;
    // }
    // t=1;
    while(t--)
    {
        solve();
    }
}