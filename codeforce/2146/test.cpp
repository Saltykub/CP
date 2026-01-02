#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
class animal{
    private:
       string name;
       string test;
    public: 
        // default constructor normally c++ will have for you 
        animal(string n, string test): name(n), test(test) {};
        animal (string all) : animal(all,all) {};
        string get_name(){
            return name;
        }
        string get_test(){
            return test;
        }
};
void solve (){
    std::string a = "Citadel";
    std::string b = std::move(a);
    std::cout << a << "\n";    

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}