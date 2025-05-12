#include "dna.h"
#include "grader.cpp"
string A,B;
void init(std::string a, std::string b) {
 A=a,B=b;
}

int get_distance(int x, int y) {
   if(y-x==1)
   {
       if(A[x]!=B[y])return -1;
       else return 1;
   }
   else
   {
       if(A.substr(x,y-x)==B.substr(x,y-x))
   }
}
