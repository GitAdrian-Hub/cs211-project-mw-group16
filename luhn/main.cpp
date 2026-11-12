#include <iostream>
#include <string> //lets me declare a string variable 
#include "luhn.h" //includes header file
using namespace std;
int main ()
{
    string input;
    while (true) //infinite loop to allow the user to keep testing numbers
    {
        cout<<"enter 16 digit number, enter 'x' to end program"<<endl;
        getline(cin, input); //allows the program to read the users input up until the press enter then stores it into the input variable. used instead of cin>>input so if theres spaces they can be detected
        if (input == "x" || input == "X") //checks to see if user inputted any X
        {
            break; //ends program if the user inputs x
        }
        if(!validformat(input)) //brings the valid format function in, checks if it doesnt meet the criteria
        {
            cout<<"invalid format, 16 digits only and no spaces or letters"<<endl;
            continue; //returns back to the top of the loop to prompt the user again
        }
        if (checkluhn(input)) //checks if the luhn is true
        {
            cout<<"passes luhn check"<<endl;
        }
        else //to check if the checkluhn resulted in false
        {
            cout<<"fails luhn check"<<endl;
        }
        
    }
    
    return 0;
    
    
}
