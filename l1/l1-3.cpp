// ./l1-3 010010 > l1-3.out && cat l1-3.out

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

void rec(string *s, int r) {
  if(r == -1) return;

  rec(s,r-1); 
  (*s).replace(r, 1,(*s)[r] == '1' ? "0" : "1");
  cout << *s <<  endl;
  rec(s, r-1);
}
int main(int argc, char *argv[]){
 stringstream arg;
 string s;
 int r;

 arg << argv[1];
 arg >> s;
 r = s.length()-1;

 cout << s << endl;
 rec(&s,r);



}