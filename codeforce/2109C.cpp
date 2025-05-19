#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int add(ll x){
    cout << "add " << x << endl;
    int ret;
    cin >> ret;
    return ret;
}
int mul(ll x){
    cout << "mul " << x << endl;
    int ret;
    cin >> ret;
    return ret;
}
int div(ll x){
    cout << "div " << x << endl;
    int ret;
    cin >> ret;
    return ret;
}
int digit(){
    cout << "digit" << endl;
    int ret;
    cin >> ret;
    return ret;
}
int ans(){
    cout << "!" << endl;
    int ret;
    cin >> ret;
    return ret;
}
void solve (){
    ll n;
    cin >> n;
    int q;
    q = mul(999999999);
    q = digit();
    if(n!=81) q = add(n-81); 
    q = ans();
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}