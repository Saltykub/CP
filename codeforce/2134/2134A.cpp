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
    ll n,a,b;
    cin >> n >> a >> b;
    if(a%2 == n%2 && b%2 == n%2){
        cout << "Yes\n";
    }
    else if(b%2 != n%2){
        cout << "No\n";
    }
    else if(a%2 != n%2 && b%2 == n%2){
        if(b > a) {
            cout << "Yes\n";
        }
        else cout << "No\n";
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