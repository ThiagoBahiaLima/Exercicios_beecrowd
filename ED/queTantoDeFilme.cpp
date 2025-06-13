#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   cin>>N;
   map<int,string> palpite;
   map<int,string> vencedor;
   vector<pair<int,int>> acertos = {{1,0},{2,0},{3,0},{4,0}};
   cin.ignore();
   while(N--){
      string x;
      getline(cin,x);
      for(int i = 1;i <= 4;i++){
         getline(cin,x);
         palpite[i] = x;
      }
      getline(cin,x);
      for(int i = 1;i <= 4;i++){
         getline(cin,x);
         vencedor[i] = x;
         if(vencedor[i] == palpite[i]){
            acertos[i-1].second++;
         }
      }
   }
   for(int i = 0;i < 4;i++){
      pair<int,int> aux = acertos[i];
      for(int j = i + 1;j < 4;j++){
         if(acertos[j].second < aux.second){
            aux = acertos[j];
            acertos[j] = acertos[i];
            acertos[i] = aux;
         }
         else{
            if(acertos[j].second == aux.second && acertos[j].first < aux.first){
               aux = acertos[j];
               acertos[j] = acertos[i];
               acertos[i] = aux;
            }
         }
      }
   }
   bool cond = true;
   for(int i = 0;i < 4;i++){
      if(acertos[i].second == acertos[0].second && cond){
         cout<<acertos[i].first;
         cond = false;
      }
      else{
         if(acertos[i].second == acertos[0].second){
            cout<<" "<<acertos[i].first;
         }
      }
   }

   return 0;
}