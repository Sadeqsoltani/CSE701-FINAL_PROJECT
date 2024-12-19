#include <iostream>
#include <string>
#include <stdexcept>
#include "bigint.hpp"
using namespace std;

int main()
{

    BigInt num1;                                     // zero
    BigInt num2(+650);                               // random number
    BigInt num3(-92);                                // random number
    BigInt num4(-2147483648);                        // int32_t min value
    BigInt num5("9223372036854775807");              // int64_t max value
    BigInt num6("299792458");                        // light of speed
    BigInt num7("31536000");                         // a year in sec
    BigInt num8("354224848179261915075");            // fibonacci 100
    BigInt num9("2432902008176640000");              // factorial 20
    BigInt num10("1267650600228229401496703205376"); // 2 power of 100

    BigInt num11("     00000-165206");           // random number with leading spaces and zeros
    BigInt num12("0000+457892");                 // random number with leading zeros
    BigInt num13("      18446744073709551615");  // uint64_t max value with leading spaces
    BigInt num14("0000000000000000000000000");   // all zeros

    cout
        << "---------------------------------------- (Constructors Results) ----------------------------------------" << endl
        << endl;

    cout << "num1 is The Default constructor which Construct a new BigInt object and initialize it to zero : " << num1 << endl;
    cout << endl;
    cout << "num2 is  the constructor that takes a signed 64-bit integer and Construct a new BigInt object : " << num2 << endl;
    cout << "num3 is  the constructor that takes a signed 64-bit integer and Construct a new BigInt object : " << num3 << endl;
    cout << "num4 is  the constructor that takes a signed 64-bit integer and Construct a new BigInt object : " << num4 << endl;
    cout << endl;
    cout << "num5 is the constructor that takes a string of digits and construct a new BigInt object  : " << num5 << endl;
    cout << "num6 is the constructor that takes a string of digits and construct a new BigInt object  : " << num6 << endl;
    cout << "num7 is the constructor that takes a string of digits and construct a new BigInt object  : " << num7 << endl;
    cout << "num8 is the constructor that takes a string of digits and construct a new BigInt object  : " << num8 << endl;
    cout << "num9 is the constructor that takes a string of digits and construct a new BigInt object  : " << num9 << endl;
    cout << "num10 is the constructor that takes a string of digits and construct a new BigInt object : " << num10 << endl;
    cout << "num11 is the constructor that takes a string of digits and construct a new BigInt object : " << num11 << endl;
    cout << "num12 is the constructor that takes a string of digits and construct a new BigInt object : " << num12 << endl;
    cout << "num13 is the constructor that takes a string of digits and construct a new BigInt object : " << num13 << endl;
    cout << "num14 is the constructor that takes a string of digits and construct a new BigInt object : " << num14 << endl;

    cout << endl;

    cout << "---------------------------------------- (Throw exception for Invalid Inputs and operations) ----------------------------------------" << endl
         << endl;

    try
    {
        BigInt num15("+1234rt7p89&");
    }
    catch (const std::exception &e)
    {
         cout << "Error : " << e.what() << endl;
    }

    try
    {
        BigInt num16("");
    }
    catch (const std::exception &e)
    {
         cout << "Error : " << e.what() << endl;
    }

    try
    {
         cout << (num2 / num1) << endl;
    }
    catch (const std::exception &e)
    {
         cout << "Error : " << e.what() << endl;
    }

    cout << endl;

    cout << "---------------------------------------- (Comparison operators) ----------------------------------------" << endl
         << endl;

    std::cout << std::boolalpha;
    cout << "num8  == num10 : (354224848179261915075 == 1267650600228229401496703205376) ? " << (num8 == num10) << endl;
    cout << "num5  != num13 : (9223372036854775807 != 18446744073709551615) ? " << (num5 != num13) << endl;
    cout << "num9  >  num8  : (2432902008176640000 > 354224848179261915075) ? " << (num9 > num8) << endl;
    cout << "num12 <  num13 : (457892 < 18446744073709551615) ? " << (num12 < num13) << endl;
    cout << "num10 <= num5  : (1267650600228229401496703205376 <= 9223372036854775807) ? " << (num10 <= num5) << endl;
    cout << "num4  >= num11 : (-2147483648 >= -165206) ? " << (num4 >= num11) << endl;

    cout << endl;

    cout << "---------------------------------------- ( Arithmetic operators) ----------------------------------------" << endl
         << endl;

    cout << "num9  + num10  : (2432902008176640000 + 1267650600228229401496703205376) = " << (num9 + num10) << endl;
    cout << "num12 + num13  : (457892 + 18446744073709551615) = " << (num12 + num13) << endl;

    cout << endl;

    cout << "num13 - num5  : (18446744073709551615 - 9223372036854775807) = " << (num13 - num5) << endl;
    cout << "num12 - num3  : (457892 - (-92)) = " << (num12 - num3) << endl;

    cout << endl;

    cout << "num6 * num7   : (299792458 * 31536000) = " << (num6 * num7) << endl;
    cout << "num9 * num6   : (2432902008176640000 * 299792458) = " << (num9 * num6) << endl;
    cout << "num9 * num1   : (2432902008176640000 * 0) = " << (num9 * num1) << endl; //new

    cout << endl;

    cout << "num8 / num9   : (354224848179261915075 / 2432902008176640000) = " << (num8 / num9) << endl;
    cout << "num5 / num4   : (9223372036854775807 / -2147483648) = " << (num5 / num4) << endl;
    cout << "num1 / num4   : (0 / -2147483648) = " << (num1 / num4) << endl;
    cout << "num2 / num12  : (650 /457892) = " << (num2 / num12) << endl;
    cout << "num2 / num2   : (650 /650) = " << (num2 / num2) << endl;

    cout << endl;

    cout << "num8 % num9   : (354224848179261915075 % 2432902008176640000) = " << (num8 % num9) << endl;
    cout << "num5 % num4   : (9223372036854775807 % -2147483648) = " << (num5 % num4) << endl;
    cout << "num2 % num2   : (650 % 650) = " << (num2 % num2) << endl; //new

    cout << endl;

    BigInt num17("100000000000000000000");
    cout << "num17 += num5  : (100000000000000000000 += 9223372036854775807) ---> num17 = " << (num17 += num5) << endl;
    BigInt num18("200000000000000000000");
    cout << "num18 -= num12 : (200000000000000000000 -= 457892) ---> num18 = " << (num18 -= num12) << endl;
    BigInt num19("300000000000000000000");
    cout << "num19 *= num2  : (300000000000000000000 *= 650) ---> num19 = " << (num19 *= num2) << endl;
    BigInt num20("400000000000000000000");
    cout << "num20 /= num7  : (400000000000000000000 /= 31536000) ---> num20 = " << (num20 /= num7) << endl;
    BigInt num21("500000000000000000000");
    cout << "num21 %= num7  : (500000000000000000000 %= 31536000) ---> num21 = " << (num21 %= num7) << endl;

    cout << endl;

    cout << "---------------------------------------- ( Unary negation operator) ----------------------------------------" << endl
         << endl;

    cout << "-num3  :  (-(-92)) = " << (-num3) << endl;
    cout << "-num5  : (-(9223372036854775807)) = " << (-num5) << endl;

    cout << endl;

    cout << "---------------------------------------- (Combined operations) ----------------------------------------" << endl
         << endl;

    cout << "(-2147483648 <= -165206 ) ? (-165206 - (-2147483648)) : (-2147483648 - (-165206)) = "
         << ((num4 <= num11) ? (num11 - num4) : (num4 - num11)) << endl;

    cout << "(354224848179261915075 == 2432902008176640000) ? (--(0)) : (++(0)) = "
         << ((num8 == num9) ? (--num1) : (++num1)) << endl;

    cout << "( 9223372036854775807 != 18446744073709551615 ) ? (9223372036854775807 + 18446744073709551615) : (9223372036854775807 * 0) = "
         << ((num5 != num13) ? (num5 + num13) : (num5 * num1)) << endl;

    cout << endl;

    cout << "(num13 + num2) - num12  : (18446744073709551615 + 650) - 457892 = "
         << (num13 + num2) - num12 << endl; // (A + B) - C

    cout << "(num13 - num12) + num2  : (18446744073709551615 - 457892) + 650 = "
         << (num13 - num12) + num2 << endl; // (A - C) + B

    cout << "num10 - (num9 * num2)   : 1267650600228229401496703205376 - (2432902008176640000 * 650) = "
         << (num10 - (num9 * num2)) << endl;

    cout << "(num13 * num14) + num5   : (18446744073709551615 * 0 ) + 9223372036854775807 = "
         << (num13 * num14 + num5) << endl;

    cout << "(num8 *= num2) + num9   : (354224848179261915075 *= 650) + 2432902008176640000 = "
         << ((num8 *= num2) + num9) << endl;

    cout << "(num7 / num2) * num2 + (num7 % num2) : (31536000 / 650) * 650  + (31536000  % 650) = "
         << (num7 / num2) * num2 + (num7 % num2) << endl;


    cout << endl;

    cout << "---------------------------------------- (Increment and Decrement Operators) ----------------------------------------" << endl
         << endl;

    cout << "++num2  : ++(650) = " << (++num2) << endl;

    cout << "num5++  : (9223372036854775807)++ = " << (num5++) << " (after = " << num5 << ")" << endl;

    cout << "--num13 : --(18446744073709551615) = " << (--num13) << endl;

    cout << "num12-- : (457892)-- = " << (num12--) << " (after = " << num12 << ")" << endl;

    cout << endl;


    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

    return 0;
}