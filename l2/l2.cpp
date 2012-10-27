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


int sg(int x){ return x>0; }

long int fact(int n){
  if (!n) return 1;
  else return mul(n,fact(n-1));
}

long int Pi (long int x, long int y, long int z){
  return !sg(fplus(x%(y-z), y%(y-z)));
}

long int d (long int x, long int y){
  
  long int z=0;
  while (!Pi(x, y, z) && z<y) z++;
  return z;
}
// [x/y]
long int e (long int x, long int d){
  long int z=0;
  while(z < x+1 && !sg( (z+1)*d-x ) ) z++;
  return z;
}
// x % y
long int g (long int x, long int d){
  
  return (x-e(x,d)*d)*sg(x-d+1);
}

long int f( int n){
  if(!n) return 0;
  return mul(f(n-1),n)+fact(n-1);
}

long int F (int n){
  
  return 
        e(
            f(n), 
            fact(n)-d( 
                      f(n), 
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
    
    cout <<F(n)<< endl;
}

