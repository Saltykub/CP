#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
   int n,q;
   scanf("%d %d",&n,&q);
   for(int i=1;i<=n-1;i++){
        printf("%d %d\n",i,i+1);
   }
   int x=n-1;
   while(q--){
        int cur;
        scanf("%d",&cur);
        if(cur==x){
            printf("%d %d %d\n",-1,-1,-1);
        }
        else {
            printf("%d %d %d\n",n,x,cur);
            x=cur;
        }
   }
   
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