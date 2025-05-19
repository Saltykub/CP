#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> v[N];
void solve (){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(auto u:arr) {
        int temp = u;
        for(int i = 2; i <= sqrt(temp); i++){
            int cnt = 0;
            while(temp%i == 0){
                cnt++;
                temp/=i;
            }
            if(cnt) v[i].pb(cnt);
        }
        if(temp != 1) v[temp].pb(1);
    }
    ll ans = 1;
    for(int i = 2; i <= 200000; i++){
        if(v[i].size() == n){
            sort(v[i].begin(),v[i].end());
            ans*=pow(i,v[i][1]);
        }
        else if(v[i].size() == n-1){
            sort(v[i].begin(),v[i].end());
            ans*=pow(i,v[i][0]);
        }
    } 
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