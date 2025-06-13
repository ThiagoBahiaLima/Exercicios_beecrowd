#include <bits/stdc++.h>
using namespace std;

int main(){

   map<string,string>::iterator it;
   map<string,string> linguas;
   linguas["brasil"] = "Feliz Natal!";
   linguas["alemanha"] = "Frohliche Weihnachten!";
   linguas["austria"] = "Frohe Weihnacht!";
   linguas["coreia"] = "Chuk Sung Tan!";
   linguas["espanha"] = "Feliz Navidad!";
   linguas["grecia"] = "Kala Christougena!";
   linguas["estados-unidos"] = "Merry Christmas!";
   linguas["inglaterra"] = "Merry Christmas!";
   linguas["australia"] = "Merry Christmas!";
   linguas["portugal"] = "Feliz Natal!";
   linguas["suecia"] = "God Jul!";
   linguas["turquia"] = "Mutlu Noeller";
   linguas["argentina"] = "Feliz Navidad!";
   linguas["chile"] = "Feliz Navidad!";
   linguas["mexico"] = "Feliz Navidad!";
   linguas["antardida"] = "Merry Christmas!";
   linguas["canada"] = "Merry Christmas!";
   linguas["irlanda"] = "Nollaig Shona Dhuit!";
   linguas["belgica"] = "Zalig Kerstfeest!";
   linguas["italia"] = "Buon Natale!";
   linguas["libia"] = "Buon Natale!";
   linguas["siria"] = "Milad Mubarak!";
   linguas["marrocos"] = "Milad Mubarak!";
   linguas["japao"] = "Merii Kurisumasu!";

   string x;
   while(cin>>x){
      it = linguas.find(x);
      if(it != linguas.end()){
         cout<<it->second<<"\n";
      }
      else{
         cout<<"--- NOTFOUND ---\n";
      }
   }

   return 0;
}