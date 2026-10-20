//(Financial: credit card number validation) Credit card numbers follow certain
//patterns: It must have between 13 and 16 digits, and the number must start with:

//- 4 for Visa cards
//- 5 for MasterCard credit cards
//- 37 for American Express cards
//- 6 for Discover cards

//In 1954, Hans Luhn of IBM proposed an algorithm for validating credit card numbers.
//The algorithm is useful to determine whether a card number is entered correctly
//or whether a credit card is scanned correctly by a scanner. Credit card
//numbers are generated following this validity check, commonly known as the
//Luhn check or the Mod 10 check, which can be described as follows (for illustration,
//consider the card number 4388576018402626):

//1. Double every second digit from right to left. If doubling of a digit results in a
  // two-digit number, add up the two digits to get a single-digit number.

//![Credit Card](./credit_card.png)

//2. Now add all single-digit numbers from Step 1.
//3. Add all digits in the odd places from right to left in the card number.
//4. Sum the results from Steps 2 and 3.
//5. If the result from Step 4 is divisible by 10, the card number is valid; otherwise,
//it is invalid. For example, the number 4388576018402626 is invalid, but the
//number 4388576018410707 is valid.

//Write a program that prompts the user to enter a credit card number as an integer.
//Display whether the number is valid or invalid. Design your program to use the
//following functions:

//Return true if the card number is valid\
bool isValid(long long number);

//Get the result from Step 2\
int sumOfDoubleEvenPlace(long long number);

//Return this number if it is a single digit, otherwise, return the sum of the two digits\
int getDigit(int number);

//Return sum of odd place digits in number\
int sumOfOddPlace(long long number);

//Return true if the digit d is a prefix for number\
bool prefixMatched(long long number, int d);

//Return the number of digits in d\
int getSize(long long d);

//Return the first k number of digits from number. If the number of digits in number is less than k, return number.\
long long getPrefix(long long number, int k);
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function prototypes
vector<int> readCardNumber();
int getPrefix(vector<int> number, int k);
bool prefixMatched(vector<int> number);
int getSize(vector<int> number);
int sumOfOddPlace(vector<int> number);
int getDigit(int number);
int sumOfDoubleEvenPlace(vector<int> number);
bool isValid(vector<int> number);

// Return true if the credit card number is valid
bool isValid(vector<int> number)
{
    return ((sumOfDoubleEvenPlace(number) +
             sumOfOddPlace(number)) % 10 == 0)
           && prefixMatched(number)
           && getSize(number) >= 13
           && getSize(number) <= 16;
}

// Double digits in even positions and return their sum
int sumOfDoubleEvenPlace(vector<int> number)
{
    int sum = 0;

    // Start from the first digit and move by 2
    for (int i = 0; i < number.size() - 1; i += 2)
    {
        int digit = number[i];

        // Double the digit
        digit = digit * 2;

        // If result has two digits, add the two digits
        sum += getDigit(digit);
    }

    return sum;
}

// Return digit if single digit,
// otherwise return sum of the two digits
int getDigit(int number)
{
    if (number < 10)
        return number;
    else
        return number / 10 + number % 10;
}

// Return sum of digits in odd positions
int sumOfOddPlace(vector<int> number)
{
    int sum = 0;

    for (int i = 1; i < number.size(); i += 2)
    {
        sum += number[i];
    }

    return sum;
}

// Return number of digits
int getSize(vector<int> number)
{
    return number.size();
}

// Return true if card has a valid prefix
bool prefixMatched(vector<int> number)
{
    int prefix1 = getPrefix(number, 1);
    int prefix2 = getPrefix(number, 2);

    return prefix1 == 4 ||
           prefix1 == 5 ||
           prefix2 == 37 ||
           prefix1 == 6;
}

// Read credit card number
vector<int> readCardNumber()
{
    string number;

    cout << "Enter credit card number: ";
    cin >> number;

    vector<int> card_digits;

    for (size_t i = 0; i < number.length(); i++)
    {
        card_digits.push_back(number[i]- '0');
    }

    return card_digits;
}

// Return first k digits of the number
int getPrefix(vector<int> number, int k)
{
    int prefix = 0;

    int length = min(k, static_cast<int>(number.size()));

    for (int i = 0; i < length; i++)
    {
        prefix = prefix * 10 + number[i];
    }

    return prefix;
}

// Main function
int main()
{
    vector<int> number = readCardNumber();

    cout << "Prefix: " << getPrefix(number, 2) << endl;
    cout << "Matched: " << prefixMatched(number) << endl;
    cout << "Size: " << getSize(number) << endl;
    cout << "Sum of Odd Numbers: "
         << sumOfOddPlace(number) << endl;
    cout << "Sum of Double Even Numbers: "
         << sumOfDoubleEvenPlace(number) << endl;

    if (isValid(number))
        cout << "Valid credit card number." << endl;
    else
        cout << "Invalid credit card number." << endl;

    return 0;
}