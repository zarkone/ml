// ./l1-3 010010 > l1-3.out && cat l1-3.out

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#define  pair_vector vector < pair<long int, string> >
using namespace std;

pair_vector phBook;

int search(int start, int end, string needle) {

  if(phBook[start].second.compare(needle) == 0)  
    return start;
  if(start == end)  return -1; 

  int half = (start+end)/2 + 1;
  if(needle.compare(phBook[half].second) < 0)
    return search(start, half-1, needle);

  return search(half,end,needle);
}

int main(int argc, char *argv[]){

 stringstream arg;
 string needle;
 pair<long int, string> tempPair;
 int end=0;

  while(!cin.eof() && ++end){
    cin >> tempPair.first >> tempPair.second;
   // cout << tempPair.first << tempPair.second << endl;
    phBook.push_back(tempPair);
  }
 if (end) end--;
 
 arg << argv[1];
 arg >> needle;

 cout << "Номер телефона: " << search(0, end, needle) << endl;
 
}