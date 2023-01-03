#include "bigint.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  // Add your own code
  // You may comment out the example code snippets below

  // First example
  /*
      BigInt mytestX("-DADCAFE", 16);
      cout<<mytestX.to_string()<<endl;//should print -DADCAFE
      BigInt mytest("DADCAFE", 16);
      cout<<mytest.to_string()<<endl;//should print DADCAFE
      BigInt mytest2("1010",2);
      cout<<mytest2.to_string()<<endl;//should print 1010
      BigInt mytest2a(6,2);
      cout<<mytest2a.to_string()<<endl;//should print 110
      BigInt mytest2b(154,16);
      cout<<mytest2b.to_string()<<endl;//should print 9A
      BigInt mytest2c(-154,16);
      cout<<mytest2c.to_string()<<endl;//should print -9A
      BigInt mytest3("1010",2);
      cout<<mytest3.to_string()<<endl;//should print 1010
      cout<<mytest3.to_int()<<endl;//should print 10
      BigInt mytest3a("-1010",2);
      cout<<mytest3a.to_string()<<endl;//should print 1010
      cout<<mytest3a.to_int()<<endl;//should print 10

      BigInt mytest3b = mytest3a;
      cout<<mytest3b.to_string()<<endl;//should print 1010
      cout<<mytest3b.to_int()<<endl;//should print 10

          mytest3b = mytestX;
      cout<<mytest3b.to_string()<<endl;//should print -DADCAFE
      cout<<mytest3b.to_int()<<endl;//should print -229493502
  */

  // Second example
  // BigInt first("DADCAFE", 16);
  // BigInt second("BEEF", 16);
  // BigInt first("1260257", 10);
  // BigInt second("37", 10);
  BigInt first("40", 10);
  BigInt second("2", 10);

  int c = first.compare(second);
  cout << "Comparing first and second " << c << endl;

  // c = mytestX.compare(first);
  // cout << "Comparing mytestX and first " << c << endl;

  // c = mytestX.compare(mytest2c);
  // cout << "Comparing mytestX and mytest2c " << c << endl;

  BigInt sum = first / second;
  cout << first.to_string() << " / " << second.to_string() << " = "
       << sum.to_string() << endl; // should print DAE89ED
  // cout<<boolalpha<<(first >= second)<<endl;//should print true
  // cout<<first.to_string()<<endl;//should print DAE89ED

  // Third example
  BigInt var1(496, 10);
  BigInt var2(249, 10);
  BigInt var3(1189, 10);
  /*
      BigInt var4 = modPow(var1,var2,var3);
      cout<<var4.to_int()<<endl;//should print 72
      cout<<(char)var4.to_int()<<endl;//should print "H"
  */

  return 0;
}
