// Mean => sum of all numbers / total numbers  [ or Avg of data points ]
// Median => arranging all numbers in ascending or descending order and picking up the middle element
//           if even then take average of 2 in middle else if odd take the middle number itself


// Prime Numbers => Its a number which is divisible by 1 and itself only
// Facts :

// 1] Each prime number can be represented in the form of 6n-1 or 6n+1 excpet 2 and 3 [ n is natural number ]
// 2] 2 and 3 are only consecutive natural numbers which are prime


// LCM and HCF

// Factors : All numbers that divide a number are called the factors of the number
// ie: 1,2,3,4,6,8,12,24 are factors of 24, and 24 is a multiple of these numbers

// LCM => LCM of 2 numbers is the Smallest number other than 0 which is the multiple of both the numbers
// ie : 4 and 6 has LCM as 12
// Brute Force : find multiples of a and b, till a*b and select the common ones and the smallest

// HCF => HCF of 2 numbers is the highest number which divides both the given numbers
// ie : 12 and 16 has HCF as 4
// Brute Force : find factors of 12 => 1,2,3,4,6,12
//             : find factors of 16 => 1,2,4,8,16 
//             : pick common : { 1,2,4 }
//             : pick highest : 4 .. answer

// Property 
// LCM*HCF = Product of Two Numbers .. IMP

// Factorials

// n! = n(n-1)(n-2)(n-3).....1
// 0! = 1

// Permutation and Combinations

// Permutation : Arrangement of r things out of total of n things is defined as nPr = N!/(N-R)!
// Combination : Selection of r things out of total of n things is defined as nCr = n!/(r!*(n-r)!) = nPr/r!


// Modular Arithmetic 

// Longest integer in C++ inbuilt is 64 bit unsigned long long int
// if it goes beyond it then it will overflow

// Thus we do modular arithmetic in C++ to prevent integer overflow
// using % operation / modulo operation

