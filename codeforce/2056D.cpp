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
    lldwa n;
    cin >> n;
    map<int,int> mp1[11], mp2[11];
    map<pii,int> off1[11], off2[11];
    for(int i = 1; i <= 10; i++) mp2[i][0] = 1, off2[i][{0,0}] = 1;
    vector<int> arr(n+1);
    vector<int> pref(11,0), cnt(11,0);
    ll ans = n*(n+1)/2;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++){
        for(int j = arr[i]; j <= 10; j++) pref[j]++;
        cnt[arr[i]]++;
        if(i%2 == 1){
            // using mp1
            for(int j = 1; j <= 10; j++){
                ll ch = 2*(pref[j])-i;
                ll choff = ch+cnt[j];
                if(mp1[j][ch]) {
                    ans-=mp1[j][ch]; 
                    ans+=off1[j][{ch,choff}];
                }
                mp1[j][ch]++;
                off1[j][{ch,choff}]++;
            }
        }
        else {
            // using map2;
            for(int j = 1; j <= 10; j++){
                ll ch = 2*(pref[j])-i;
                ll choff = ch+cnt[j];
                if(mp2[j][ch]) {
                    ans-=mp2[j][ch]; 
                    ans+=off2[j][{ch,choff}];
                }
                //if( j == 2 && choff == -2) cout << i;
                mp2[j][ch]++;
                off2[j][{ch,choff}]++;
            }
        }
        //cout << ans << "\n";
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