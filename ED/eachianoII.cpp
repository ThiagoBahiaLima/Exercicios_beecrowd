#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   cin>>N;
   cin.ignore();
   while(N--){
      string x;
      getline(cin,x);
      istringstream tudo(x);
      getline(cin,x);
      string y;
      int posicao = 0;
      bool cond = true, primeira = true;
      while(tudo >> y){
         if(y == x && primeira){
            cout<<posicao;
            primeira = false;
            cond = false;
         }
         else{
            if(y == x){
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