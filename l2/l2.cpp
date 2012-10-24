#include <iostream>
#include <sstream>
using namespace std;

int sg(int x){ return x>0; }
long int fact(int n){
  if (!n) return 1;
  else return n*fact(n-1);
}

long int min (long int x, long int y){
  if (x > y) return y;
  else return x;
}

long int Pi (long int x, long int y, long int z){
  return !(x % z || y % z);
}

long int d (long int x, long int y){
  
  long int z=min(x,y);
  while (!Pi(x, y, z) && z>0) z--;
  return z;
}

long int e (long int x, long int d){
  long int z=0;
  while(z*d < x) z++;
  return z;
}

long int f (long int ch, long int zn, int n){
  if(!n)
    return ch;
  return  f(ch*n+zn, zn*n, n-1) ;  
}

long int F (int n){
  return 
        e(
            f(1, n, n-1), 
            d( 
              f(1, n, n-1), 
              fact(n) 
            ) 
        );
}

int main(int argc, char *argv[])
{
    stringstream arg;
    int  n;

    arg << argv[1];
    arg >> n; 
    
    cout << F(n)<< endl;

}

