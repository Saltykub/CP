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
int p[N][35];
int jmp(int i, int k){
    int ret = i;
    for(int i = 0; i < 30; i++){
        if((1LL<<i)&k){
            ret = p[ret][i];
        }
    }
    return ret;
}
void solve (){
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> p[i][0];
    }
    // pre-process 
    for(int i = 1; i < 30; i++){
        for(int j = 1; j <= n; j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    while(q--){
        int i,k;
        cin >> i >> k;
        cout << jmp(i,k) << "\n";
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