#include "grader.h"
#include "cluedo.h"

void Solve(){
   int x,y,z;
   x=y=z=1;
   for(int i=0;i<20;i++)
   {
     int check=Theory(x,y,z);
     if(check==1)x++;
     else if(check==2)y++;
     else if(check==3)z++;
     else return;
   }
}
