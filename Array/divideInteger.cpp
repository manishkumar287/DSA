// C++ implementation to Divide two integers without using multiplication, division and mod operator
//divide two integer

#include <bits/stdc++.h>
using namespace std;

//function
int divide(long long dividend, long long divisor) {

  // Calculate sign of quotient i.e.,
  // sign will be negative only iff
  // either one of them is negative
  // otherwise it will be positive
  int sign = ((dividend < 0) ^ 
              (divisor < 0)) ? -1 : 1;

  // remove sign of operands
  dividend = abs(dividend);
  divisor = abs(divisor);

  // Initialize the quotient
  long long quotient = 0, temp = 0;

  // test down from the highest bit and
  // accumulate the tentative value for
  // valid bit

  //dividend=43
  //divisor=8
  //for i=31 to i=3 if condition is false 
  //for i=2 (8<<2)==32 if condition is true  (8*(2^2))
  //so quoitent=0|1<<i === 0+4 ==4
  //for i=1 32+(8<<1)==48 if condition is again false
  //for i=0 32+(8<<0)==40 if condition is true
  //so quoitent=4|1<<0 === 4+1 ==5
  for (int i = 31; i >= 0; --i) {

    if (temp + (divisor << i) <= dividend) {
      temp += divisor << i;
      quotient |= 1LL << i;
    }
  }
  //if the sign value computed earlier is -1 then negate the value of quotient
  if(sign==-1) quotient=-quotient;
  
  return quotient;
}

int main() {
  int a = 10, b = 3;
  cout << divide(a, b) << "\n";

  a = 43, b = -8;
  cout << divide(a, b);

  return 0;
}
