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
    vector<int> a(n),b(n);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    vector<pii> ans;
    vector<int> posi(2*n+10),cur(2*n+10,0),ch(2*n+10,0);
    for(int i = 0; i < n; i++){
       posi[i+1] = i;
       posi[n+i+1] = i;
    }
    for(int i = 0; i < n; i++){
        cur[a[i]] = 1;
        cur[b[i]] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(cur[i] == cur[n+i]) {
            ch[i] = 1;
            ch[n+i] = 1;
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
        if(ch[a[i]] && ch[b[i]]){
            swap(a[i],b[i]);
            ch[a[i]] = 0;
            if(a[i] > n) ch[a[i]-n] = 0;
            else ch[a[i]+n] = 0;
            ch[b[i]] = 0;
            if(b[i] > n) ch[b[i]-n] = 0;
            else ch[b[i]+n] = 0;
            ans.pb({3,i+1});
        }
        else {
            if(i == n-1) continue;
            if(ch[a[i]]) {
                ans.pb({1,i+1});
                swap(a[i],a[i+1]);
            }
            if(ch[b[i]]){
                ans.pb({2,i+1});
                swap(b[i],b[i+1]);
            }
        }
        }
    }
   
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(posi[a[j]] < posi[a[j-1]]){
                swap(a[j],a[j-1]);
                ans.pb({1,j});
            } 
            if(posi[b[j]] < posi[b[j-1]]){
                swap(b[j],b[j-1]);
                ans.pb({2,j});
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]) {
            ans.pb({3,i+1});
            swap(a[i],b[i]);
        }
    }
    cout << ans.size() << "\n";
    for(auto [l,r]:ans){
        cout << l << " " << r << "\n";
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