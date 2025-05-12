#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
int arr[N];
int main(){
    ll n,l,r,cur=0,mx=INT_MIN,cur_length=0;
    cin >> n >> l >> r;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i = 1, j = 1; i <= n;i++){
         cur += arr[i];
         cur_length++;
         if(cur_length > r){
            cur -= arr[j];
            cur_length--;
            j++;
         }  
         if(cur_length < l)continue;
         mx = max(mx,cur);
         while(cur < 0){
            cur -= arr[j];
            cur_length--;
            j++;
         }
         if(cur_length < l)continue; 
         mx = max(mx,cur);
         cout<<cur<<" "<<cur_length<<" "<<i<<"\n";
    }
    cout<<mx;
}