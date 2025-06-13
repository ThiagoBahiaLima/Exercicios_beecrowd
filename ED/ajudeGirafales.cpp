#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   while(cin>>N && N != 0){
      map<string,string>::iterator it;
      map<string,string> nome_assinatura;
      string x,y;
      for(int i = 0;i < N;i++){
         cin>>x>>y;
         nome_assinatura[x] = y;
      }
      cin>>N;
      pair<string,string> presentes;
      int val = 0,falsos = 0;
      for(int i = 0;i < N;i++){
         cin>>presentes.first>>presentes.second;
         for(int i = 0;i < presentes.second.size();i++){
            if(nome_assinatura[presentes.first][i] != presentes.second[i]){
               val++;
            }
         }
         if(val > 1){
            falsos++;
         }
         val = 0;
      }
      cout<<falsos<<"\n";
      nome_assinatura.clear();
   }

   return 0;
}