// ./l1-3 010010 > l1-3.out && cat l1-3.out

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;


int rec(int n) {
  if(n == 1 || n == 0) return 1;

  return rec(n - 2) + rec(n - 1);
}
int notRec(int n){
  int r1=1;
  int r2=1;
  int temp=1;
  
  for (int i = 1 ; i < n ; ++i) {
    temp = r1;
    r1 = r2;
    r2 += temp;
    cout << r2 << " "<<r1 << " " << temp << endl;
  }

  return r2;   
}

int main(int argc, char *argv[]){

 stringstream arg;
 int  n;

 arg << argv[1];
 arg >> n;

 cout << "Количество вариантов расположения: " << notRec(n) << endl;
 
}  