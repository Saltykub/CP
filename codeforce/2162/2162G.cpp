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
    cin >> n;
    if(n == 2){
        cout <<  -1 << "\n";
        return;
    }
    else if(n == 3){
        cout << 1 << " " << 3 << "\n";
        cout << 2 << " " << 3 << "\n";
    }
    else if(n == 4){
        cout << 1 << " " << 2 << "\n";
        cout << 1 << " " << 3 << "\n";
        cout << 1 << " " << 4 << "\n";
    }
    else {
        for(int i = 1; i <= n-1; i++){
            if(i == 2 || i == 4){
                continue;
            }
            cout << 2 << " " << i << "\n";
        }
        cout << 3 << " " << 4 << "\n";
        cout << 1 << " " << n << "\n";
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