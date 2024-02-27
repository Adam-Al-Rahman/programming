#include <iostream>

using std::cout;
using std::string;

namespace vrv_boys
{
    class Person;
};

class vrv_boys::Person
{
public:
    string name;
    string sex;

    Person(string name_val, string sex_val)
    {
        name = name_val;
        sex = sex_val;
    }

    const void details()
    {
        cout << "Name: " << name << "\n";
        cout << "Sex: " << sex;
    }
};

using vrv_boys::Person;

int main()
{
    Person piyush("Piyush", "Gay");
    piyush.details();
}