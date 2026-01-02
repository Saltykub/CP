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
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vll  v(n);
    for(auto &u:v) cin >> u;
    if(n <= 5000){
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if((v[j]%v[i])%2 == 0){
                    cout << v[i] << " " << v[j] << "\n";
                    return;
                }
            }
        }
        cout << -1 << "\n";
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((v[j]%v[i])%2 == 0){
                cout << v[i] << " " << v[j] << "\n";
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