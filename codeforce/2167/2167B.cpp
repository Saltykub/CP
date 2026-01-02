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
    string a,b;
    cin >> n >> a >> b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a == b){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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