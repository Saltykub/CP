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
    // 2 |2 3 |2 2 |1 
    int n;
    string s;
    cin >> n >> s;
    int cntA = 0, cntB = 0;
    for(auto u:s){
        if(u == 'a') cntA++;
        else cntB++;
    }
    if(cntA == cntB){
        cout << 0 << "\n";
        return;
    }
    vector<int> cnt(n+1,0);
    map<int,int> mp;
    int mn = INT_MAX;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            cnt[i+1]++;
        }
        else cnt[i+1]--;
        cnt[i+1] += cnt[i];
        int target = cnt[i+1]-(cntA-cntB);
        if(mp[target]){
            mn = min(mn,i+1-mp[target]);
        }
        if(target == 0){
            mn = min(mn,i+1);
        }
        mp[cnt[i+1]] = i+1;
    }
    cout << (mn >= n ? -1: mn) << "\n"; 

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}