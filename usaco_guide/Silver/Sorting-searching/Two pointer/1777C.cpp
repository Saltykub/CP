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
    vector<int> arr(n), cnt(m+1);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    int cur = 0, ans = INT_MAX;
    int p = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= sqrt(arr[i]); j++){
            if(arr[i]%j == 0){
                if(j > m) continue;
                if(cnt[j] == 0)  cur++;
                cnt[j]++;
                if(arr[i]/j > m) continue;
                if(cnt[arr[i]/j] == 0) cur++;
                cnt[arr[i]/j]++;
            }
        }
        if(cur == m){
            ans = min(ans,arr[i]-arr[p]);
            while(cur == m){
                 for(int j = 1; j <= sqrt(arr[p]); j++){
                    if(arr[p]%j == 0){
                    if(j > m) continue;
                    cnt[j]--;
                    if(cnt[j] == 0)  cur--;
                    if(arr[p]/j > m) continue;
                    cnt[arr[p]/j]--;
                    if(cnt[arr[p]/j] == 0) cur--;
                    }
                }
                p++;
                if(cur == m) ans = min(ans,arr[i]-arr[p]);
            }
        }
    }
    if(cur == m) ans = min(ans,arr[n-1]-arr[p]);
    cout << ((ans == INT_MAX) ? -1 : ans) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}