#include <bits/stdc++.h>
using namespace std;

int main(){

int N;
vector<pair<string,int>> criancas;
while(cin>>N && N != 0){
   for(int i = 0;i < N;i++){
      string x;
      int y;
      cin>>x>>y;
      criancas.push_back({x,y});
   }
   int mortas = 0;
   int limite, i = 0, j = 0;
   while(mortas != N - 1){
      if(mortas == 0){
         limite = criancas[0].second;
      }
      if(limite%2 == 0){
         i--;
      }
      else{
         i++;
      }
      if(i == criancas.size()){
         i = 0;
      }
      if(i == -1){
         i = criancas.size() - 1;
      }
      if(criancas[i].second != 0){
         j++;
      }
      if(j == limite){
         limite = criancas[i].second;
         criancas[i].second = 0;
         j = 0;
         mortas++;
      }

   }
   for(int i = 0;i < criancas.size();i++){
      if(criancas[i].second != 0){
         cout<<"Vencedor(a): "<<criancas[i].first<<"\n";
      }
   }
   criancas.clear();
}

   return 0;
}