#include <iostream>
#include <string>
#include <stdexcept>

/**
 * @brief A class for arbitrary-precision integer
 */

class BigInt
{

public:
    /**
     * @brief The Default constructor which Construct a new BigInt object and initialize it to zero
     */

    BigInt();

    /**
     * @brief The constructor that takes a signed 64-bit integer and Construct a new BigInt object
     *
     * @param int_number The signed 64-bit integer
     */

    BigInt(const int64_t int_number);

    /**
     * @brief The constructor that takes a string of digits and construct a new BigInt object
     * Since a string input may have a bad format with leading zeros and spaces or contain invalid digits
     * Then before finalizing the construction, the input need to be trimmed and validated to ensure it represents a valid and well-formatted input for the rest of process
     *
     * @param str_number The string representing the integer
     */

    BigInt(const std::string &str_number);

    /**
     * @brief The member function which returns the sign of a BigInt object
     * Used to access the 'sign' which is private member of the BigInt class, and read the sign of an object
     *
     * @return A character representing the sign of a BigInt object ('+' or '-')
     */

    char getsign() const;

    /**
     * @brief The member function that receives and sets the sign of a new BigInt object
     * Used to set the sign for a newly created BigInt object resulting from operations like *, + , - , / and %
     *
     * @param ch A character representing the new sign ('+' or '-')
     */

    void setsign(char ch);

    /**
     * @brief The member function that returns the numerical part of a BigInt object
     * Used to access the `number` which is a private member of the BigInt class, and read the numerical value without the sign
     *
     * @return A string representing the numerical part of a BigInt object
     */

    std::string getnumber() const;

    /**
     * @brief The member function that receives and sets the numerical part of a new BigInt object
     * Used to set the numerical part for a newly created BigInt object resulting from operations like *, +, - , / and %
     * Since leading zeros may be added during operations to align numbers, this function remove leading zeros before setting the `number`, ensuring a valid input
     *
     * @param str A string representing the new numerical value
     */

    void setnumber(const std::string &str);

    /**
     * @brief The member function that returns number of digits in the numerical part of a BigInt object
     *
     * @return size_t The number of digits in the numerical part of a BigInt object
     */

    size_t getsize() const;

    /**
     * @brief The member function that returns the absolute value of a BigInt object
     *
     * @return BigInt the absolute value of the current BigInt (*this)
     */

    BigInt abs() const;

    /**
     * @brief Overloads the addition operator (+) for BigInt class
     * Performs addition between the current BigInt object (*this) and  operand
     * To align the numbers, leading zeros are added to the shorter number. The process then split into different scenarios based on the signs and sizes of the objects
     * The addition is performed digit by digit, similar to the traditional school method
     *
     * @param operand The BigInt object to be added to *this
     * @return BigInt a new BigInt object representing the sum of the two BigInt objects
     */

    BigInt operator+(const BigInt &operand) const;

    /**
     * @brief Overloads the compound addition operator (+=) for BigInt class
     * Uses the logic of the overloaded operator `+` and Performs addition between the current BigInt object (*this) and operand
     * This process add operand to *this and update the value of *this
     *
     * @param operand The BigInt object to be added to (*this)
     * @return BigInt& A reference to the updated BigInt object (*this)
     */

    BigInt &operator+=(const BigInt &operand);

    /**
     * @brief Overloads the subtraction operator (-) for BigInt class
     * Performs subtraction between the current BigInt object (*this) and operand
     * This operation takes advantage of the overloaded addition '+' and unary negation operators.It negates the operand and then adding it to *this
     *
     * @param operand The BigInt object to subtract from *this
     * @return BigInt a new BigInt object representing the subtraction of the two BigInt objects
     */

    BigInt operator-(const BigInt &operand) const;

    /**
     * @brief Overloads the compound subtraction (-=) operator for BigInt class
     * Uses the logic of the overloaded operator  `-` and Performs subtraction between the current BigInt object (*this) and operand
     * this process subtract operand from *this and update the value of *this
     *
     * @param operand The BigInt object to subtract from *this
     * @return BigInt& A reference to the updated BigInt object (*this)
     */

    BigInt &operator-=(const BigInt &operand);

    /**
     * @brief Overloads the multiplication operator (*) for BigInt class
     * Performs multiplication between the current BigInt object (*this) and the operand
     * The multiplication is done digit-by-digit, similar to traditional school multiplication
     * It also takes advantage of the overloaded addition `+` operator to sum the results of partial multiplications and compute the final result
     *
     * @param operand The BigInt object to multiply with *this
     * @return BigInt a new BigInt object representing the multiplication of the two BigInt objects
     */

    BigInt operator*(const BigInt &operand) const;

    /**
     * @brief Overloads the compound multiplication (*=) operator for BigInt class
     * Uses the logic of the overloaded operator `*` to perform multiplication between the current BigInt object (*this) and operand
     * This process multiplies the operand with (*this) and updates the value of (*this)
     *
     * @param operand The BigInt object to multiply with *this
     * @return BigInt& A reference to the updated BigInt object (*this)
     */

    BigInt &operator*=(const BigInt &operand);

    /**
     * @brief Overloads the unary negation operator (-) for BigInt class
     * Changes the sign of the BigInt object from '+' to '-' and vice versa and returns a new BigInt object with the opposite sign
     *
     * @return BigInt a new BigInt object with the opposite sign
     */

    BigInt operator-() const;

    /**
     * @brief Overloads the division operator (/) for BigInt class
     * Performs division of the current BigInt object (*this) as the dividend and the operand as the divisor
     * Since applying division directly to strings is complicated and prone to errors, the function use the logic of overloaded comparison operators to split the operation into different possible scenarios
     * For the scenario where the dividend > divisor, we take advantage of the overloaded operators (`*`, `+`, `-=`) to iteratively calculate the remainder and quotient
     *
     * @param operand The BigInt object as the divisor
     * @return BigInt A BigInt representing the quotient of the division
     */

    BigInt operator/(const BigInt &operand) const;

    /**
     * @brief Overloads the compound division operator (/=) for BigInt class
     * Uses the logic of the overloaded operator `/`  to divide the current BigInt object (*this) by the operand as divisor
     * Updates *this with the quotient and returns the updated *this
     *
     * @param operand The BigInt object as the divisor
     * @return BigInt& A reference to the updated object (*this)
     */

    BigInt &operator/=(const BigInt &operand);

    /**
     * @brief Overloads the modulus operator (%) for BigInt class
     * Uses the logic of the overloaded operator `/` to calculate the quotient, and then takes advantage of the overloaded operators `-` and `*` operators to compute the modulus based on the traditional formula
     *
     * @param operand The BigInt object as the divisor
     * @return BigInt a new BigInt object representing the remainder of the division
     */

    BigInt operator%(const BigInt &operand) const;

    /**
     * @brief Overloads the compound modulus operator (%=) for BigInt class
     * Uses the logic of the overloaded operator `%` to calculate the remainder of the division of the current BigInt object (*this) by the operand and return updated *this
     *
     * @param operand The BigInt object as the divisor
     * @return BigInt&  A reference to the updated BigInt object (*this)
     */

    BigInt &operator%=(const BigInt &operand);

    /**
     * @brief Overloads the equality (==) operator for BigInt class
     * Compare the current BigInt object (*this) and operand to determine whether they are equal or not
     * First Compares the signs and sizes of both BigInt objects ,If the sizes and signs are equal, performs a digit-by-digit comparison of their numerical values
     *
     * @param operand The BigInt object to compare with (*this)
     * @return true if the two BigInt objects are equal
     * @return false if the two BigInt objects are not equal
     */

    bool operator==(const BigInt &operand) const;

    /**
     * @brief Overloads the inequality operator (!=) for BigInt class
     * uses the logic of the equality operator (`==`) and Compares the current BigInt object (*this) with the operand for inequality
     *
     * @param operand The BigInt object to compare with *this
     * @return true if the two BigInt objects are not equal
     * @return false if the two BigInt objects are equal
     */

    bool operator!=(const BigInt &operand) const;

    /**
     * @brief Overloads the greater-than operator (>) for BigInt class
     * Compares the current BigInt object (*this) with the operand to determine whether *this is greater than the operand or not
     * The comparison is split into different scenarios based on the signs of the objects
     *
     * @param operand The BigInt object to compare with *this
     * @return true if (*this) is greater than the operand
     * @return false if (*this) is not greater than the operand
     */

    bool operator>(const BigInt &operand) const;

    /**
     * @brief Overloads the less-than operator (<) for BigInt class
     * Uses the logic of the overloaded operator `>` to compare the current BigInt object (*this) with operand to determines whether (*this) is less than the operand or not
     *
     * @param operand The BigInt object to compare with *this
     * @return true if (*this) is less than the operand
     * @return false if (*this) is not less than the operand
     */

    bool operator<(const BigInt &operand) const;

    /**
     * @brief Overloads the greater-than-or-equal-to operator (>=) for BigInt class
     * Uses the logic of the overloaded operators `>` and `==` to compare the current BigInt object (*this) with the operand to determines whether *this is greater than or equal to the operand or not
     *
     * @param operand The BigInt object to compare with *this
     * @return true if (*this) is greater than or equal to the operand
     * @return false if (*this) is not greater than or equal to the operand
     */

    bool operator>=(const BigInt &operand) const;

    /**
     * @brief Overloads the less-than-or-equal-to operator (<=) for BigInt class
     * Uses the logic of the overloaded operators `<` and `==` to compare the current BigInt object (*this) with the given operand and determines whether (*this) is less than or equal to the operand or not
     *
     * @param operand The BigInt object to compare with (*this)
     * @return true  if (*this) is less than or equal to the operand
     * @return false if (*this) is not less than or equal to the operand
     */

    bool operator<=(const BigInt &operand) const;

    /**
     * @brief Overloads the pre-increment operator (++X) for BigInt class
     * Uses the logic of the overloaded operator `+` to increment the current BigInt object (*this) by 1
     * the function returns the incremented value of *this
     *
     * @return BigInt& A reference to the updated BigInt object (*this)
     */

    BigInt &operator++();

    /**
     * @brief Overloads the post-increment operator (X++) for BigInt class
     * The function creates a copy of (*this) and increments (*this) by 1 using the logic of the overloaded operator '+'
     * the function returns the original (pre-increment) value of (*this)
     *
     *@param int  is a parameter to differentiate post-increment from pre-increment
     * @return BigInt  a BigInt object representing the original value of (*this)
     */

    BigInt operator++(int);

    /**
     * @brief Overloads the pre-decrement operator (--X) for BigInt class
     * Uses the logic of the overloaded operator `-`  to decrement the current BigInt object (*this) by 1
     * the function returns the decremented value of *this
     *
     * @return BigInt& A reference to the updated BigInt object (*this)
     */

    BigInt &operator--();

    /**
     * @brief Overloads the post-decrement operator (X--) for BigInt class
     * The function creates a copy of (*this) and decrements (*this) by 1 using the logic of the overloaded operator  `-`
     * the function returns the original (pre-decrement) value of (*this)
     *
     * @param int is a parameter to differentiate post-decrement from pre-decrement
     * @return BigInt a BigInt object representing the original value of (*this)
     */

    BigInt operator--(int);

    /**
     * @brief Overloads the insertion operator (<<) for BigInt class
     * Streams a BigInt object to an output stream, formatting it with the sign ('+' or '-') followed by its numerical part
     *
     * @param out The output stream that the BigInt object will be written to
     * @param bigint The BigInt object to be output
     * @return std::ostream& A reference to the modified output stream
     */

    friend std::ostream &operator<<(std::ostream &out, const BigInt &bigint);

private:
    /**
     * @brief Private members of the BigInt class
     * number Stores the numerical part of a BigInt object which is in string format
     * sign Stores the sign of a BigInt object as a character ('+' or '-')
     *
     */

    std::string number;
    char sign;

    /**
     * @brief Trims and validates the string input for constructing a valid BigInt object
     * First Removes leading zeros and spaces to ensure the input is well-formatted.
     * Then, checks the input for invalid characters ,if any invalid character is found an exception is thrown
     *
     * @param main_number The input string for trimming and validation process
     */

    void check_number(std::string &main_number);

    /**
     * @brief Splits the input string into the sign and numerical value for a BigInt object
     * Receives a well-formatted input string passed from check_number() and splits it into the sign and the numerical part
     * This process facilitates the implementation of operators overloading to focus only on the numerical value without interruption from the sign
     *
     * @param raw_number the input string for splitting sign and number
     */

    void split_sign_and_number(std::string &raw_number);
};

BigInt::BigInt()
{

    number = "0";
    sign = '+';
}

BigInt::BigInt(int64_t int_num)
{
    std::string temp = std::to_string(int_num); // to_string() from cppreference.com is a numeric conversion which converts an integral or floating-point value to string

    split_sign_and_number(temp);
}

BigInt::BigInt(const std::string &str_num)
{
    std::string temp = str_num;

    check_number(temp);
    split_sign_and_number(temp);
}

void BigInt::split_sign_and_number(std::string &raw_number)
{
    if (raw_number == "0" || raw_number == "+0" || raw_number == "-0")
    {
        sign = '+';
        number = "0";
    }
    else
    {
        if (raw_number[0] == '-' || raw_number[0] == '+')
        {
            sign = raw_number[0];
            number = raw_number.substr(1);
        }
        else
        {
            sign = '+';
            number = raw_number;
        }
    }
}

// find_first_not_of() from cppreference.com is a member function of std::string ,it finds the first character equal to none of the characters in the given character sequence
void BigInt::check_number(std::string &main_number)
{
    std::size_t non_space_position = main_number.find_first_not_of(' '); // it finds the first position in the string that is not a space (' ')
    if (non_space_position == std::string::npos)                         // If all characters are spaces, the function returns std::string::npos, indicating input is all spaces
    {
        throw std::invalid_argument("Input is empty ");
    }
    main_number = main_number.substr(non_space_position);

    std::size_t non_zero_position = main_number.find_first_not_of('0'); // it finds first position in the string that is not a zero ('0')
    if (non_zero_position == std::string::npos)                         // If all characters are zeros, the function returns std::string::npos and  string is set to "0"
    {

        main_number = "0";
    }
    else
    {
        main_number = main_number.substr(non_zero_position);
    }

    if (main_number.find_first_not_of("0123456789+-") != std::string::npos) // it checks the trimmed input string to find any character that is not part of the valid set (0123456789+-)
    {
        throw std::invalid_argument("Input contains invalid characters");
    }
}

std::string BigInt::getnumber() const
{
    return number;
}

char BigInt::getsign() const
{
    return sign;
}

void BigInt::setsign(char ch)
{
    sign = ch;
}

void BigInt::setnumber(const std::string &str)
{
    size_t start_position = str.find_first_not_of('0'); // remove leading zeros which are created in operations before set the number
    if (start_position == std::string::npos)
    {
        number = "0";
    }
    else
    {
        number = str.substr(start_position);
    }
}

size_t BigInt::getsize() const
{
    return number.size();
}

BigInt BigInt::abs() const
{
    BigInt temp = *this;
    temp.setsign('+');
    return temp;
}

bool BigInt::operator==(const BigInt &operand) const
{

    if (getsign() != operand.getsign())
        return false;

    if (getsize() != operand.getsize())
        return false;

    if (getnumber().compare(operand.getnumber()) == 0) // compare() is a member function from cppreference.com compares two strings, char by char and return < , > and ==
        return true;
    else
        return false;
}

bool BigInt::operator!=(const BigInt &operand) const
{
    return !(*this == operand);
}

bool BigInt::operator>(const BigInt &operand) const
{

    if ((getsign() == '+') && (operand.getsign() == '-'))
        return true;
    if ((getsign() == '-') && (operand.getsign() == '+'))
        return false;

    if ((getsign() == '+') && (operand.getsign() == '+'))
    {
        if (getsize() > operand.getsize())
            return true;
        else if (getsize() < operand.getsize())
            return false;

        if (getsize() == operand.getsize())
        {
            if (getnumber().compare(operand.getnumber()) > 0)
                return true;
            else
                return false;
        }
    }

    if ((getsign() == '-') && (operand.getsign() == '-'))
    {
        if (getsize() < operand.getsize())
            return true;
        else if (getsize() > operand.getsize())
            return false;

        if (getsize() == operand.getsize())
        {
            if (getnumber().compare(operand.getnumber()) < 0)
                return true;
            else
                return false;
        }
    }

    return false;
}

bool BigInt::operator<(const BigInt &operand) const
{
    if (operand > *this)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BigInt::operator>=(const BigInt &operand) const
{
    if (*this > operand || *this == operand)
        return true;
    return false;
}

bool BigInt::operator<=(const BigInt &operand) const
{
    if (*this < operand || *this == operand)
        return true;

    return false;
}

BigInt BigInt::operator+(const BigInt &operand) const
{
    std::string left_number = getnumber();
    std::string right_number = operand.getnumber();
    char left_sign = getsign();
    char right_sign = operand.getsign();
    BigInt result("0");

    std::string sum = "";
    int64_t carry = 0;
    int64_t diff = 0;
    int64_t digit_sum = 0;

    while (left_number.size() < right_number.size())
        left_number.insert(left_number.begin(), '0');
    while (right_number.size() < left_number.size())
        right_number.insert(right_number.begin(), '0');

    if (left_sign == right_sign)
    {
        for (size_t i = left_number.size(); i > 0; --i)
        {
            digit_sum = (static_cast<int64_t>(left_number[i - 1] - '0')) + (static_cast<int64_t>(right_number[i - 1] - '0')) + carry; // static_cast<> is used to explicitly convert a value to a specific type and resolve implicit conversion errors reported by the compiler
            carry = digit_sum / 10;
            sum.insert(sum.begin(), static_cast<char>((digit_sum % 10) + '0'));
        }

        if (carry > 0)
            sum.insert(sum.begin(), static_cast<char>(carry + '0'));

        result.setnumber(sum);
        result.setsign(left_sign);
        return result;
    }

    if (left_sign == '+' && right_sign == '-')
    {
        if (left_number >= right_number)
        {
            for (size_t i = left_number.size(); i > 0; --i)
            {
                diff = (static_cast<int64_t>(left_number[i - 1] - '0')) - (static_cast<int64_t>(right_number[i - 1] - '0')) - carry;
                carry = 0;

                if (diff < 0)
                {
                    diff += 10;
                    carry = 1;
                }

                sum.insert(sum.begin(), static_cast<char>(diff + '0'));
            }

            result.setnumber(sum);
            result.setsign(left_sign);
            return result;
        }
        else
        {
            for (size_t i = right_number.size(); i > 0; --i)
            {
                diff = (static_cast<int64_t>(right_number[i - 1] - '0')) - (static_cast<int64_t>(left_number[i - 1] - '0')) - carry;
                carry = 0;

                if (diff < 0)
                {
                    diff += 10;
                    carry = 1;
                }

                sum.insert(sum.begin(), static_cast<char>(diff + '0'));
            }

            result.setnumber(sum);
            result.setsign(right_sign);
            return result;
        }
    }

    else if (left_sign == '-' && right_sign == '+')
    {
        if (left_number >= right_number)
        {
            for (size_t i = left_number.size(); i > 0; --i)
            {
                diff = (static_cast<int64_t>(left_number[i - 1] - '0')) - (static_cast<int64_t>(right_number[i - 1] - '0')) - carry;
                carry = 0;

                if (diff < 0)
                {
                    diff += 10;
                    carry = 1;
                }

                sum.insert(sum.begin(), static_cast<char>(diff + '0'));
            }

            result.setnumber(sum);
            result.setsign(left_sign);
            return result;
        }
        else
        {
            for (size_t i = right_number.size(); i > 0; --i)
            {
                diff = (static_cast<int64_t>(right_number[i - 1] - '0')) - (static_cast<int64_t>(left_number[i - 1] - '0')) - carry;
                carry = 0;

                if (diff < 0)
                {
                    diff += 10;
                    carry = 1;
                }

                sum.insert(sum.begin(), static_cast<char>(diff + '0'));
            }

            result.setnumber(sum);
            result.setsign(right_sign);
            return result;
        }
    }

    return result;
}

BigInt &BigInt::operator+=(const BigInt &operand)
{
    *this = *this + operand;
    return *this;
}

BigInt BigInt::operator-(const BigInt &operand) const
{

    return *this + (-operand);
}

BigInt &BigInt::operator-=(const BigInt &operand)
{
    *this = *this - operand;
    return *this;
}

BigInt BigInt::operator-() const
{
    BigInt negated = *this;

    if (negated.getsign() == '+')
        negated.setsign('-');
    else
        negated.setsign('+');

    return negated;
}

BigInt BigInt::operator*(const BigInt &operand) const
{
    std::string left_number = getnumber();
    std::string right_number = operand.getnumber();
    char left_sign = getsign();
    char right_sign = operand.getsign();
    BigInt result("0");
    char result_sign;
    int64_t product;

    if (left_sign == right_sign)
        result_sign = '+';
    else
        result_sign = '-';

    for (size_t i = right_number.size(); i > 0; --i)
    {
        std::string partial_result;
        int64_t carry = 0;

        partial_result.append((right_number.size() - i), '0'); // append zero to partial result in each iteration like grade school

        for (size_t j = left_number.size(); j > 0; --j)
        {

            product = (static_cast<int64_t>(left_number[j - 1] - '0')) * (static_cast<int64_t>(right_number[i - 1] - '0')) + carry;
            carry = product / 10;
            partial_result.insert(partial_result.begin(), static_cast<char>((product % 10) + '0'));
        }

        if (carry > 0)
        {
            partial_result.insert(partial_result.begin(), static_cast<char>(carry + '0'));
        }

        result = result + BigInt(partial_result);
    }

    result.setnumber(result.getnumber());
    result.setsign(result_sign);

    return result;
}

BigInt &BigInt::operator*=(const BigInt &operand)
{
    *this = *this * operand;
    return *this;
}

BigInt &BigInt::operator++()
{
    *this = *this + BigInt("1");
    return *this;
}

BigInt BigInt::operator++(int)
{
    BigInt result = *this;
    *this = *this + BigInt("1");
    return result;
}

BigInt &BigInt::operator--()
{
    *this = *this - BigInt("1");
    return *this;
}

BigInt BigInt::operator--(int)
{
    BigInt result = *this;
    *this = *this - BigInt("1");
    return result;
}

std::ostream &operator<<(std::ostream &out, const BigInt &bigint)
{
    if (bigint.getsign() == '+')
        out << "+" << bigint.getnumber();
    else if (bigint.getsign() == '-')
        out << "-" << bigint.getnumber();
    return out;
}

BigInt BigInt::operator/(const BigInt &operand) const
{

    BigInt dividend = *this;
    BigInt divisor = operand;
    BigInt quotient("0");
    BigInt remainder("0");
    char newsign;

    if (divisor.getsign() == dividend.getsign())
    {
        newsign = '+';
    }
    else
    {
        newsign = '-';
    }

    if (divisor == BigInt("0"))
    {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    else if (dividend == BigInt("0"))
    {
        BigInt result("0");
        result.setsign('+');
        return result;
    }
    else if (dividend.abs() == divisor.abs())
    {
        BigInt result("1");
        result.setsign(newsign);
        return result;
    }
    else if (divisor.abs() > dividend.abs())
    {
        BigInt result("0");
        result.setsign('+');
        return result;
    }

    if (dividend.abs() > divisor.abs())
    {

        for (char div : dividend.getnumber())
        {

            remainder = (remainder * BigInt("10")) + BigInt(std::to_string(div - '0')); // by multiplying the remainder by 10 in each iteration, its value is shifted left by one digit
            BigInt count("0");

            while (remainder.abs() >= divisor.abs())
            {
                remainder -= divisor.abs();
                count++;
            }

            quotient = quotient * BigInt("10") + count;
        }

        remainder.setsign(dividend.getsign());
        remainder.setnumber(remainder.getnumber());
        quotient.setsign(newsign);
        quotient.setnumber(quotient.getnumber());

        return quotient;
    }

    return BigInt("0"); 
}

BigInt &BigInt::operator/=(const BigInt &operand)
{

    *this = *this / operand;

    return *this;
}

BigInt BigInt::operator%(const BigInt &operand) const
{

    BigInt quotient = *this / operand;
    BigInt modulus = *this - (quotient * operand);

    if (modulus.getsign() == '-')
    {
        modulus = modulus + operand.abs(); // following the standard mathematical convention to ensure the modulus is non-negative
    }

    return modulus;
}

BigInt &BigInt::operator%=(const BigInt &operand)
{

    *this = *this % operand;

    return *this;
}