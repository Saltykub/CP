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
    string s;
    cin >> s;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    int ans = 0;
    int j = -1;
    //int go = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') ans += v[i];
        else {
            j = i;
            break;
        }
    }
    for(int i = j+1; i < n; i++){
        if(s[i] == '0'){
            if(s[i-1] == '0') {
                j = i;
            }
            else {
                int mn = INT_MAX;
                for(int k = j; k < i; k++){
                    mn = min(v[k],mn);
                    ans += v[k];
                }
                ans -= mn;
                j = i;
            }
        }
    }
    //cout << j;
    if(j != -1 ){
        if(s[n-1] == '1'){
            int mn = INT_MAX;
            for(int k = j; k < n; k++){
                mn = min(v[k],mn);
                ans += v[k];
            }
            ans -= mn;
        }
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