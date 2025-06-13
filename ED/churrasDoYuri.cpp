#include <bits/stdc++.h>
using namespace std;

int main(){

   int z;
   while(cin>>z){
      map<int,string>::iterator it;
      map<int,string> churras;
      int y;
      string x;
      for(int i = 0;i < z;i++){
         cin>>x>>y;
         churras[y] = x;
      }
      for(it = churras.begin();it != --churras.end();it++){
         cout<<it->second<<" ";
      }
      cout<<it->second;
      cout<<"\n";
   }

   return 0;
}