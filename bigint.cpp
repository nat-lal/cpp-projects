#include "bigint.h"
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <sstream>
using namespace std;

//******************************************************************
//START OF THE CONSTRUCTORS SECTION
//******************************************************************

/*
// Create a default BigInt with base 10.
// This function is complete. You do not have to add anything.
*/
BigInt::BigInt(){
  base = 10;
  isPositive = true;
}

/*
// Create a BigInt with a specified base.
// This function is complete. You do not have to add anything.
*/
BigInt::BigInt(int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    base = setbase;
    isPositive = true;
}

/*
// Destructure. You do not have to add anything.
// This function is complete
*/
BigInt::~BigInt(){}

/*
//  Create a BigInt from int (base 10).
//  - Convert the int (base 10) input into a specified base (setbase).
//  - Don't forget to set the base accordingly
//  For example:
//     BigInt k(6,2) <- int 6 base 10 to BigInt base 2
//          - Result:  BigInt k with value 110 (base 2)
//     BigInt k(154,16) <- 154 base 10 to BigInt base 16
//          - Result: BigInt k with value 9A (base 16)
*/
BigInt::BigInt(int input,int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    /************* You complete *************/
  	base = setbase;
	if ( input < 0 )
		isPositive = false;
	else
		isPositive = true;
	int i = abs(input);
	while (i > 0) {
		vec.push_back(i % base);
		i /= base;
	}
}

/*
//  Create a BigInt from string.
//  Don't forget to set the base accordingly
//  The input string will contain
//      - numbers (0-9) and/or 
//      - uppercase letters (A-Z) [A=10, B=11, ... , Z=35]
//  The input string may contain
//      - a negative sign ('-') to signify that the number is negative.
//  Note: char '0' = int 48 (see ASCII table)
//  Note: char 'A' = int 65
*/
BigInt::BigInt(const string &s, int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    /************* You complete *************/
  	base = setbase;
	int b;
	if (s[0] == '-') {
  		isPositive = false;
		b = 1;
	} else {
  		isPositive = true;
		b = 0;
	}

	for(int i = s.size()-1; i >= b; i--) {
		if (s[i] <= '9') {
			//cout << s[i] - '0' << endl;
			vec.push_back(s[i] - '0');
		}
		else if (s[i] >= 'A')
			vec.push_back(s[i] - 'A' + 10);
	}
  
}

/*
//  Create a BigInt from another BigInt.
//  This is a copy constructor.
//  Simply call the assignment operator (=) below.
*/
BigInt::BigInt(const BigInt &b){

    /************* You complete *************/
	vec = b.vec;
	base = b.base;
	isPositive = b.isPositive;
}

/*
//  Assignment operator. (i.e., BigInt a = b;)
//  Overriding a's data with BigInt b's data
//       - vec
//       - isPositive
//       - base
*/
BigInt & BigInt::operator = (const BigInt &b){

    /************* You complete *************/
	vec = b.vec;
	base = b.base;
	isPositive = b.isPositive;

    return *this;
}


//******************************************************************
//END OF THE CONSTRUCTORS SECTION
//******************************************************************

//******************************************************************
//START OF THE DISPLAYS SECTION
//******************************************************************

/*
// Convert to string and return the string
// Display it in its corresponding base
//  Note: char '0' = int 48 (see the ASCII table)
//  Note: char 'A' = int 65
*/
string BigInt::to_string(){

    /************* You complete *************/
	stringstream ss;
	if (!isPositive) 
		ss << "-";
	for (int i=vec.size()-1;  i >= 0 ; i--) {
		char c;
		if (vec.at(i) <= 9) 
			c = vec.at(i) + '0';
		else
			c = vec.at(i) - 10 + 'A';
		ss << c;
	}
	string s = ss.str();
	if (s.empty()) {
		s ="0";
	}

  return s;
}

/*
//  Convert BigInt to integer base 10 and return that int
//    If BigInt >= INT_MAX, return INT_MAX.
//    If BigInt =< INT_MIN, return INT_MIN.
//  Note: 1. INT_MAX and INT_MIN are already defined for you
//           in the 'climits' library.
//        2. INT_MAX = 2147483647, INT_MIN = -2147483648
//           therefore, INT_MIN does not equal to (-INT_MAX)
*/
int BigInt::to_int() const{

    /************* You complete *************/
	int v=0;
	for (long unsigned int i=0;  i < vec.size() ; i++) {
		v += vec.at(i) * pow(base,i);
	}
	if (!isPositive)
		v = -v;

	if (v >= INT_MAX ) {
		if (!isPositive) 
			v = INT_MIN;
	} else if ( v <= INT_MIN ) {
		if (isPositive)
			v = INT_MAX;
	}
  return v;//for now
}

//******************************************************************
//END OF THE DISPLAYS SECTION
//******************************************************************

//******************************************************************
//START OF THE EQUALITY CHECK OPERATORS SECTION
//******************************************************************

/*
//  Compare a and b.
//     If a = b, return 0.
//     If a < b, return -1.
//     If a > b, return 1.
//  See the HINT below
*/
int BigInt::compare(const BigInt &b) const{
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/

    //HINT:
    //1. do NOT call the to_int() or to_string() function
    //2. do NOT convert bigInt to other datatypes first (e.g., long long, int)
    
    //First let's compare the signs
    //    - if the signs aren't the same,
    //              how do you know which one is larger?

    //If they have the same sign, let's compare their vec sizes 
    //    - what if both are positive, but a's vec is larger (a or b is larger?)
    //    - other cases?
    
    //If they have the same vec size, let's compare their digits one by one
    // Starting from the most-significant digits. --> in what vector position?
    // Remember that the BigInt vectors are in reverse order!
    //    - what if both are positive, but the digit of a is greater than that of b (a or b is larger?)
    //    - other cases?
    
    //If ALL digits are the same, then they MUST be equal!!
	
	// Different signs case check
	if (isPositive != b.isPositive) {
		if (isPositive)
			return 1;
		else
			return -1;
	}

/* beginning add */
	//Strip off leading zeros
	BigInt q = *this;
	BigInt r = b;
	for (int i = q.vec.size()-1; i >= 0; i--) {
		if (q.vec[i] == 0) {
			q.vec.pop_back();
		} else {
			break;
		}
	}
	for (int i = r.vec.size()-1; i >= 0; i--) {
		if (r.vec[i] == 0) {
			r.vec.pop_back();
		} else {
			break;
		}
	}
	if (q.vec.size() > r.vec.size() ) {
		if (isPositive) {
			return 1;
		} else {
			return -1;
		}
	}
	if (q.vec.size() < r.vec.size() ) {
		if (isPositive) {
			return -1;
		} else {
			return 1;
		}
	}
/* ending add */

	// If we have come this far, means signs are the same
	// Let's compare sizes of vectors
	if (vec.size() > b.vec.size() ) {
		if (isPositive) {
			return 1;
		} else {
			return -1;
		}
	}
	if (vec.size() < b.vec.size() ) {
		if (isPositive) {
			return -1;
		} else {
			return 1;
		}
	}

	// If we have come this far, means both sings and sizes 
	// of the vectors are the same
	// Need to compare one by one
	for (int i=vec.size()-1;  i >= 0 ; i--) {
		if (vec.at(i) == b.vec.at(i)) {
			continue;
		}
		if (vec.at(i) > b.vec.at(i) ) {
			if (isPositive) {
				return 1;
			} else {
				return -1;
			}
		} else if (vec.at(i) < b.vec.at(i) ) {
			if (isPositive) {
				return -1;
			} else {
				return 1;
			}
		}
	}
	
	// If we have come here, then numbers are the same
    return 0;
}

//Call the compare function above to check if a == b
bool operator == (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if (a.compare(b) == 0)
		return true;
	else
  		return false;//for now
}

//Call the compare function above to check if a != b
bool operator != (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if (a.compare(b) != 0)
		return true;
	else
  		return false;//for now
}

//Call the compare function above to check if a <= b
bool operator <= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if (a.compare(b) != 1)
		return true;
	else
  		return false;//for now
}

//Call the compare function above to check if a >= b
bool operator >= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if (a.compare(b) != -1)
		return true;
	else
  		return false;//for now
}

//Call the compare function above to check if a > b
bool operator > (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if (a.compare(b) == 1)
		return true;
	else
  		return false;//for now
}

//Call the compare function above to check if a < b
bool operator < (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if (a.compare(b) == -1)
		return true;
	else
  		return false;//for now
}

//******************************************************************
//END OF THE EQUALITY CHECK OPERATORS SECTION
//******************************************************************

//******************************************************************
//START OF THE ARITHMETIC OPERATORS SECTION
//******************************************************************

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call += operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator + (const  BigInt &a, const BigInt & b){

  /************* You complete *************/
	BigInt c = a;
	c += b;
	return c;
}

/*
//==================
// MEMBER function
//==================
//  Addition assignment operator.
//    i.e., a += b
*/
const BigInt & BigInt::operator += (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
	// handle the case if one of the numbers is 0
	if (vec.size() == 1) {
		if (vec[0] == 0) {
			*this = b;
			return *this;
		}
	}
	if (b.vec.size() == 1) {
		if (b.vec[0] == 0) {
			return *this;
		}
	}

	// If signs are different, then it becomes a case
	// of subtraction
	if (isPositive != b.isPositive) {
		BigInt c = *this;
		BigInt d = b;
		bool c_isPositive = isPositive;
		bool d_isPositive = b.isPositive;
		c.isPositive = true;
		d.isPositive = true;
		
		if (c > d) {
			c -= d;
			c.isPositive = c_isPositive;
			*this = c;
			return *this;
		} else if (d > c) {
			d -= c;
			d.isPositive = d_isPositive;
			*this = d;
			return *this;
		} else {
			BigInt c = BigInt(0,base);
			*this = c;
			return *this;
		}
	} else {
		// Check if a is the bigger vector
		// If not, let's pad it
		int d = b.vec.size() - vec.size();
		unsigned int bs = b.vec.size();
	
		for (int i = 0; i<d; i++) 
			if (vec.size() < b.vec.size()) 
				vec.push_back(0);
	
		int c = 0; //carry
		// Assuming same sign
		for (unsigned int i = 0; i < vec.size(); i++) {
			//add the carry
			int temp = vec[i] + c;
			if ( i < bs )
				temp += b.vec[i];
			c =  temp / base;
			vec[i] = temp % base;
		}
	
		if (c > 0) {
			vec.push_back(c);
		}

	}
	return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call -= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator - (const  BigInt &a, const BigInt & b){

  /************* You complete *************/
  
	BigInt c = a;
	c -= b;
	return c;//for now
}


/*
//==================
// MEMBER function
//==================
//  Subtraction assignment operator.
//    i.e., a -= b
//  Note: Think of base cases (e.g., subtract by itself)
*/
const BigInt & BigInt::operator -= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
	// Subtraction by itself
	if ( (vec == b.vec)  && (isPositive == b.isPositive) ){
		BigInt c = BigInt(0,base);
		*this = c;
		return *this;
	} 
	// handle the case if one of the numbers is 0
	if (vec.size() == 1) {
		if (vec[0] == 0) {
			*this = b;
			isPositive = !isPositive;
			return *this;
		}
	}
	if (b.vec.size() == 1) {
		if (b.vec[0] == 0) {
			return *this;
		}
	}

	// IF a is positive and b is negative
	// or a is negative and b is positive
	// then this is addition

	if (isPositive != b.isPositive) {
		BigInt c = *this;
		BigInt d = b;
		bool c_isPositive = isPositive;
		c.isPositive = true;
		d.isPositive = true;
		
		c += d;
		c.isPositive = c_isPositive;
		*this = c;
		return *this;
	} else {
		BigInt c = *this;
		BigInt d = b;
		bool c_isPositive = isPositive;
		bool d_isPositive = b.isPositive;
		c.isPositive = true;
		d.isPositive = true;
		// lets handle same signs
		// Check if a is the bigger vector
		// If not, let's pad it
		if ( c > d) { 
			int e = b.vec.size() - vec.size();
			unsigned int bs = b.vec.size();
		
			for (int i = 0; i<e; i++) 
				if (vec.size() < b.vec.size()) 
					vec.push_back(0);
		
			int borrow = 0; //borrow
			for (unsigned int i = 0; i < vec.size(); i++) {
				int temp = vec[i] - borrow;
				borrow = 0;
				if ( i < bs )
					temp -= b.vec[i];
				if (temp < 0) {
					borrow = 1;
					vec[i] = temp + base;
				} else {
					vec[i] = temp;
				}
			}
		
			if (borrow > 0) {
				vec.push_back(borrow);
			}
		} else {
			int e = vec.size() - b.vec.size();
			unsigned int as = vec.size();
		
			for (int i = 0; i<e; i++) 
				if (d.vec.size() < c.vec.size()) 
					d.vec.push_back(0);
		
			int borrow = 0; //borrow
			for (unsigned int i = 0; i < d.vec.size(); i++) {
				int temp = d.vec[i] - borrow;
				borrow = 0;
				if ( i < as )
					temp -= c.vec[i];
				if (temp < 0) {
					borrow = 1;
					d.vec[i] = temp + base;
				} else {
					d.vec[i] = temp;
				}
			}
		
			if (borrow > 0) {
				d.vec.push_back(borrow);
			}
			if (c_isPositive && d_isPositive)
				d.isPositive = false;
			*this = d;
		}

	}
	//Strip off leading zeros
	for (int i = vec.size()-1; i >= 0; i--) {
		if (vec[i] == 0) {
			vec.pop_back();
		} else {
			break;
		}
	}
    
  return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call *= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator * (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
	BigInt c = a;
	c *= b;
	return c;//for now
}



/*
//==================
// MEMBER function
//==================
//  Multiplication assignment operator.
//    i.e., a *= b
//  Implement Long Multiplication
//  Note: What are the base cases?? (e.g., multiply by 0)
*/
const BigInt & BigInt::operator *= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
	// Multiplication by zero
	if ( ( (vec.size() == 1) && (vec[0] == 0) ) ||
         ( (b.vec.size() == 1) && (b.vec[0] == 0) ) ) {
		BigInt c = BigInt(0,base);
		*this = c;
		return *this;
	}

	// Multiplication by 1 or -1. If a=1
	if ( (vec.size() == 1) && (vec[0] == 1) ) {
		BigInt c = BigInt(0,base);
		c = b;
		c.isPositive = (isPositive == b.isPositive ? true : false);
		*this = c;
		return *this;
	}
	// Multiplication by 1 or -1. If b=1
	if ( (b.vec.size() == 1) && (b.vec[0] == 1) ) {
		BigInt c = BigInt(0,base);
		c = *this;
		c.isPositive = (isPositive == b.isPositive ? true : false);
		*this = c;
		return *this;
	}

	BigInt total = BigInt(base);
	int carry=0;

	for (unsigned int i=0; i < b.vec.size(); i++) {
		BigInt temp = BigInt(base);
		for (unsigned int k=0; k < i; k++){
			temp.vec.push_back(0);
		}
		for (unsigned int j=0;j < vec.size(); j++) {
			int p = (vec[j] * b.vec[i]) + carry;
			carry = p / base;
			temp.vec.push_back(p % base);
		}
		if (carry) {
			temp.vec.push_back(carry);
			carry = 0;
		}
		total += temp;
	}
	total.isPositive = (isPositive == b.isPositive ? true : false);
	*this = total;
  
    return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call /= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator / (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
	BigInt c = a;
	c /= b;
	return c;//for now
}


/*
//==================
// MEMBER function
//==================
//  Division assignment operator.
//    - Call 'divisionMain' to get the quotient;
*/
const BigInt & BigInt::operator /= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();
    }
    /************* You complete *************/
	BigInt quotient = BigInt(base);
	BigInt remainder = BigInt(base);
	divisionMain(b, quotient, remainder);
	if ( (quotient.vec.size() == 1) && quotient.vec[0] == 0 ) {
		quotient.isPositive = true;
	} 
	*this = quotient;
  
    return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call %= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator % (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
	BigInt c = a;
	c %= b;
	return c;//for now
}


/*
//==================
// MEMBER function
//==================
//  Modulus assignment operator.
//    - Call 'divisionMain' to get the remainder;
//    - Note: remainder takes the sign of the dividend.
*/
const BigInt & BigInt::operator %= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();//divide by zero.
    }
    /************* You complete *************/
	BigInt quotient = BigInt(base);
	BigInt remainder = BigInt(base);
	divisionMain(b, quotient, remainder);
	remainder.isPositive = isPositive;
	if ( (remainder.vec.size() == 1) && remainder.vec[0] == 0 ) {
		remainder.isPositive = true;
	} 
	*this = remainder;
  
    return *this;
}

/*
//  Main function for the Division (/=) and Modulus (%=) operators.
//     - Compute (q)uotient and (r)emainder
//     - Implement Long Division
//  Note: 1. This should behave like integer division
//        2. What are the base cases?? (e.g., div by itself)
*/
void BigInt::divisionMain(const BigInt &b, BigInt &quotient, BigInt &remainder){

    /************* You complete *************/
	// Dividend is empty/0
	if ( (vec.size() == 0) || ((vec.size() == 1) && (vec[0] == 0) ) ) {
		quotient.vec.push_back(0);
		quotient.base = base;
		quotient.isPositive = true;
		remainder.vec.push_back(0);
		remainder.base = base;
		remainder.isPositive = true;
		return;
	}

	// Divison by 1 or -1
	if ( (b.vec.size() == 1) && (b.vec[0] == 1) ) {
		quotient = *this;
		quotient.isPositive = (isPositive == b.isPositive ? true : false);
		remainder.vec.push_back(0);
		remainder.base = base;
		remainder.isPositive = true;
		return;
	}

	//Divison by itself
	BigInt dividend = *this;
	BigInt divisor = b;
	dividend.isPositive = true;
	divisor.isPositive = true;

	if (dividend.compare(divisor) == 0) {
		quotient.vec.push_back(1);
		quotient.base = base;
		quotient.isPositive = (isPositive == b.isPositive ? true : false);
		remainder.vec.push_back(0);
		remainder.base = base;
		remainder.isPositive = true;
		return;
	}

	// All base cases should be taken care of by now

	int pos = dividend.vec.size()-1;
	BigInt dividend_seq = BigInt(dividend.vec[pos],base);
	dividend_seq.isPositive = true;
	quotient.base = base;
	quotient.isPositive = true;

	while((dividend_seq < divisor) && ( pos > 0)) {
		--pos;
		dividend_seq.vec.insert(dividend_seq.vec.begin(),dividend.vec[pos]);
	}
	do {
		int times=0;
		while(dividend_seq >= divisor) {
			dividend_seq -= divisor;
			times++;
		}
		quotient.vec.insert(quotient.vec.begin(),times);
		if( (dividend_seq.vec.size() == 1) && (dividend_seq.vec[0] == 0) ) {
			dividend_seq.vec.clear();
		}
		if (pos > 0) {
			dividend_seq.vec.insert(dividend_seq.vec.begin(),dividend.vec[pos-1]);
		}
		--pos;
	} while (pos >=0);
	
	quotient.isPositive = (isPositive == b.isPositive ? true : false);
	remainder = dividend_seq;
	///Strip leading zeroes
	for (int i = remainder.vec.size()-1; i >= 0; i--) {
		if (remainder.vec[i] == 0) {
			remainder.vec.pop_back();
		} else {
			break;
		}
	}
	if (remainder.vec.size() == 0) {
		remainder.vec.push_back(0);
		remainder.isPositive = true;
	}
}



/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call the 'exponentiation' function on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt pow(const  BigInt &a, const BigInt & b){

    /************* You complete *************/
	BigInt c = a;
	return (c.exponentiation(b));
    //return a;//for now
}

/*
//==================
// MEMBER function
//==================
//  Exponentiation assignment function.
//     - i.e., a.exponentiation(b);
// Note: 1. implement Exponentiation by Squaring (see the writeup)
//       2. b should be treated as BigInt, not int or other data type.
*/
const BigInt & BigInt::exponentiation(const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/
	/* Pseudo-code 
	exp(number x, exponent n)
    if n < 0 then
      x = 1 / x;
      n = -n;
    if n == 0 then return 1;
    y = 1;
    while n > 1 do
      if n is even then 
        x = x * x;
        n = n / 2;
      else
        y = x * y;
        x = x * x;
        n = (n – 1) / 2;
    return x * y
	*/
	BigInt x = *this; //number
	BigInt n = b;     //exponent
	const BigInt zero = BigInt("0",base);
	const BigInt one = BigInt(1,base);
	const BigInt two = BigInt(2,base);

	if (!n.isPositive) {
		x = one / x;
		n.isPositive = true;
	}
	if (n.compare(zero) == 0) {
		*this = one;
		return *this;
	}
	BigInt y = BigInt(1,base);
	while ( n > one ) {
		if ( zero.compare(n % two) == 0 ){
			x = x * x;
			n = n / two;
		} else {
			y = x * y;
			x = x * x;
			n = ( n - one ) / two;
		}
	}
	*this = x * y;
    return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call the 'modulusExp' function on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt modPow(const BigInt &a, const BigInt &b, const BigInt &m){

    /************* You complete *************/
 	BigInt c = a; 
	return (c.modulusExp(b, m));
    //return a;//for now
}


/*
//==================
// MEMBER function
//==================
//  Modulus Exponentiation assignment function.
//     - i.e., a.modulusExp(b)
// Note: 1. implement Modulus Exponentiation (see the writeup)
//       2. b should be treated as BigInt, not int or other data type.
// Hint: same implementation as exponentiation, but take modulus 
//          after every call to the *= operator.
*/
const BigInt & BigInt::modulusExp(const BigInt &b, const BigInt &m){
    if(base != b.base || base != m.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/
	/* Pseudo-code 
	modExp(base x, exponent n, mod m) is
    	if m == 1 then
        	return 0
    	y = 1
    	x = x mod m
    	while n > 0 do
        	if (n mod 2 == 1) then
            	y = (y * x) mod m
        	n = n / 2
        	x = (x * x) mod m
    	return y
	*/
	BigInt x = *this; //number
	BigInt n = b;     //exponent
	const BigInt zero = BigInt("0",base);
	const BigInt one = BigInt(1,base);
	const BigInt two = BigInt(2,base);

	if (!n.isPositive) {
		x = one / x;
		n.isPositive = true;
	}
	if (n.compare(zero) == 0) {
		*this = one;
		return *this;
	}
	BigInt y = BigInt(1,base);
	if (m.compare(one) == 0) {
		*this = zero;
		return *this;
	}

	x = x % m;
	while ( n > zero ) {
		if ( one.compare(n % two) == 0 ){
			//odd 
			y = (y * x) % m;
		}
		n = n / two;
		x = (x * x) % m;
	}
	*this = y;
    return *this;
}

//******************************************************************
//END OF THE ARITHMETIC OPERATORS SECTION
//******************************************************************
