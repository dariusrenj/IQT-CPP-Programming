/*
CPP: Lab 1
- This is a very casual lab designed to introduce you to C++. Mess around with some of it's features we kind of
hinted at. 
- Ensure to set this up as a C++ project in Visual Studio or compile using G++ if using another editor or Linux
Instructions:
- A number is considered to be relatively prime to another if the greatest common denominator of both is 1.
- Euler's Totient Function – phi(n) – tallies up all the numbers that are relatively prime to a number n
- I have provided a program that implements Euler’s Totient Function to find a count of all numbers {1, 2, 3, …, n} that are relatively prime to a number n.
- Two functions to solve this problem have been provided but need to be completed, as well as a main().
-- int phi(unsigned int n) – this function should iterate through the number set to tally all numbers relative prime to n.
-- int gcd(const int, const int b) – this function should return the greatest common denominator of two numbers.
- Try using some of the new C++ features we covered. Experiment with auto, decltype, const, and references.
*/

#include <iostream>

int gcd(const int a, const int b);
int phi(unsigned int n);

int main()
{
    auto n = 0;
    for (n = 1; n <= 10; n++)
        printf("phi(%d) = %d\n", n, phi(n));

    return 0;
}

//Function: gcd()
//Arguments: const int a, const int b - two int arguments to determine the gcd of 
//Return value: the greatest common denominator of two numbers 
int gcd(const int a, const int b)
{
    int greatest_common_denominator;
    if (a > b)
    {
        for (int y = 1; y <= a; y++)
        {
            if (a%y == 0 && b%y == 0)
            {
                greatest_common_denominator = y;
            }
        }
    }
    
    else
    {
        for (int y = 1; y <= b; y++)
        {
            if (a%y == 0 && b%y == 0)
            {
                greatest_common_denominator = y;
            }
        }
    }
    return greatest_common_denominator;
}

//Function: phi()
//Arguments: unsigned int n - a number that we want to find all numbers relative prime to 
//Return: the count of all numbers relative prime to n 
int phi(unsigned int n)
{
    int count = 0;
    if (n == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (gcd(i, n)==1)
            {
                count++;
            }
        }
    }
    

    return count;
}