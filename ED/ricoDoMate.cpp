#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   float G,C;
   vector<string> nomes;
   cin>>N>>G>>C;
   for(int i = 0;i < N;i++){
      string x;
      cin>>x;
      nomes.push_back(x);
   }
   float m;
   int i = 0;
   while(G > 0.09){
      m = G;
      G = G - C;
      i++;
      if(i == N){
         i = 0;
      }
   }
   i--;
   if(i == -1){
      i = nomes.size() - 1;
   }
   cout<<fixed<<setprecision(1);
   cout<<nomes[i]<<" "<<m<<"\n";

   return 0;
}