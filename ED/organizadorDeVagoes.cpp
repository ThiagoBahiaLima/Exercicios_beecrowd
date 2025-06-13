#include <bits/stdc++.h>
using namespace std;

int main(){

   vector<int> trem;
   int N;
   cin>>N;
   while(N--){
      int M;
      cin>>M;
      for(int i = 0;i < M;i++){
         int x;
         cin>>x;
         trem.push_back(x);
      }
      int pos = 0;
      int trocas = 0;
      while(pos < M){
         int vagao = 0;
         while(trem[vagao] != pos + 1){
            vagao++;
         }
         while(trem[pos] != pos + 1){
            if(vagao < pos){
               int aux = trem[vagao];
               trem[vagao] = trem[vagao+1];
               trem[vagao+1] = aux;
               vagao++;
               trocas++;
            }
            else{
               int aux = trem[vagao];
               trem[vagao] = trem[vagao-1];
               trem[vagao-1] = aux;
               vagao--;
               trocas++;
            }
         }
         pos++;
      }
      cout<<"Optimal train swapping takes "<<trocas<<" swaps.\n";
      trem.clear();
   }

   return 0;
}