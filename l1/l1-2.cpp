// ./l1-2 < l1-2.input > l1-2.out && cat l1-2.out

#include <iostream>
using namespace std;

int  rec(int a) {
  if(a  == 123) return 0;
  if(a < 10) return a;
  if(a % 1000 == 123)
    return rec(a / 1000);
  return  rec(a /10)*10 + (a % 10);
}
int main(int argc, char *argv[]){
 int in;
 cin >> in; 
 cout << rec(in)<< endl;

}