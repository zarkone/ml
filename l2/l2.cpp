#include <iostream>
using namespace std;

int NOD(int a,int b)
{
  while(a!=0 && b!=0)
    {
       if(a>=b) a=a%b;
           else b=b%a;
    }
  return a+b; 
}

int HnCh(int ch, int zn, int n){
  if (n == 0) { 
   int nod = NOD(ch, zn);
   ch /= nod;
   // zn /= nod;

   return ch; 
 }
  
  ch = ch*n + zn;
  zn *= n;
  n--;

  return HnCh(ch,zn,n);

}
int Hn(int n){
  if(!n) return 0;

  return add(fact(n), mul(Hn(n-1), n))
}


int main()
{
    int x; 
    // scanf("%d",&x);
    // unsigned long int z=p(x);
    // printf("простое число с номером %d равно %ld\n",x,z);
    
    cout << HnCh(1,4, 3);
}

