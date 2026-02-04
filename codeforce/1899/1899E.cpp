#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    int n;
    scanf("%d",&n);
    int arr[n];
    int mn=INT_MAX;
    int idx=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i]<mn){mn=arr[i];idx=i;}
    }
    bool can=true;
    for(int i=idx+1;i<n;i++){
        if(arr[i]<arr[i-1])can=false;
    }
    if(can==false)printf("%d",-1);
    else printf("%d",idx);
    printf("\n");
}  
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
}