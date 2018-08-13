/*
Inside of **person.h **design a class Person, that has private data members for first name, last name, age and gender.
Implement public functions to get and set the values of these private data members (example: std::string getFname(),
 void setName(std::string fName), as well as your constructor(s) and destructor.
Inside of main.cpp, you will find the function, **generate_roster() **that you will need to write. This funciton will
recieve user input to populate an array of Person objects, with each person being an individual in the class roster. 
Return the number of students recorded.
You will also find a function called **log_roster(). **Write this function to print each user out to roster.txt.
Compile person.h and roster.cpp into an executable to test your work.
If you are lost, please reach out for help.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "person.h"

//declare functions and variables
int log_roster(std::vector<Person>& , std::ofstream& );
int generate_roster(std::vector<Person>&);
int count1 = 0;

int main()
{
    //declare variables
    std::ofstream outfile("roster.txt");
    std::vector<Person> roster;

    int roster_size = generate_roster(roster);
    int logged_count = log_roster(roster, outfile);

    if(roster_size == logged_count)
        std::cout<<"Roster logged successfully"; <<std::endl;
    else
        std::cout<<"Roster size and logged count mismatch. Error!" << std::endl;

    roster.clear();
    outfile.close();
    return 0;
    
}
//Arguments: std::vector<person>& roster - reference a vector containing the list of students in the class
//           std::ofstream& - a reference to the ofstream outfile object you will write too 
//Returns:  int count of the number of records written out 
//Purpose: write out the logic
int log_roster(std::vector<Person>& roster, std::ofstream& outfile)
{
    //declare count
    int count = 0;
    //check if the file exists
    if (outfile.is_open())
    {
        //write roster to file
        for (int i=0; i < roster.size(); i++)
        {
            outfile << roster[i].firstN() << " " << roster[i].lastN() << " " << roster[i].get_age() << " " << roster[i].get_gender() << std::endl;
            count++;
        }
        return count;
    }
    else
    {
        std::cout << "Unable to open file…";
        return -1;
    }
}

//Arguments: std::vector<Person>& roster - a reference to a vector that will contain the students you input 
//Returns: int count of the number of records input 
//Purpose: receive input and load the vector 
int generate_roster(std::vector<Person>& roster)
{
    //declare variables
    int age;
    std::string firstN, lastN;
    char gender, more_people;
    Person new_person (age, firstN, lastN, gender);

    //ask for user input
    std::cout << "How old is the person?" << std::endl;
    std::cin >> age;
    std::cout << "What is the person's first name?" << std::endl;
    std::cin >> firstN;
    std::cout << "What is the person's last name?" << std::endl;
    std::cin >> lastN;
    std::cout << "What is the person's gender?" << std::endl;
    std::cin >> gender;
    new_person.set_first_name(firstN);
    new_person.set_last_name(lastN);
    new_person.set_gender(gender);
    new_person.set_age(age);
    roster.push_back(new_person);
    count1++;

    //ask if the user would like to input another person
    std::cout << "Would you like to input another person?(Y/N)\n" << std::endl;
    std::cin >> more_people;

    //if the user wants to add additional numbers, call the function again
    if (more_people == 'Y' || more_people == 'y')
    {
        generate_roster(roster);
        return count1;
        
    }
    //if the user doesn't want to add additional numbers, return to menu
    else if (more_people == 'N' || more_people == 'n')
    {
        return count1;
    }
    //error
    else
    {
        return -1;
    }

}