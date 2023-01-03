#include "bigint.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "\033[1;41m----Missing an argument----\033[0m" << endl;
    cout << "Usage: ./decipher <file>" << endl;
    cout << "Examples:" << endl;
    cout << "\t./decipher secret/message1.txt \033[1;90m//to decipher message "
            "1\033[0m"
         << endl;
    cout << "\t./decipher secret/message2.txt \033[1;90m//to decipher message "
            "2\033[0m"
         << endl;
    return -1;
  }

  /************* You complete *************/
  ifstream ifile(argv[1]);
  if (ifile.fail()) {
    cout << "\033[1;31mError:\033[0m Unable to open file (" << argv[1] << ")"
         << endl;
    return -1;
  }
  int base;
  string d, n, secret;
  // Get 1st line to get base, d, n for our message
  ifile >> base >> d >> n;
  // cout << "base =" << base << " d =" << d << " n=" << n << endl;
  // Process messages one by one
  while (ifile >> secret) {
    try {
      BigInt d_big(d, base);
      BigInt n_big(n, base);
      BigInt secret_big(secret, base);
      BigInt result = modPow(secret_big, d_big, n_big);

      // cout << result.to_int() << endl;
      char r = result.to_int();
      cout << r;
    } catch (const exception &e) {
      cout << e.what() << endl;
      return -1;
    }
  }
  cout << endl;
  return 0;
}
