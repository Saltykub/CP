#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
int main(){
    int n;
    cin >> n;
    if(n%4 == 3){
        cout << "YES\n";
        cout << n/2+1 << "\n";
        cout << 1 << " " << 2 << " ";
        for(int i = 4; i <= 4+(n-3)/4-1; i++){
            cout << i << " " << n-i+4 <<" ";
        }
        cout << "\n";
        cout << n/2 << "\n";
        cout << 3 << " ";
        for(int i = 4+(n-3)/4; i <= 4+(n-3)/4 +(n-3)/4-1; i++){
            cout << i << " " << n-i+4 << " ";
        }
    } 
    else if(n%4 == 0){
        cout << "YES\n";
        cout << n/2 << "\n";
        for(int i = 1; i <= n/4; i++){
            cout << i << " " << n-i+1 <<" ";
        }
        cout << "\n";
        cout << n/2 << "\n";
        for(int i = n/4+1; i <= n/4+n/4; i++){
            cout << i << " " << n-i+1 << " ";
        }
    }
    else cout << "NO";
}