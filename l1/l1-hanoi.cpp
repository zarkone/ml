// ./l1-2 < l1-2.input > l1-2.out && cat l1-2.out

#include <iostream>
#include <sstream>
using namespace std;

void  hanoi(int a, int b, int c, int n) {
  if(!n) return;
  hanoi(a,c,b,n-1);
  cout  << "Переложить с " 
        << a << " на "
        << c <<  endl;
  hanoi(b,a,c,n-1);      

}
int main(int argc, char *argv[]){
  stringstream arg;
  int n;
  arg << argv[1];
  arg >> n;

  hanoi(1, 2, 3, n);
}