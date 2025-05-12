#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n;
    cin >> n;
    vector<int> succ(n+1,0);
    for(int i = 1; i <= n; i++) cin >> succ[i];
    for(int i = 1; i <= n; i++){
        int a = succ[i], b = succ[succ[i]];
        while(a!=b){
            a = succ[a];
            b = succ[succ[b]];
        }
        a = i;
        while(a!=b){
            a = succ[a];
            b = succ[b];
        }
        cout << a << " ";
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