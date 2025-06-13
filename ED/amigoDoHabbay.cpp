#include <bits/stdc++.h>
using namespace std;

int main(){

   map<string,pair<string,int>>::iterator it;
   map<string,pair<string,int>> pessoas;
   string x;
   for(int i = 1;cin>>x && x != "FIM";i++){
      string y;
      cin>>y;
      it = pessoas.find(x);
      if(it == pessoas.end()){
         pessoas[x] = {y,i};
      }
   }
   int maior = 0;
   string nome;
   for(it = pessoas.begin();it != pessoas.end();it++){
      if(it->second.first == "YES"){
         cout<<it->first<<"\n";
         if(it->first.size() > maior){
            maior = it->first.size();
            nome = it->first;
         }
         if(it->first.size() == maior){
            if(it->second.second < pessoas[nome].second){
               nome = it->first;
            }
         }
      }
   }
   for(it = pessoas.begin();it != pessoas.end();it++){
      if(it->second.first == "NO"){
         cout<<it->first<<"\n";
      }
   }
   cout<<"\nAmigo do Habay:\n"<<nome<<"\n";

   return 0;
}