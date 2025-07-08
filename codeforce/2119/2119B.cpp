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
    ll px,py,qx,qy;
    int n;
    cin >> n;
    cin >> px >> py >> qx >> qy;
    double d = sqrt((px-qx)*(px-qx) + (py-qy)*(py-qy));
    vector<int> v(n);
    ll sm = 0;
    for(auto &x:v) cin >> x, sm += x;
    sort(v.begin(),v.end());
    if(sm < d){
        cout << "No\n";
    }
    else if(sm == d) {
        cout << "Yes\n";
    }
    else {
        if(v[n-1]-sm+v[n-1] <= d) cout << "Yes\n";
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