#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   map<string,string>::iterator it;
   map<string,string> traducoes;
   cin>>N;
   while(N--){
      string x,y;
      cin>>x;
      cin.ignore();
      getline(cin,y);
      traducoes[x] = y;
   }
   cin>>N;
   cin.ignore();
   while(N--){
      string x,y;
      getline(cin,x);
      cin>>y;
      cin.ignore();
      it = traducoes.find(y);
      cout<<x<<"\n"<<it->second<<"\n\n";
   }

   return 0;
}