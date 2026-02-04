#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    char curc; 
    int cnt = 1, ans = -1;
    curc = s[0];
    for(int i = 1; i < n; i++){
        if(curc == s[i]) {
            cnt++;
            if(cnt > k) {
                i++;
                while( i < n && curc == s[i]){
                    cnt++;
                    i++;
                }
                ans = i-k-1;
                break;
            }
        }
        if(curc != s[i]){
            if(cnt == k){
                cnt = 1;
                curc = s[i];
            }
            else {
                ans = i-1;
                break;
            }
        }
    }
    if(ans == -1) {
        cout << n << "\n";
        return;
    }
    curc = s[ans+1];
    cnt = 1;
    for(int i = ans+2; i < n;i++){
        if(curc == s[i]){
            cnt++;
            if(cnt > k) {
            cout << -1 << "\n";
            return;
           }
        } 
        if(curc != s[i]){
            if(cnt == k){
                cnt = 1;
                curc = s[i];
            }
            else {
                cout << -1 <<"\n";
                return;
            }
        }
    }
    for(int i = ans; i >= 0; i--){
        if(curc == s[i]) {
            cnt++;
            if(cnt > k) {
            cout << -1 << "\n";
            return;
         }
        }
        if(curc != s[i]){
            if(cnt == k){
                cnt = 1;
                curc = s[i];
            }
            else {
                cout << -1 <<"\n";
                return;
            }
        }
    }
    if(cnt == k) cout << ans+1;
    else cout << -1;
    cout << "\n";
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
