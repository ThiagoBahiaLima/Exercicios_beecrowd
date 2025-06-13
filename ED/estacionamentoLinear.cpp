#include <bits/stdc++.h>
using namespace std;

int main(){

   int N,K;
   vector<pair<int,int>> carros;
   while(cin>>N>>K && N != 0 && K != 0){
      bool superlotou = false;
      bool bloqueou = false;
      while(N--){
         int x,y;
         cin>>x>>y;
         if(carros.size() == 0){
            carros.push_back({x,y});
         }
         else{
            if(x >= carros[carros.size() - 1].second){
               bool vaisair = true;
               for(int i = carros.size() - 1;i >= 1  && !bloqueou;i--){
                  if(carros[i].second > carros[i-1].second){
                     bloqueou = true;
                  }
               }
               for(int i = carros.size() - 1;i >= 0 && vaisair;i--){
                  if(carros[i].second <= x){
                     carros.pop_back();
                  }
                  else{
                     vaisair = false;
                  }
               }
               carros.push_back({x,y});   
            }
            else{
               carros.push_back({x,y});
            }
         }
         if(carros.size() > K){
            superlotou = true;
         }
      }
      for(int i = carros.size() - 1;i >= 1  && !bloqueou;i--){
         if(carros[i].second > carros[i-1].second){
            bloqueou = true;
         }
      }
      if(bloqueou || superlotou){
         cout<<"Nao\n";
      }
      else{
         cout<<"Sim\n";
      }
      carros.clear();
   }

   return 0;
}