#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    int n,m;
    cin >> n >> m;
    int tab[n][m];
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) cin >> tab[i][j];
    if( n == 1 && m == 1) cout << -1 << "\n";
    else {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m-1; j++){
                swap(tab[i][j],tab[i][j+1]);
            }
        }
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n-1; i++){
                swap(tab[i][j],tab[i+1][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << tab[i][j]<< " ";
            }
            cout << "\n";
        }
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}