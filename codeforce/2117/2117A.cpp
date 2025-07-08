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
    vector<int> v(n);
    int f = -1;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] == 1) f = i;
    }
    if(f == -1) cout << "YES\n";
    else {
        for(int i = 0; i < n; i++){
            if(v[i] == 1){
                if(f-i+1 <= k){
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
                return;
            }
        }
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