#include <bits/stdc++.h>
using namespace std;

int main(){

   vector<pair<string,pair<char,int>>> locais;
   int N;
   while(cin>>N){
      while(N--){   
         string x;
         char y;
         int z;
         cin>>x>>y>>z;
         locais.push_back({x,{y,z}});
      }
      sort(locais.begin(),locais.end(),[](pair<string,pair<char,int>> a,pair<string,pair<char,int>> b){
         if(a.second.second < b.second.second) return true;
         if(a.second.second > b.second.second) return false;
         if(a.second.first < b.second.first) return true;
         if(a.second.first > b.second.first) return false;
         return a.first < b.first;
      });
      for(int i = 0;i < locais.size();i++){
         cout<<locais[i].first<<"\n";
      }
      locais.clear();   
   }

   return 0;
}