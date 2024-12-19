# BigInt Project

This is the final project for the Foundations of Modern Scientific Programming course in Fall 2024, instructed by Prof. Barak Shoshany

# Overview

Standard data types in C++, such as int64_t have fixed sizes and can overflow when handling extremely large numbers that exceed their capacity. For instance, a signed 64-bit integer can only represent values up to 9,223,372,036,854,775,807 (around 9.2×10¹⁸). If we need to enter or perform operations on numbers greater than this limit, we cannot use a 64-bit integer as it would result in overflow or truncation. To address this limitation, this project is designed to  write a C++ class named BigInt for arbitrary-precision integers as an extension of the usual C++ signed integer types except that bigint class will allow signed integers of unlimited range - limited only by the computer's memory.

# Test Structure

The test.cpp file is designed to comprehensively test the functionality of the BigInt class. To achieve this, various BigInt objects are created, and some large real-world numbers are used such as: **uint64_t max value (18,446,744,073,709,551,615)** , **int64_t max value (9,223,372,036,854,775,807)** , **int32_t min value (-2,147,483,648)** , **2 power of 100 (1267650600228229401496703205376)** , **Factorial of 20 (2,432,902,008,176,640,000)** , **Fibonacci of 100(354224848179261915075)** , **Speed of light in m/s (299,792,458)** ,  **Seconds in a year (31,536,000)** and **some Random numbers**.To ensure a reliable and self-contained test that works independently and successfully, these numbers are used to test all aspects of the BigInt class comprehensively. *1*.Write separate tests for each feature of the BigInt class, such as constructors, operators, and member functions and verify that each individual functionality works as expected *2*.Write tests that combine two or more features like addition and subtraction together *3*.Test the class with edge cases, like large numbers,negative values *4*.Test the class with bad_formatted input strings like with leading zeros or spaces and ensure class can handle such inputs and create a well-formatted input *5*. Test invalid inputs, such as input Strings that have invalid digits , empty inputs and operations that are not allowed like division by zero and ensure that the class throws exceptions *6*.Write a test and verify that all operations across the class are consistent with each other and follow the same logical rules.


# Class Structure

## Public:

### Constructors:

```cpp
BigInt();  //The Default constructor which initializes a BigInt object to 0 with a positive sign

test 1: BigInt num1;                    output 1: +0

BigInt(const int64_t int_number);  //Constructs a BigInt object from a signed 64-bit integer

test 1: BigInt num2(+650);               output 1: +650 
test 2: BigInt num3(-92);                output 2: -92
test 3: BigInt num4(-2147483648);        output 3: -2147483648 

BigInt(const std::string &str_number);  //Constructs a BigInt object from a string input

test 1:  BigInt num5("9223372036854775807");                output 1: +9223372036854775807     
test 2:  BigInt num6("299792458");                          output 2: +299792458    
test 3:  BigInt num7("31536000");                           output 3: +1536000  
test 4:  BigInt num8("354224848179261915075");              output 4: +354224848179261915075
test 5:  BigInt num9("2432902008176640000");                output 5: +2432902008176640000
test 6:  BigInt num10("1267650600228229401496703205376");   output 6: +1267650600228229401496703205376

```
### Operators Overloading:

#### Arithmetic Operators:

```cpp

BigInt operator+(const BigInt &operand) const;  //Adds two BigInt objects and create a new object

test 1: (2432902008176640000 + 1267650600228229401496703205376)       output 1: +1267650600230662303504879845376 // (factorial 20 + 2 power of 100)
test 2: (457892 + 18446744073709551615)                               output 2: +18446744073710009507

BigInt &operator+=(const BigInt &operand);  //Adds and updates the current BigInt

test 1:(100000000000000000000 += 9223372036854775807)   output 1: +109223372036854775807

BigInt operator-(const BigInt &operand) const;  //Subtracts two BigInt objects and creates a new object

test 1: (18446744073709551615 - 9223372036854775807)    output 1: +9223372036854775808 // (uint64-t max value - int64-t max value)
test 2: (457892 - (-92))                               output 2:  +457984

BigInt &operator-=(const BigInt &operand);  //Subtracts and updates the current BigInt

test 1: (200000000000000000000 -= 457892)       output 1: 199999999999099542108

BigInt operator*(const BigInt &operand) const;  //Multiplies two BigInt objects and create a new object

test 1: (299792458 * 31536000)                             output 1: +9454254955488000 // (light of speed * a year in sec)
test 2: (2432902008176640000 * 299792458)                  output 2: +729365673104411003781120000
test 3: (2432902008176640000 * 0)                          output 3: +0

BigInt &operator*=(const BigInt &operand);   //Multiplies and updates the current BigInt

test 1: (300000000000000000000 *= 650)         output 1: +195000000000000000000000

BigInt operator/(const BigInt &operand) const;  // Divides two BigInt objects and creates a new object

test 1: (354224848179261915075 / 2432902008176640000)           output 1: +145   // (fibonacci 100 / factorial 20)
test 2: (9223372036854775807 / -2147483648)                     output 2: -4294967295
test 3: (0 / -2147483648)                                       output 3: +0
test 4: (650 /457892)                                           output 4: +0
test 5: (650 /650)                                              output 5: +1    

BigInt &operator/=(const BigInt &operand);  //Divides and updates the current BigInt

test 1: (400000000000000000000 /= 31536000)       output 1: +12683916793505

BigInt operator%(const BigInt &operand) const;  //Computes the modulus of two BigInt objects and creates a new object

test 1: (354224848179261915075 % 2432902008176640000)          output 1: +1454056993649115075
test 2: (9223372036854775807 % -2147483648)                    output 2: +2147483647
test 3: (650 % 650)                                            output 3: +0


BigInt &operator%=(const BigInt &operand);  //Computes the modulus and updates the current BigInt object

test 1: (500000000000000000000 %= 31536000)       output 1: +9248080

```
#### Comparison Operators:

```cpp
bool operator==(const BigInt &operand) const;  //Checks whether two BigInt objects are equal

test 1: (354224848179261915075 == 1267650600228229401496703205376)      output 1: false  // (fibonacci 100 == 2 power of 100)

bool operator!=(const BigInt &operand) const;  //Checks whether two BigInt objects are unequal

test 1: (9223372036854775807 != 18446744073709551615)                   output 1: true  // (int64-t max value != uint64-t max value)

bool operator>(const BigInt &operand) const;  //Checks whether the current BigInt is greater:

test 1: (2432902008176640000 > 354224848179261915075)                    output 1: false // (factorial 20 > fibonacci 100)

bool operator<(const BigInt &operand) const;  //Checks whether the current BigInt is smaller

test 1: (457892 < 18446744073709551615)                                  output 1: true

bool operator>=(const BigInt &operand) const;  //Checks whether the current BigInt is greater or equal

test 1: (-2147483648 >= -165206)                                         output 1: false

bool operator<=(const BigInt &operand) const; //Checks whether the current BigInt is smaller or equal

test 1: (1267650600228229401496703205376 <= 9223372036854775807)         output 1: false

```
#### Increment and Decrement Operators:

```cpp
BigInt &operator++();  //Increments a BigInt object by 1 and returns incremented value

test 1:  ++(650)                   output 1: +651

BigInt operator++(int);  //Increments a BigInt object by 1 and returns the original value

test 1: (9223372036854775807)++     output 1: +9223372036854775807

BigInt &operator--(); //Decrements a BigInt object by 1 and return decremented value

test 1: --(18446744073709551615)    output 1: +18446744073709551614

BigInt operator--(int);  //Decrements a BigInt object by 1 and return the original value

test 1: (457892)--                 output 1: +457892

```
#### Unary Operator:

```cpp
BigInt operator-() const;  //Negates a BigInt object

test 1: (-(-92))                                 output 1: +92
test 2: (-(9223372036854775807))                 output 2: -9223372036854775807
```

#### Stream Operator:

```cpp
friend std::ostream &operator<<(std::ostream &out, const BigInt &bigint); //Outputs a BigInt object with its sign and value

```

### Getters , Setters and Modifiers:
```cpp

char getsign() const;  // Returns the sign of a bigint object

Example: BigInt num11("-165206");                            output: num11.getsign(); ---> '-'

std::string getnumber() const;  // Returns the numerical value of a bigint object

Example: BigInt num11("-165206");                            output: num11.getnumber(); ---> "165206" 

void setnumber(const std::string &str);  // removes leading zeros then sets the numerical value of a new bigint object

Example: num11.setnumber("0000650456");                     output: num11.getnumber(); ---> "650456" // new value for num11 

void setsign(char ch);  // Sets the sign of a new  bigint object

Example: num11.setsign('-');                                 output: num11.getsign(); ---> '-' // new sign for num11 
             
size_t getsize() const;  // Returns the size of a bigint object without sign

Example: num11.getsize();                                   output: 6 // excluding sign

BigInt abs() const;  // Return the absolute value of a bigint object

Example: num11.abs();                                       output: +650456

```
## Private:

```cpp
char sign;  //Stores the sign of a BigInt object

std::string number; //Stores the numerical value of a BigInt object

```
```cpp
void check_number(std::string &main_number)  //Remove leading zeros and spaces then validate the input string and throw exceptions

test 1: BigInt BigInt num11("     00000-165206");        output 1: -165206
test 2: BigInt num12("0000+457892");                     output 2: +457892    
test 3: BigInt num13("      18446744073709551615");      output 3: +18446744073709551615
test 4: BigInt num14("0000000000000000000000000");       output 4: +0
test 5: BigInt num15("+1234rt7p89&");                    output 5: Error: Input contains invalid characters
test 6: BigInt num16("");                                output 6: Error: Input is empty    
test 7: (+650 / 0)                                       output 7: Error: Division by zero is not allowed    
```  
```cpp
void split_sign_and_number(std::string &raw_number)  //Separates the sign and numerical part of the input
```
# Combined test
```cpp

test 1:(-2147483648 <= -165206 ) ? (-165206 - (-2147483648)) : (-2147483648 - (-165206))        output 1: +2147318442     
test 2:(354224848179261915075 == 2432902008176640000) ? (--(0)) : (++(0))                       output 2: +1
test 3:(1267650600228229401496703205376) - (2432902008176640000 * 650)                          output 3: +1267650598646843096181887205376
test 4:(18446744073709551615 * 0 ) + 9223372036854775807                                        output 4: +9223372036854775807
test 5:(354224848179261915075 *= 650) + 2432902008176640000                       output 5: +230248584218528421438750
test 6:(31536000 / 650) * 650  + (31536000  % 650)                                output 6: +31536000
test 7:(18446744073709551615 + 650) - 457892                                      output 7: +18446744073709094373  // (A + B) - C
test 8:(18446744073709551615 - 457892) + 650                                      output 8: +18446744073709094373  // (A - C) + B  
                     
```

# Code Validation and Quality Assurance

The bigint.hpp file has been compiled and tested successfully using both GCC and Clang compilers and all compiler warnings and errors have been fixed. Also the Code Spell Checker extension is used to eliminate typos and ensure clear documentation. Finally all outputs generated by the test.cpp file have been thoroughly checked for accuracy.

# Requirements

C++ Standard: C++23 

Compiler: The latest versions of GCC or Clang with the compiler argument -std=c++23 

# How to Compile and Run 

Place the test.cpp and bigint.hpp files in the same directory. Compile and run either file—both will display the results of the test experiments in the terminal

## References

[The lecture notes](https://baraksh.com/CSE701/notes/)

[C++ Reference](https://en.cppreference.com/w/)
