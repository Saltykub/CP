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
    int n,m;
    string a,b;
    cin >> n >> a >> m >> b;
    string op;
    cin >> op;
    int i = 0;
    for(auto u:op){
        if(u == 'D'){
            a += b[i++];
        }
        else {
            string tmp = a;
            a = b[i++] + tmp;
        }
    }
    cout << a << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}