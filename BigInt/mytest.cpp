#include "bigint.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  BigInt zero = BigInt("0", 10);
  BigInt two = BigInt(2, 10);
  BigInt n = BigInt(2, 10);

  if (n.compare(two) == 0) {
    cout << "N " << n.to_string() << " and Two " << two.to_string() << " match "
         << endl;
  } else {
    cout << "N " << n.to_string() << " and Two " << two.to_string()
         << "DO NOT match " << endl;
  }
  BigInt m = n % two;
  if (zero.compare(m) == 0) {
    cout << "M " << m.to_string() << " and Zero " << zero.to_string()
         << " match " << endl;
  } else {
    cout << "M " << m.to_string() << " and Zero " << zero.to_string()
         << " DONOT match " << endl;
  }

  return 0;
}
