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
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int g = 0;
    bool can = false;
    for(int i = 0; i < n; i++){
        g = __gcd(g,v[i]);
        if(v[i] != v[0]) can = true;
    }
    if(!can) cout << "No\n";
    else {
        cout << "Yes\n";
        bool one = false;
        for(int i = 0; i < n; i++){
            if(v[i] != g){
                if(one) cout << 2 << " ";
                else {
                    cout << 1 << " ";
                    one = true;
                }
            }
            else {
                cout << 2 << " ";
            }
        }
        cout << "\n";
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