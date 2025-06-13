#include <bits/stdc++.h>
using namespace std;

int main(){

   stack<char> molejo;
   queue<char> trem;
   vector<char> reorg;
   int N;
   while(cin>>N && N != 0){
      molejo.push('A');
      for(int i = 0;i < N;i++){
         char x;
         cin>>x;
         trem.push(x);
      }
      trem.push('A');
      for(int i = 0;i < N;i++){
         char x;
         cin>>x;
         reorg.push_back(x);
      }
      int i = 0;
      bool entrando = true;
      while(i <= N && entrando){
         if(trem.front() == reorg[i]){
            trem.pop();
            i++;
            cout<<"IR";
         }
         else{
            if(molejo.top() == reorg[i]){
               molejo.pop();
               i++;
               cout<<"R";
            }
            else{
               if(trem.front() != reorg[i] && trem.front() != 'A'){
                  molejo.push(trem.front());
                  trem.pop();
                  cout<<"I";
               }
               else{
                  entrando = false;
               }
            }
         }
      }
      molejo.pop();
      if(!molejo.empty()){
         cout<<" Impossible";
      }
      cout<<"\n";
      reorg.clear();
      while(!trem.empty()){
         trem.pop();
      }
      while(!molejo.empty()){
         molejo.pop();
      }
   }

   return 0;
}