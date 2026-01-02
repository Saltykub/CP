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
    vector<int> v(n);
    for(auto &u:v) cin >> u;
    sort(v.begin(),v.end());
    vector<int> cnt(101,0), num(101,0);
    for(auto u:v){
        num[u]++;
        cnt[num[u]]++;
    }
    int ans = 0;
    for(int i = 0; i <= 100; i++){
        ans = max(i*cnt[i],ans);
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