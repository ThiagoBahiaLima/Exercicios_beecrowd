#include <iostream>
#include <vector>
using namespace std;

vector<bool> vis;

void verificadorDeConexoes(vector<vector<int>> &A,int pos){
   vis[pos] = true;
   for(int i = 0;i < A[pos].size();i++){
      if(!vis[A[pos][i]]){
         verificadorDeConexoes(A,A[pos][i]);
      }
   }
}

int main(){

   int n,m;
   cin>>n>>m;
   vector<vector<int>> conexoes(n);
   for(int i = 0;i < m;i++){
      int x,y;
      cin>>x>>y;
      conexoes[x-1].push_back(y-1);
      conexoes[y-1].push_back(x-1);
   }
   for(int i = 0;i < n;i++){
      vis.push_back(false);
   }
   vector<int> deadEnds;
   int cont = 0;
   for(int i = 0;i < n;i++){
      if(!vis[i]){
         verificadorDeConexoes(conexoes,i);
         deadEnds.push_back(i+1);
         cont++;
      }
   }
   cout<<cont - 1<<"\n";
   for(int i = 0;i < deadEnds.size() - 1;i++){
      cout<<deadEnds[i]<<" "<<deadEnds[i+1]<<"\n";
   }


   return 0;
}