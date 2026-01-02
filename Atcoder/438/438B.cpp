#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    int ans = INT_MAX;
    for(int i = 0; i <= n-m; i++){
        string cal = s.substr(i,m);
        int mn = INT_MAX;
        int cnt = 0;
        for(int j = 0; j < m; j++){
            int s1 = cal[j] - '0', s2 = t[j]-'0';
                for(int k = 0; k < 10; k++){
                        if((s2+k)%10 == s1) {
                            cnt += k;
                            break;
                        }
                    }
            }
        ans = min(ans,cnt);
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