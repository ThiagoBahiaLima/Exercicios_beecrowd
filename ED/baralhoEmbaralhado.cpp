#include <bits/stdc++.h>
using namespace std;

int main(){

   int cartas;
   cin>>cartas;
   int metade = cartas/2;
   int pos = 0;
   int embaralhadas = 0;
   for(int i = 0;pos != 0 || i == 0;i++){
      if(pos < metade){
         pos = pos*2 + 1;
         embaralhadas++;
      }
      else{
         pos = (pos - metade)*2;
         embaralhadas++;
      }
   }
   cout<<embaralhadas<<"\n";

   return 0;
}