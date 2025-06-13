#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

vector<bool> vis;

void funcaoFoda(vector<vector<int>> &A,int pos){
   vis[pos] = true;
   for(int i = 0;i < A[pos].size();i++){
      if(!vis[A[pos][i]]){
         funcaoFoda(A,A[pos][i]);
      }
   }
}

int main(){

   int casos;
   cin>>casos;
   while(casos--){
      char maior;
      cin>>maior;
      for(int i = 0;i < maior - 'A'  + 1;i++){
         vis.push_back(false);
      }
      cin.ignore();
      vector<vector<int>> seila(maior - 'A'  + 1);
      string conexoes;
      while(getline(cin,conexoes) && !conexoes.empty()){
         seila[conexoes[0] - 'A'].push_back(conexoes[1] - 'A');
         seila[conexoes[1] - 'A'].push_back(conexoes[0] - 'A');
      }
      int maximos = 0;
      for(int i = 0;i < maior - 'A' + 1;i++){
         if(!vis[i]){
            funcaoFoda(seila,i);
            maximos++;
         }
      }
      cout<<maximos<<"\n";
      if(casos != 0){
         cout<<"\n";
      }
      vis.clear();
   }

   return 0;
}