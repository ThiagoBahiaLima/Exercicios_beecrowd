#include <bits/stdc++.h>
using namespace std;

int main(){

   map<int,vector<string>> cliente;
   map<int,pair<vector<string>,bool>> servidor;
   int N,M;
   while(cin>>N>>M && N != 0 && M != 0){
      for(int i = 1;i <=N;i++){
         int x;
         cin>>x;
         for(int j = 0;j < x;j++){
            string y;
            cin>>y;
            servidor[i].first.push_back(y);
            servidor[i].second = true;
         }
      }
      for(int i = 1;i <=M;i++){
         int x;
         cin>>x;
         for(int j = 0;j < x;j++){
            string y;
            cin>>y;
            cliente[i].push_back(y);
         }
      }
      int ligacoes = 0;
      for(int i = 1;i <= M;i++){
         for(int j = 0;j < cliente[i].size();j++){
            for(int a = 1;a <= N;a++){
               bool achou = false;
               for(int b = 0;b < servidor[a].first.size() && !achou && servidor[a].second;b++){
                  if(cliente[i][j] == servidor[a].first[b]){
                     ligacoes++;
                     achou = true;
                     servidor[a].second = false;
                  }
               }
            }
         }
         for(int j = 1;j <= N;j++){
            servidor[j].second = true;
         }
      }
      cout<<ligacoes<<"\n";
      servidor.clear();
      cliente.clear();
   }

   return 0;
}