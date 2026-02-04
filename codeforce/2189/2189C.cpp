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
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    for(int i = 0; i < 30; i++){
        if(pow(2,i) == n){
            cout << -1 << "\n";
            return;
        }
    }
    if(n == 3){
        cout << "2 1 3";
    }
    else {
        if(n%2){
            cout << n - (n%2) << " ";
            for(int i =  2; i < n; i++){
                if(i%2){
                    cout << i-1;
                }
                else {
                    cout << i+1;
                }
                cout << " ";
            }
            cout << 1 << " ";
        }
        else {
            
            int target = 0;
            for(int i = 30; i >= 0; i--){
                if((1<<i)&n){
                    target = (1<<i)^n;
                    break;
                }
            }
            cout << target << " ";
            for(int i =  2; i < n; i++){
                    if(i%2){
                        if(i-1 == target) cout << n;
                        else cout << i-1;
                    }
                    else {
                        if(i+1 == target) cout << n;
                        else cout << i+1;
                    }
                cout << " ";
            }
            cout << 1 << " ";
        }
    }
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}