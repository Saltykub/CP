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
    ll n,k;
    cin >> n >> k;
    if(n == 1 && k == 2){
        cout << "Yes\n";
        return;
    }
    if(n == 1 && k == 1){
        cout << "No\n";
        return;
    }
    if(k > 1){
        cout << "No\n";
        return;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}