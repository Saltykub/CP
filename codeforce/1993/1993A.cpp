#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
void solve(){
    vector<int> cnt(5);
    int n;
    cin >> n;
    string s; 
    cin >> s;
    for(auto c:s){
        if(c=='?') cnt[4]++;
        else cnt[c-'A']++;
    }
    int ans = 4*n;
    for(int i = 0; i <= 3; i++){
        if(cnt[i] > n) ans -= cnt[i]-n;
    }
    cout << ans-cnt[4] << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}