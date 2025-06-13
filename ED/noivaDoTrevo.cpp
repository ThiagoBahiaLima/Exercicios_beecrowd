#include <bits/stdc++.h>
using namespace std;

int main(){

   int limite, relatos;
   vector<pair<string,pair<string,int>>> vetor;
   cin>>limite>>relatos;
   int caso = 1;
   while(relatos--){
      string hora, nome;
      cin>>hora>>nome;
      if(hora[0] == 50){
         int aux = (hora[3] - 48)*10 + (hora[4] - 48);
         if(60 - aux <= limite){
            vetor.push_back({hora,{nome,caso}});
         }
      }
      else{
         int aux = (hora[3] - 48)*10 + (hora[4] - 48);
         if(aux <= limite){
            vetor.push_back({hora,{nome,caso}});
         }
      }
      caso++;
   }
   sort(vetor.begin(),vetor.end(),[](pair<string,pair<string,int>> a,pair<string,pair<string,int>> b){
      if(a.first[0] == 50 && b.first[0] == 48) return true;
      if(a.first[0] != 50 && b.first[0] != 48) return false;
      if(a.first[0] == 50 && b.first[0] == 50 && a.first[3] > b.first[3]) return false;
      if(a.first[0] == 50 && b.first[0] == 50 && a.first[3] < b.first[3]) return true;
      if(a.first[0] == 50 && b.first[0] == 50 && a.first[4] > b.first[4]) return false;
      if(a.first[0] == 50 && b.first[0] == 50 && a.first[4] < b.first[4]) return true;
      if(a.first[0] == 48 && b.first[0] == 48 && a.first[3] < b.first[3]) return true;
      if(a.first[0] == 48 && b.first[0] == 48 && a.first[3] > b.first[3]) return false;
      if(a.first[0] == 48 && b.first[0] == 48 && a.first[4] < b.first[4]) return true;
      if(a.first[0] == 48 && b.first[0] == 48 && a.first[4] > b.first[4]) return false;
      return a.second.second < b.second.second;
   });
   for(int i = 0;i < vetor.size();i++){
      cout<<vetor[i].second.first<<"\n";
   }

   return 0;
}