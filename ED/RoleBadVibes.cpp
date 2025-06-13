#include <bits/stdc++.h>
using namespace std;

int main(){

   int N,M;
   cin>>N>>M;
   vector<string> oxi;
   for(int i = 0;i < N*M;i++){
      string x;
      cin>>x;
      oxi.push_back(x);
   }
   for(int i = 0;i < N*M;i++){
      string aux = oxi[i];
      for(int j = i + 1;j < N*M;j++){
         if(oxi[j][1] > aux[1]){
            aux = oxi[j];
            oxi[j] = oxi[i];
            oxi[i] = aux;
         }
         if(oxi[j][1] == aux[1] && oxi[j][0] > aux[0]){
            aux = oxi[j];
            oxi[j] = oxi[i];
            oxi[i] = aux;
         }

      }
   }
   for(int i = 0;i < N*M;i++){
      cout<<oxi[i]<<"\n";
   }

   return 0;
}