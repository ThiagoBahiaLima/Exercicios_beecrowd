#include <bits/stdc++.h>
using namespace std;

int main(){

   string texto;
   getline(cin,texto);
   int N;
   cin>>N;
   cin.ignore();
   string z;
   getline(cin,z);
   istringstream nemtudo(z);
   while(N--){
      istringstream tudo(texto);
      bool cond = true;
      bool otacond = true;
      string y,x;
      nemtudo >> x;
      int posicao = 0;
      while(tudo >> y){
         if(x == y && otacond){
            cout<<posicao;
            cond = false;
            otacond = false;
         }
         else{
            if(x == y){
               cout<<" "<<posicao;
            }
         }
         posicao += y.size() + 1;
      }
      if(cond){
         cout<<-1;
      }
      cout<<"\n";
   }

   return 0;
}