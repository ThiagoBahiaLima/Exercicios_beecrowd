#include <bits/stdc++.h>
using namespace std;

int main(){

   map<int,vector<pair<string,float>>,greater<>>::iterator it;
   map<int,vector<pair<string,float>>,greater<>> lista;
   string nome;
   int presentes;
   while(cin>>nome>>presentes){
      cin.ignore();
      for(int i = 0;i < presentes;i++){
         string x;
         float y;
         int z;
         getline(cin,x);
         cin>>y>>z;
         cin.ignore();
         lista[z].push_back({x,y});
      }
      for(it = lista.begin();it != lista.end();it++){
         sort(it->second.begin(),it->second.end(),[](pair<string,float> a,pair<string,float> b){
            if(a.second < b.second) return true;
            if(a.second > b.second) return false;
            return a.first < b.first;
         });
      }
      cout<<"Lista de "<<nome<<"\n";
      for(it = lista.begin();it != lista.end();it++){
         for(int i = 0;i < it->second.size();i++){
            cout<<fixed<<setprecision(2);
            cout<<it->second[i].first<<" - R$"<<it->second[i].second<<"\n";
         }
      }
      cout<<"\n";
      lista.clear();
   }

   return 0;
}