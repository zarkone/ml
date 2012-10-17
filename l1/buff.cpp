#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

 int i=0;
 char a[12] = "aaaaaaaaaa";
 char t ;
 long int num =0;
 
  while(i++ < 10){
    t = 'b';
    if(i != 10) a[i+1] = 'a';
    while (t != 'z') {
      a[i] = t++;
      cout << num << " ";
      cout << a;
      cout << endl;
      num++;
    }
    
  }
 

}