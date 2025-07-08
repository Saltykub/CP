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
    string s;
    cin >> n >> s;
    string ans = "";
    int l = -1;
    for(int i = 0; i < n-1; i++){
        if(s[i] > s[i+1]){
            l = i;
            break;
        }
    }
    if(l == -1) {
        cout << s << "\n";
    }
    else {
        int r = n;
        for(int i = l+1; i < n; i++){
            if(s[i] > s[l]){
                r = i;
                break;
            }
        }
        for(int i = 0; i < l; i++) ans += s[i];
        for(int i = l+1; i < r; i++) ans += s[i];
        ans += s[l];
        for(int i = r; i < n; i++) ans += s[i];
        cout << ans << "\n";
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