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
    vector<int> cnt(n+2,0),ans(n+2,0);
    for(auto &x:v) cin >> x,cnt[x]++;
    vector<int> left(n+1,0),suff(n+1,0);
    if(cnt[0]) left[0] = cnt[0]-1;
    for(int i = 1; i <= n; i++) {
        if(cnt[i]) left[i]+=cnt[i]-1;
        left[i] += left[i-1];
    }
    suff[n] = cnt[n];
    for(int i = n-1; i >= 0; i--){
        suff[i] = suff[i+1] + cnt[i];
    }
    for(int i = 0; i <= n; i++){
        if(cnt[i]){
            ans[cnt[i]]++;
            int r = cnt[i];
            if(i > 0) r += left[i-1];
            if(i < n) r += suff[i+1];
            ans[r+1]--;
        }
        else {
            ans[0]++;
            int r = 0;
            if(i > 0) r += left[i-1];
            if(i < n) r += suff[i+1];
            ans[r+1]--;
            break;
        }
    }
    for(int i = 1; i <= n; i++) ans[i]+=ans[i-1];
    for(int i = 0; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}