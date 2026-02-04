#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    string s;
    cin>>s;
    bool status=true,can=true;
    int sz=0;
    int mnfalse=-1;
    int sortsz=0;
    int ssz=s.size();
    for(int i=0;i<ssz;i++)
    {
        if(s[i]=='+')sz++;
        if(s[i]=='-')sz--;
        if(sz<mnfalse)
        {
            mnfalse=-1;
            status=true;
        }
        if(sz<sortsz)
        {
            sortsz=sz;
        }
        if(s[i]=='0')
        {   
            if(sz<2)
            {
                can=false;
               
                break;
            }
            if(status==false)continue;
            if(status==true&&sz>sortsz)
            {
                status=false;
                //sortsz=0;
                mnfalse=sz;
            }
            else 
            {
                can=false;break;
                
            }
            
        }
        if(s[i]=='1')
        {
            if(status==false&&mnfalse<=sz&&mnfalse!=-1)
            {
                can=false;
                break;
            }
            else
            {   
                sortsz=sz;
                mnfalse=-1;
                status=true;
            }
        }
    }
    if(can)cout<<"YES";
    else cout<<"NO";
    cout<<"\n";
    
}
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}