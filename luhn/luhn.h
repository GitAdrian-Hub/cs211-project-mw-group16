#ifndef luhn_h 
#define luhn_h //these two lines prevent the code from reading at the same time so it wont crash
#include <string> //the 16 digit number must be read as a string
bool validformat(const std::string& input); //this makes sure that only an input of 16 numbers and nothing else is accepted
bool checkluhn(const std::string& input); //checks if the number passes the luhn formula

#endif


