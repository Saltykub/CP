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
int a[200][200];
void solve (){
    int n;
    cin >> n; 
    a[0][(n-1)/2] = 1;
    int cur = 1;
    int r = 0, c = (n-1)/2;
    for(int i = 0; i < n*n-1; i++){
        //cout << r << " " << c << "\n";
        int rr = (r-1)%n;
        rr+=n;
        rr%=n;
        int cc = (c+1)%n;
        cc+=n;
        cc%=n;
        if(a[rr][cc] == 0){
            
            a[rr][cc] = ++cur;
            r = rr;
            c = cc;
            continue;
        }
        rr = (r+1)%n;
        rr+=n;
        rr%=n;
        a[rr][c] = ++cur;
        r = rr;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
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