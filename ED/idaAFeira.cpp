#include <bits/stdc++.h>
using namespace std;

int main(){

   map<string,float>::iterator it;
   map<string,float> tabela;
   int idas;
   cin>>idas;
   while(idas--){
      int N;
      float soma = 0;
      cin>>N;
      while(N--){
         string x;
         float y;
         cin>>x>>y;
         tabela[x] = y;
      }
      cin>>N;
      while(N--){
         string x;
         int y;
         cin>>x>>y;
         it = tabela.find(x);
         soma += it->second*y;
      }
      cout<<fixed<<setprecision(2);
      cout<<"R$ "<<soma<<"\n";
   }

   return 0;
}