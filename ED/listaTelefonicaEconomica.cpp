#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   while(cin>>N){
      vector<string> numeros;
      for(int i = 0;i < N;i++){
         string x;
         cin>>x;
         numeros.push_back(x);
      }
      sort(numeros.begin(),numeros.end());
      int economia = 0;
      for(int i = 1;i < N;i++){
         bool economizando = true;
         for(int j = 0;j < numeros[i].size() && economizando;j++){
            if(numeros[i][j] == numeros[i-1][j]){
               economia++;
            }
            else{
               economizando = false;
            }
         }
      }
      cout<<economia<<"\n";
   }

   return 0;
}