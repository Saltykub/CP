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
    int n,k;
    cin >> n >> k;
    vector<int> v;
    vector<int> pref(n,0), suff(n,0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x > k) v.pb(-1);
        else v.pb(1);
    }
    pref[0] = v[0];
    suff[n-1] = v[n-1];
    for(int i = 1; i < n; i++) pref[i] += pref[i-1]+v[i];
    for(int i = n-2; i >= 0; i--) suff[i] += suff[i+1] + v[i];
    int x= -1;
    for(int i = 0; i < n; i++){
        if(pref[i] >= 0){
            x = i;
            break;
        }
    }
    for(int j = n-1; j >= 0; j--){
        if(suff[j] >= 0){
            if(x != -1){
                if(x+1 < j) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    vector<int> mxpref(n,0), mxsuff(n,0);
    mxpref[n-1] = pref[n-1];
    mxsuff[0] = suff[0];
    for(int i = n-2; i >= 0; i--){
        mxpref[i] = max(mxpref[i+1],pref[i]);
    }
    for(int i = 1; i < n; i++){
        mxsuff[i] = max(mxsuff[i-1],suff[i]);
    }
    for(int i = 0; i < n-2; i++){
        if(pref[i] >= 0){
            if(mxpref[i+2] >= 0){
                cout << "YES\n";
                return;
            }
        }
    }
    for(int i = n-1; i >= 2; i--){
        if(suff[i] >= 0){
            if(mxsuff[i-2] >= 0){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}