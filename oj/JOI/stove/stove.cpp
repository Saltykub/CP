#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=1e5+10;
long long arr[N];
int main(){
    int n,k;
    cin>>n>>k;
    k--;
    ll sum=0;
    for(int i=0;i<n;i++)cin>>arr[i];
    sum=arr[n-1]+1-arr[0];
    priority_queue<int> pq;
    pq.push(0);
    for(int i=1;i<n;i++){
        pq.push(arr[i]-arr[i-1]-1);
    }
    while(k--){
        sum-=pq.top();
        pq.pop();
    }
    cout<<sum;
}