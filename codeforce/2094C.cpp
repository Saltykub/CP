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
    vector<int> ans(2*n+1,0);
    map<int,int> mp;
    for(int i = 2; i <= n+1; i++){
        cin >> ans[i];
        mp[ans[i]] = 1;
    }
    for(int i = n+2 ; i <= 2*n; i++){
        for(int j = 0; j < n-1; j++){
            int x;
            cin >> x;
        }
        cin >> ans [i];
        mp[ans[i]] = 1;
    }
    for(int i = 1; i <=  2*n; i++){
        if(mp[i] == 0) {
            ans[1] = i;
            break;
        }
    }
    for(int i = 1; i <= 2*n; i++) cout << ans[i] << " ";
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