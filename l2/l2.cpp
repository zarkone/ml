#include <iostream>
#include <sstream>
using namespace std;

long int fplus(long int x, long int y){
  if(!y) return x;
  return fplus(x, y-1)+1;
}
long int mul(long int x, long int y){
  if(!y) return 0;
  return fplus(mul(x,y-1), x);
}

long int uminus(long int x, long int y){
  if(!x) return 0;
  if(!y) return x;
  
  return uminus(x-1, y-1);
}

int sg(int x){ return uminus(x,0); }

long int fact(int n){
  if (!n) return 1;
  else return mul(n,fact(n-1));
}

long int min (long int x, long int y){
  if (uminus(x,y)) return y;
  else return x;
}

long int ost (long int x, long int d){
  if(x == d) return 0;
  if(uminus(x,d) == 0) return x;
  if(uminus(d,x) == 0) return ost(uminus(x,d), d);
}

//
long int Pi (long int x, long int y, long int z){
  return !(ost(x,z) || ost(y,z));
}

long int d (long int x, long int y){
  
  long int z=min(x,y);
  while (!Pi(x, y, z) && uminus(z,0)) z--;
  return z;
}

long int e (long int x, long int d){
  long int z=0;
  while( uminus(x, mul(z,d)) ) z++;
  return z;
}

long int f (long int ch, long int zn, int n){
  if(!n)
    return ch;
  return  f(fplus(mul(ch,n),zn), mul(zn,n), n-1) ;  
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

