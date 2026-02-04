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
    int q;
    cin >> q;
    int vol = 0;
    int play = 0;
    while(q--){
        int x;
        cin >> x;
        if(x == 1) vol++;
        else if(x == 2){
            vol--;
            vol = max(vol,0);
        }
        else{
            play^=1;
        }
        if(play && vol >= 3) {
            cout << "Yes\n";
        }
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