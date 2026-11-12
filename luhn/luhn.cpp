#include "luhn.h"  //includes the stuff written in the header  
#include <cctype> //needed for character checking to use the isdigit code

using namespace std; //includes namespace std

bool validformat(const string& input) //uses the function to decide if the users input returns true or false
{
    if (input.length() != 16)
    {
        return false; //this if statement stops the program if the user does not input 16 digits
    }
    for (char d : input) //this loop checks every digit in the string 
    {
        if (!isdigit(d)) 
        {
            return false; //this if loop returns false if the user inputs anything that isnt a number for any part of the input
        }
    }
    return true; //the function is true if the user input matches both criteria 
}
bool checkluhn(const string& input) //uses other function from .h file 
{
    int sum = 0; //to keep track of the running total while calculating the luhn 
    for (int i =15; i>=0; --i)
    { //will check indexes 0-15 cuz a 16 digit would start at 0, will start from right and go left
         int digit = input[i] - '0'; //accesses the current index and uses ASCII values and subtraction with these values to get the actual value and store it into digit
         if (i % 2 == 0) //check if its even
         {
             digit = digit * 2; //this will only apply to every second digit moving from right to left like the luhn requires
             if (digit > 9) //luhn code requires that if a digit is multiplied to be 2 digits, those digits must be added
             {
                 digit = digit - 9; //subtracting 9 from the added digits will always result in the same result as adding the two numbers together. for example, 7 * 2 = 14. 1 + 4 is 5, and 14 - 9 is 5.
             }
         }
         sum = sum + digit; //adds the number to the sum regardless of if its even or not 
    }
    return (sum % 10 == 0); //only returns if the input divided by 10 has a remainder of 0
}

