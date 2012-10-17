#include <iostream>
using namespace std;

int  myPow(int a, unsigned int n) {
  
  if(!n) return 1;

  int p = myPow(a, n/2);
  p*=p;

  return (n%2 != 0) ? p*a : p;

}

int main(int argc, char *argv[]){
  
 cout << myPow(2,12)<< endl;

}