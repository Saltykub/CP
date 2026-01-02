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
    int n,k;
    cin >> n >> k;
    int x = n*n-k;
    if(n*n-k == 1){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    if(x == 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout << 'D';
            cout << "\n";
        }
    }
    else {
        char tab[n][n];
        tab[0][0] = 'R';
        tab[0][1] = 'L';
        x-=2;
        for(int i = 0; i <= 0; i++){
            for(int j = 2; j < n; j++){
                if(x){
                    x--;
                    tab[i][j] = 'L';
                }
                else tab[i][j] = 'D';
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                if(x){
                    x--;
                    tab[i][j] = 'U';
                }
                else tab[i][j] = 'D';
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << tab[i][j];
            }
            cout << "\n";
        }
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