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
    double ans = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = i+2; j < s.size(); j++){
            double x = 0, t = 0;
            if(s[i] == 't' && s[j] == 't'){
                for(int k = i; k <= j; k++){
                    if(s[k] == 't') x++;
                    t++;
                }
                ans = max(ans,(x-2)/(t-2));
            }
        }
    }
    cout << fixed << setprecision(12) << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}