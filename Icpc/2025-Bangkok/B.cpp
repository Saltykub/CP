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
    int n,m;
    cin >> n >> m;
    if(n == 2){
        if(m%2){
            cout << 2 << " " << 1;
        }
        else {
            cout << 1 << " " << 2;
        }
        cout << "\n";
        return;
    }
    if(m <= n-1){
        for(int i = 0; i < min(m,n); i++){
            cout << n-i << " ";
        }
        for(int i = 1; i <= max(n-m,0); i++){
            cout << i << " ";
        }
    }
    else {
        for(int i = n; i >= 1; i--){
            cout << i << " ";
        }
    }
    
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}