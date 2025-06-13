#include <bits/stdc++.h>
using namespace std;

int main(){

   int a,b,val = 1;
   cin>>a>>b;
   vector<int> vetor;
   for(int i = 0;i < a;i++){
      vetor.push_back(0);
   }
   pair<int,int> c;
   for(int i = 0;i < b;i++){
      cin>>c.first>>c.second;
      if(vetor[c.first-1] == 0 && vetor[c.second-1] == 0){
         vetor[c.first-1] = val;
         vetor[c.second-1] = val;
         val++;
      }
      else{
         if((vetor[c.first-1] < vetor[c.second-1] || vetor[c.second-1] == 0) && vetor[c.first-1] != 0){
            int m = vetor[c.second-1];
            for(int j = 0;j < a;j++){
               if(vetor[j] == m){
                  vetor[j] = vetor[c.first-1];
               }
            }
         }
         else{
            int m = vetor[c.first-1];
            for(int j = 0;j < a;j++){
               if(vetor[j] == m){
                  vetor[j] = vetor[c.second-1];
               }
            }
         }
      }
   }
   int seila = 0;
   for(int i = 0;i < a;i++){
      if(vetor[i] != 1){
         seila++;
      }
   }
   if(seila == 0){
      cout<<"COMPLETO"<<"\n";
   }
   else{
      cout<<"INCOMPLETO"<<"\n";
   }


   return 0;
}