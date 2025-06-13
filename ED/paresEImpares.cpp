#include <bits/stdc++.h>
using namespace std;

int main(){

   vector<int> numeros;
   int pares = 0;
   int N;
   cin>>N;
   for(int i = 0;i < N;i++){
      int x;
      cin>>x;
      numeros.push_back(x);
      if(x%2 == 0){
         pares++;
      }
   }
   sort(numeros.begin(),numeros.end(),[](int a,int b){
      if ((a % 2 == 0) && (b % 2 != 0)) return true;
      if ((a % 2 != 0) && (b % 2 == 0)) return false;
      return a < b;
   });
   sort(numeros.begin() + pares,numeros.end(),greater<>());
   for(int i = 0;i < numeros.size();i++){
      cout<<numeros[i]<<"\n";
   }

   return 0;
}