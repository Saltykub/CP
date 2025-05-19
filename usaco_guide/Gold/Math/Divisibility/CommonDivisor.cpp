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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> mp(1000001,0);
    for(auto u:arr){
       mp[u]++;
    }
    // time complex o(max X (log max X))
    for(int i = 1000000; i >= 1; i--){
        int cnt = 0;
        for(int j = i; j <= 1000000; j+=i){
            cnt += mp[j];
            if(cnt >= 2){
                cout << i;
                return;
            }
        }
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