#include <bits/stdc++.h>
using namespace std;

int main(){

   map<string,pair<int,bool>>::iterator it;
   map<string,pair<int,bool>> assassinos;
   string ass,mor;
   while(cin>>ass>>mor){
      it = assassinos.find(ass);
      if(it == assassinos.end()){
         assassinos[ass] = {1,true};
      }
      else{
         if(it->second.second){
            assassinos[ass].first++;
         }
      }
      it = assassinos.find(mor);
      assassinos[mor] = {0,false};
   }
   cout<<"HALL OF MURDERERS\n";
   for(it = assassinos.begin();it != assassinos.end();it++){
      if(it->second.second){
         cout<<it->first<<" "<<it->second.first<<"\n";
      }
   }

   return 0;
}