#include "string_maker.h"
using namespace std;

int main(){
  StringMaker sb1("=");
  sb1 * 2;
  sb1 * 2;
  cout << sb1 << endl;

  StringMaker sb2("=");
  sb1 + (sb2 * 4).str();
  cout << sb1 << sb2 << endl;

  (sb1 - 4) * 3 * 2;
  cout << sb1 << endl;

  sb2.clear();

  if(sb1 != sb2){
    cout << "\t1 != 2" << endl;
  }

  sb2 + sb1.str();
  if(sb1 == sb2){
    cout << "\t1 == 2" << endl;
  }

  sb1 - sb1.size();
  " Welcome to CS 1410" >> sb1;
  cout << sb1 << endl;

  cout << sb2 << endl;
  sb2 - (sb2.size() / 2);

  StringMaker sb3(sb2);
  cout << sb3.str() << endl;

  sb3 - 7;
  cout << sb3 << endl;

  return 0;
}