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
    string s;
    cin >> s;
    int n = s.size();
    string ans = "";
    for(int i = 0; i < n; i++){
       ans += s[i];
       if(s[i] == '-'){
           ans += s[++i];
           while(true){
             i++;
             if(i >= n) break;
             if(s[i] == '-'){
                i--;
                break;
             }
             if(s[i] == '+'){
                ans += '+';
                break;
             }
             if(s[i] != '0'){
                ans += '+';
                ans += s[i];
                break;
             }
             ans += '+';
             ans += s[i];
           }
       }
       //cout << s[i] << "\n";
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("easy.in","r",stdin);
    // freopen("easy.out","w",stdout);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}