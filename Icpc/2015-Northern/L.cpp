#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
int tab[150][150];
void solve (){

    int r,c;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) cin >> tab[i][j];
    }
    int cnt = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int go = i;
            bool can = true;
            while(go > 0){
                go--;
                if(tab[i][j] <= tab[go][j]) {
                    can = false;
                    break;
                }
            }
            if(can) cnt++;
            go = i;
            can = true;
            while(go < r){
                go++;
                if(tab[i][j] <= tab[go][j]) {
                    can = false;
                    break;
                }
            }
            if(can) cnt++;
            go = j;
            can = true;
            while(go > 0){
                go--;
                if(tab[i][j] <= tab[i][go]) {
                    can = false;
                    break;
                }
            }
            if(can) cnt++;
            go = j;
            can = true;
            while(go < c){
                go++;
                if(tab[i][j] <= tab[i][go]) {
                    can = false;
                    break;
                }
            }
            if(can) cnt++;
            //cout << cnt << " ";
        }
    }
    cout << cnt;
    
}
int main(){   
    // ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("lucky.in","r",stdin);
    freopen("lucky.out","w",stdout);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}