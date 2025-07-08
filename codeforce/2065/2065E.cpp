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
    int n,m,k;
    cin >> n >> m >> k;
    // n < m 
    if(k < abs(m-n) || k > max(n,m)) cout << -1 << "\n";
    else {
        string ans = "";
        for(int i = 1; i <= k; i++){
            if(n > m) ans += '0';
            else ans += '1';
        }
        if(n > m){
            n-=k;
            while(n != 0 && m != 0){
                ans += '1';
                ans += '0';
                m--;
                n--;
            }
            while(n!=0) ans += '0',n--;
            while(m!=0) ans += '1',m--;
        }
        else {
            m-=k;
            while(n > 0 && m > 0){
                ans += '0';
                ans += '1';
                m--;
                n--;
            }
            while(n > 0) ans += '0',n--;
            while(m > 0) ans += '1',m--;
        }
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