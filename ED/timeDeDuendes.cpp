#include <bits/stdc++.h>
using namespace std;

int main(){

   map<int,vector<string>>::iterator it;
   map<int,vector<string>,greater<>> duendes;
   map<int,vector<pair<string,int>>> times;
   int N;
   cin>>N;
   for(int i = 0;i < N;i++){
      string y;
      int x;
      cin>>y>>x;
      duendes[x].push_back(y);
   }
   for(it = duendes.begin();it != duendes.end();it++){
      sort(it->second.begin(),it->second.end());
   }
   int time = 1;
   for(it = duendes.begin();it != duendes.end();it++){
      for(int i = 0;i < it->second.size();i++){
         times[time].push_back({it->second[i],it->first});
         time++;
         if(time > N/3){
            time = 1;
         }
      }
   }
   for(int i = 1;i <= N/3;i++){
      cout<<"Time "<<i<<"\n";
      for(int j = 0;j < 3;j++){
         cout<<times[i][j].first<<" "<<times[i][j].second<<"\n";
      }
      cout<<"\n";
   }


   return 0;
}