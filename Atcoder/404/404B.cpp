#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
int cal(vector<vector<char>> s, vector<vector<char>> t, int n){
     int ans = 0;
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] != t[i][j]) ans++;
        }
    }
    return ans;
}
void solve (){
    int n;
    cin >> n;
    vector<vector<char>> s(n,vector<char>(n)), t(n,vector<char>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> s[i][j];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> t[i][j];
    int ans = cal(s,t,n);
    vector<vector<char>> temp;
    for(int j = 0; j < n; j++){
        vector<char> tmp;
        for(int i = n-1; i >= 0; i--){
            tmp.pb(s[i][j]);
        }
        temp.pb(tmp);
    }
    ans = min(ans,cal(temp,t,n)+1);
    temp.clear();
    for(int i = n-1; i >= 0; i--){
        vector<char> tmp;
        for(int j = n-1; j >= 0; j--){
            tmp.pb(s[i][j]);
        }
        temp.pb(tmp);
    }
    ans = min(ans,cal(temp,t,n)+2);
    temp.clear();
    for(int j = n-1; j >= 0; j--){
        vector<char> tmp;
        for(int i = 0; i < n; i++){
            tmp.pb(s[i][j]);
        }
        temp.pb(tmp);
    }
    ans = min(ans,cal(temp,t,n)+3);
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}