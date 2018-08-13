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
#include <string>
class Person{
private:
    int age;
    std::string first_name;
    std::string last_name;
    char gender;
public:
Person(int age, std::string first_name, std::string last_name, char gender)
    {
        this->age = age;
        this->first_name = first_name;
        this->last_name = last_name;
        this->gender = gender;
        
    }
    void set_values(int age, std::string first_name, std::string last_name, char gender);
~Person()
{
    
}
std::string firstN()
    {
        return first_name;
    }

   
    std::string lastN()
    {
        return last_name;
    }

    
    char get_gender()
    {
        return gender;
    }
    int get_age()
    {
        return age;
    }

    void set_first_name(std::string firstN)
    {
        this->first_name = firstN;
    }

    void set_last_name(std::string lastN)
    {
        this->last_name = lastN;
    }

    void set_gender(char gender)
    {
        this->gender = gender;
    }

    void set_age(int age)
    {
        this->age = age;
    }
};