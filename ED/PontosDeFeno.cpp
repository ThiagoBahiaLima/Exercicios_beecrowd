#include <bits/stdc++.h>
using namespace std;

int main(){

   vector<pair<string,int>> palavrasChave;
   int M,N,valor;
   string chave;
   cin>>M>>N;
   for(int i = 0;i < M;i++){
      cin>>chave>>valor;
      palavrasChave.push_back({chave,valor});
   }
   int soma = 0;
   while(N != 0){
      cin>>chave;
      for(int i = 0;i < palavrasChave.size();i++){
         if(chave == palavrasChave[i].first){
            soma += palavrasChave[i].second;
         }
      }
      if(chave == "."){
         cout<<soma<<"\n";
         soma = 0;
         N--;
      }
   }

   return 0;
}