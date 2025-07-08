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
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    vector<int> pref(m,INT_MAX), suff(m,INT_MAX);
    int j = 0;
    for(int i = 0; i < n; i++){
        if(j < m && a[i] >= b[j]) pref[j++] = i;
    }
    j = m-1;
    for(int i = n-1; i >= 0; i--){
        if(j >= 0 && a[i] >= b[j]) suff[j--] = i;
    }
    if(pref[m-1] != INT_MAX){
        cout << 0 << "\n";
        return;
    }
    if(m == 1){
        cout << b[0] << "\n";
        return;
    }
    int mn = INT_MAX;
    for(int i = 0; i < m; i++){
       if(i == 0){
           if(suff[i+1] >= 0 && suff[i+1] != INT_MAX) mn = min(mn,b[i]);
       }
       else if(i == m-1){
           if(pref[i-1] < n && pref[i-1] != INT_MAX) mn = min(mn,b[i]);
       }
       else {
         if(pref[i-1] < suff[i+1] && suff[i+1] != INT_MAX && pref[i-1] != INT_MAX) mn = min(mn,b[i]);
       }
    }
    if(mn != INT_MAX) cout << mn << "\n";
    else cout << -1 << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}