#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);
    int dup = 0, notdup, nenedup;
    for(int i = 0; i < n-1; i++){
        if(arr[i] == arr[i+1]) dup++;
    }
    notdup = n-2*dup;
    nenedup = n - notdup;
    if(dup <= nenedup) cout << dup;
    else cout << dup + notdup;
    cout << "\n";
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