#include <bits/stdc++.h>
using namespace std;

int main(){

   int casos;
   cin>>casos;
   while(casos--){
      int menor = (50*99) + 1;
      int maior = -1;
      int lojas;
      cin>>lojas;
      while(lojas--){
         int pos;
         cin>>pos;
         if(pos > maior){
            maior = pos;
         }
         if(pos < menor){
            menor = pos;
         }
      }
      int distancia = (maior - menor)*2;
      cout<<distancia<<"\n";
   }

   return 0;
}