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
    int x;
    cin >> x;
    if(x <= -3){
        cout << -1*(x+4)*(x+4)+8;
    }
    else if (x <= 2){
        cout << -2*x + 1;
    }
    else {
        cout << x*x*x - 14*x +17;
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