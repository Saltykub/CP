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
    int w,b;
    cin >> b >> w;
    int diff = abs(w-b);
    if(w > b){
        cout << 2*w << " " << 2 << "\n";
        for(int i = 0; i < b; i++){
            cout << ".." << "\n";
            cout << "@@" << "\n";
        } 
        for(int i = 0; i < diff; i++){
            cout << ".@" << "\n";
            cout << "@@" << "\n";
        }
    }
    else {
        cout << 2*b << " " << 2 << "\n";
         for(int i = 0; i < w; i++){
            cout << "@@" << "\n";
            cout << ".." << "\n";
        } 
        for(int i = 0; i < diff; i++){
            cout << "@." << "\n";
            cout << ".." << "\n";
        }
    }
}
int main(){   
    // ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("black.in","r",stdin);
    freopen("black.out","w",stdout);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}