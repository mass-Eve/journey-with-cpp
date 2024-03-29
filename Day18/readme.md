# This Is Day18 Of Learning C++
## *24 February 2024*

# Some Points To Be Noted While Inheriting Classes
- Visibility of the Class is kind of a parameter which basically is just like the *public* and *private* thing that we have inside a class.
- It defines how you are inheriting the members of the base class in your class! 

- ***Important Note : We can only inherit the public members of a class, we simply can't inherit the private members of a class.***

- If you want to inherit the public members of the base class as public members in your derived class, you use *public visibility*. 
- But if you want to inherit the public members of the base class as private members of your derived class, you use *private visibility*.

- The ***default visibility*** is *private*.

-----

# Creating Derived Classes
To create a derived class, or a class which is inheriting properties from another class (*base class*), we use the following syntax ~
```cpp
// Declare the base class
class <Base-Class-Name>{
    // body
};

// Declare the derived class
class <Derived-Class-Name> : <visibility-mode> <Base-Class-Name>{

};
```

-----

# Understanding The Concept Of Inheritance With Examples ~
To understand inheritance in the simplest form, lets divide it in two forms -:

**Case 1** : Base Class with private members

**Case 2** : Base Class with public members

## Case 1 Outline ~  
- We have created a `Employee` class and in that class we have created two private members.
- Next we have created a `Programmer` class, which is inheriting values from the `Employee` class. 
- The idea is that a company has many employees and each employee has a different department. Not every employee is a computer programmer, but every computer programmer (in that company specifically) is an Employee of that company.
- Utilising that idea, we have some general properties that every employee has and then we have some properties that are specific to the Programmer Employees.

### Example 1 ~
```cpp
#include<iostream>
#include<string>
using namespace std;

// Base class Employee
class Employee{
    private:
        string emp_name;
        int emp_id;
    public:
        // Empty construtor
        Employee(){
            cout << "New employee with garbage value has been created" << endl;
        }

        Employee(string name, int id){
            cout << "New employee with provided values has been created" << endl;
            emp_name = name;
            emp_id = id;
        }

        void displayData(){
            cout << "Employee name : " << emp_name << endl;
            cout << "Employee ID : " << emp_id << endl;
        }
};

// A Programmer class which is Derived from the Employee class 
//          OR
// A Company has an employee which is also a programmer, but not all the employees are programmer
class Programmer : Employee{
    private: 
        string programmingLanguage;
        int totalProjects;
    public:
        Programmer(){
            cout << "A programmer employee has been created with default values" << endl;
            programmingLanguage = "C";
            totalProjects = 5;
        }
        
        Programmer(string langName, int projectsCount){
            cout << "A programmer employee has been created with the passed values" << endl;
            programmingLanguage = langName;
            totalProjects = projectsCount;
        }

        void displayData(){
            cout << "Programming Language : " << programmingLanguage << endl;
            cout << "Total Projects Completed Till Noe : " << totalProjects << endl;
        }
};

int main()
{
    cout << "------------------------------------------------" << endl;
    cout << "Creating two Employees using the Employee class" << endl;
    Employee emp1("mona", 1245), emp2;
    cout << "------------------------------------------------" << endl;

    cout << endl;
    cout << "These are my regular employees" << endl;
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 1" << endl;
    emp1.displayData();
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 2" << endl;
    emp2.displayData();
    
    cout << "------------------------------------------------" << endl;
    cout << "Creating One Programmer Employee using the Programmer class" << endl;
    Programmer emp3("C", 5);
    cout << "------------------------------------------------" << endl;

    cout << "This is a programmer employee " << endl;
    emp3.displayData();
    cout << "------------------------------------------------" << endl;

    return 0;
}
```

### Output
```cmd
Creating two Employees using the Employee class
New employee with provided values has been created
New employee with garbage value has been created
------------------------------------------------

These are my regular employees
------------------------------------------------
Employee 1
Employee name : mona
Employee ID : 1245
------------------------------------------------
Employee 2
Employee name :
Employee ID : 1993577244
------------------------------------------------
Creating One Programmer Employee using the Programmer class
New employee with garbage value has been created
A programmer employee has been created with the passed values
------------------------------------------------
This is a programmer employee
Programming Language : C
Total Projects Completed Till Noe : 5
------------------------------------------------
```

- But as you can see, this program is running well. But ideally, it shouldn't! Because we are trying to inherit the private members of the `Employee` Class which is against the rules.
- On looking carefully, we can see that we are not actually accessing those private members of the Employee class, we are just accessing the members created inside the `Programmer` class. 

### Example 2 ~
- But if I try to access those private members, then it should raise appropriate errors ? Lets check this out .......
- In this example, we are adding one more member function inside our `Programmer` class, which is basically used to add the name and id of the programmer employee.

```cpp
#include<iostream>
#include<string>
using namespace std;

// Base class Employee
class Employee{
    private:
        string emp_name;
        int emp_id;
    public:
        // Empty construtor
        Employee(){
            cout << "New employee with garbage value has been created" << endl;
        }

        Employee(string name, int id){
            cout << "New employee with provided values has been created" << endl;
            emp_name = name;
            emp_id = id;
        }

        void displayData(){
            cout << "Employee name : " << emp_name << endl;
            cout << "Employee ID : " << emp_id << endl;
        }
};

// A Programmer class which is Derived from the Employee class 
//          OR
// A Company has an employee which is also a programmer, but not all the employees are programmer
class Programmer : Employee{
    private: 
        string programmingLanguage;
        int totalProjects;
    public:
        Programmer(){
            cout << "A programmer employee has been created with default values" << endl;
            programmingLanguage = "C";
            totalProjects = 5;
        }
        
        Programmer(string langName, int projectsCount){
            cout << "A programmer employee has been created with the passed values" << endl;
            programmingLanguage = langName;
            totalProjects = projectsCount;
        }

        void setEmployeeDetails(string name, int id){
            emp_name = name;
            emp_id = id;
        }

        void displayData(){
            cout << "Programming Language : " << programmingLanguage << endl;
            cout << "Total Projects Completed Till Noe : " << totalProjects << endl;
        }
};

int main()
{
    cout << "------------------------------------------------" << endl;
    cout << "Creating two Employees using the Employee class" << endl;
    Employee emp1("mona", 1245), emp2;
    cout << "------------------------------------------------" << endl;

    cout << endl;
    cout << "These are my regular employees" << endl;
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 1" << endl;
    emp1.displayData();
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 2" << endl;
    emp2.displayData();
    
    cout << "------------------------------------------------" << endl;
    cout << "Creating One Programmer Employee using the Programmer class" << endl;
    Programmer emp3("C", 5);
    cout << "------------------------------------------------" << endl;

    cout << "This is a programmer employee " << endl;
    emp3.displayData();
    cout << "------------------------------------------------" << endl;

    return 0;
}
```

### Output
```cmd
02-inheritance.cpp: In member function 'void Programmer::setEmployeeDetails(std::__cxx11::string, int)':
02-inheritance.cpp:49:13: error: 'std::__cxx11::string Employee::emp_name' is private within this context
             emp_name = name;
             ^~~~~~~~
02-inheritance.cpp:8:16: note: declared private here
         string emp_name;
                ^~~~~~~~
02-inheritance.cpp:50:13: error: 'int Employee::emp_id' is private within this context
             emp_id = id;
             ^~~~~~
02-inheritance.cpp:9:13: note: declared private here
         int emp_id;
             ^~~~~~
```

- But as you can see, without even calling that function, the compiler is giving an error
- Now this completely proves that *"private employees are not inherited at all."*

### Example 3 ~
- What if I create this `setEmployeeDetails()` function in the public section of the base class `Employee` instead of this `Programmer` class, will that work ? 
- Ideally, it should work because, since the function is now in the public scope of the base class, and all the elements of base class are inherited, isn't it ?

- Lets try this out ......

```cpp
#include<iostream>
#include<string>
using namespace std;

// Base class Employee
class Employee{
    private:
        string emp_name;
        int emp_id;
    public:
        // Empty construtor
        Employee(){
            cout << "New employee with garbage value has been created" << endl;
        }

        Employee(string name, int id){
            cout << "New employee with provided values has been created" << endl;
            emp_name = name;
            emp_id = id;
        }

        void displayData(){
            cout << "Employee name : " << emp_name << endl;
            cout << "Employee ID : " << emp_id << endl;
        }

        void setEmployeeDetails(string name, int id){
            emp_name = name;
            emp_id = id;
        }
};

// A Programmer class which is Derived from the Employee class 
//          OR
// A Company has an employee which is also a programmer, but not all the employees are programmer
class Programmer : Employee{
    private: 
        string programmingLanguage;
        int totalProjects;
    public:
        Programmer(){
            cout << "A programmer employee has been created with default values" << endl;
            programmingLanguage = "C";
            totalProjects = 5;
        }
        
        Programmer(string langName, int projectsCount){
            cout << "A programmer employee has been created with the passed values" << endl;
            programmingLanguage = langName;
            totalProjects = projectsCount;
        }

        void displayData(){
            cout << "Programming Language : " << programmingLanguage << endl;
            cout << "Total Projects Completed Till Noe : " << totalProjects << endl;
        }
};

int main()
{
    cout << "------------------------------------------------" << endl;
    cout << "Creating two Employees using the Employee class" << endl;
    Employee emp1("mona", 1245), emp2;
    cout << "------------------------------------------------" << endl;

    cout << endl;
    cout << "These are my regular employees" << endl;
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 1" << endl;
    emp1.displayData();
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 2" << endl;
    emp2.displayData();
    
    cout << "------------------------------------------------" << endl;
    cout << "Creating One Programmer Employee using the Programmer class" << endl;
    Programmer emp3("C", 5);
    cout << "------------------------------------------------" << endl;

    cout << "This is a programmer employee " << endl;
    emp3.displayData();
    cout << "------------------------------------------------" << endl;

    cout << endl;

    cout << "------------------------------------------------" << endl;
    cout << "Trying to add name and ID of the programmer employee " <<  endl;
    emp3.setEmployeeDetails("Christine", 45);

    return 0;
}
```

### Output
Wait, again !

```cmd
03-inheritance.cpp: In function 'int main()':
03-inheritance.cpp:88:44: error: 'void Employee::setEmployeeDetails(std::__cxx11::string, int)' is inaccessible within this context
     emp3.setEmployeeDetails("Christine", 45);
                                            ^
03-inheritance.cpp:27:14: note: declared here
         void setEmployeeDetails(string name, int id){
              ^~~~~~~~~~~~~~~~~~
03-inheritance.cpp:88:44: error: 'Employee' is not an accessible base of 'Programmer'
     emp3.setEmployeeDetails("Christine", 45);
```

We got another error. Maybe this was because *by default, all the inheritance is private, if we don't mention it externally.* Lets try again by changing that as well.

## Example 4 ~
- This time we are changing the visibility of inheritance from private to public. Lets see if that work......
- While doing this, I saw an ambiguity in the program which might can result in undesired value. We are having two `displayData()` member functions, one unique to the base class and other unique to derived class. So for the derived class, I have changed it to `displayDataProgrammer()` to avoid ambiguity.

```cpp
#include<iostream>
#include<string>
using namespace std;

// Base class Employee
class Employee{
    private:
        string emp_name;
        int emp_id;
    public:
        // Empty construtor
        Employee(){
            cout << "New employee with garbage value has been created" << endl;
        }

        Employee(string name, int id){
            cout << "New employee with provided values has been created" << endl;
            emp_name = name;
            emp_id = id;
        }

        void displayData(){
            cout << "Employee name : " << emp_name << endl;
            cout << "Employee ID : " << emp_id << endl;
        }

        void setEmployeeDetails(string name, int id){
            emp_name = name;
            emp_id = id;
        }
};

// A Programmer class which is Derived from the Employee class 
//          OR
// A Company has an employee which is also a programmer, but not all the employees are programmer
class Programmer : public Employee{
    private: 
        string programmingLanguage;
        int totalProjects;
    public:
        Programmer(){
            cout << "A programmer employee has been created with default values" << endl;
            programmingLanguage = "C";
            totalProjects = 5;
        }
        
        Programmer(string langName, int projectsCount){
            cout << "A programmer employee has been created with the passed values" << endl;
            programmingLanguage = langName;
            totalProjects = projectsCount;
        }

        void displayDataProgrammer(){
            cout << "Programming Language : " << programmingLanguage << endl;
            cout << "Total Projects Completed Till Noe : " << totalProjects << endl;
        }
};

int main()
{
    cout << "------------------------------------------------" << endl;
    cout << "Creating two Employees using the Employee class" << endl;
    Employee emp1("mona", 1245), emp2;
    cout << "------------------------------------------------" << endl;

    cout << endl;
    cout << "These are my regular employees" << endl;
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 1" << endl;
    emp1.displayData();
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 2" << endl;
    emp2.displayData();
    
    cout << "------------------------------------------------" << endl;
    cout << "Creating One Programmer Employee using the Programmer class" << endl;
    Programmer emp3("C", 5);
    cout << "------------------------------------------------" << endl;

    cout << "This is a programmer employee " << endl;
    emp3.displayData();
    cout << "------------------------------------------------" << endl;

    cout << endl;

    cout << "------------------------------------------------" << endl;
    cout << "Trying to add name and ID of the programmer employee " <<  endl;
    emp3.setEmployeeDetails("Christine", 45);
    emp3.displayData();
    emp3.displayDataProgrammer();

    return 0;
}
```

### Output
And here we go...... No Errors at all .......

```cpp
------------------------------------------------
Creating two Employees using the Employee class
New employee with provided values has been created
New employee with garbage value has been created
------------------------------------------------

These are my regular employees
------------------------------------------------
Employee 1
Employee name : mona
Employee ID : 1245
------------------------------------------------
Employee 2
Employee name :
Employee ID : 4199136
------------------------------------------------
Creating One Programmer Employee using the Programmer class
New employee with garbage value has been created
A programmer employee has been created with the passed values
------------------------------------------------
This is a programmer employee
Employee name :
Employee ID : 0
------------------------------------------------

------------------------------------------------
Trying to add name and ID of the programmer employee
Employee name : Christine
Employee ID : 45
Programming Language : C
Total Projects Completed Till Noe : 5
```

----

## *Now it is pretty clear that If we want to access the private elements of the base class, we have to create a public function in the base class only, which can manipulate those private members on the behalf of the derived class. Also, we have to change the inheritance visibility to public. Then only we can suppose to do this.*

-----

## Case 2 Outline ~
Now lets understand things with the perspective of public members of the base class.
- The whole scenario is same except that this time the members ***(name and id)*** of the base class are in public domain.

### Example 1 ~
Here we are trying to acess the public members ***(name and id)*** and we are expecting that we can do that because obviously public members are inherited na.

```cpp
#include<iostream>
#include<string>
using namespace std;

// Base class Employee
class Employee{
    public:

        // Employee Name
        string emp_name;

        // Employee ID no.
        int emp_id;

        // Default construtor
        Employee(){
            cout << "New employee with garbage value has been created" << endl;
        }

        // Parameterised Constructor
        Employee(string name, int id){
            cout << "New employee with provided values has been created" << endl;
            emp_name = name;
            emp_id = id;
        }

        // A function to display data
        void displayData(){
            cout << "Employee name : " << emp_name << endl;
            cout << "Employee ID : " << emp_id << endl;
        }
};

// A Programmer class which is Derived from the Employee class 
//          OR
// A Company has an employee which is also a programmer, but not all the employees are programmer
class Programmer : Employee{
    private: 
        string programmingLanguage;
        int totalProjects;
    public:
        Programmer(){
            cout << "A programmer employee has been created with default values" << endl;
            programmingLanguage = "C";
            totalProjects = 5;
        }
        
        Programmer(string langName, int projectsCount){
            cout << "A programmer employee has been created with the passed values" << endl;
            programmingLanguage = langName;
            totalProjects = projectsCount;
        }

        void displayData(){
            cout << "Programming Language : " << programmingLanguage << endl;
            cout << "Total Projects Completed Till Noe : " << totalProjects << endl;
        }
};

int main()
{
    cout << "------------------------------------------------" << endl;
    cout << "Creating one Employee using the Employee class" << endl;
    Employee emp1("mona", 1245);
    cout << "------------------------------------------------" << endl;

    cout << endl;
    cout << "These are my regular employees" << endl;
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 1" << endl;
    emp1.displayData();

    cout << "------------------------------------------------" << endl;
    cout << "Creating One Programmer Employee using the Programmer class" << endl;
    Programmer emp2("C", 5);
    cout << "------------------------------------------------" << endl;

    cout << "This is a programmer employee " << endl;
    emp2.displayData();
    cout << "------------------------------------------------" << endl;

    cout << endl;

    cout << "------------------------------------------------" << endl;
    cout << "Accesing the name and id of the employee ~ " << endl;
    emp1.emp_name = "Nishant";
    emp1.emp_id = 22;
    emp1.displayData();
    cout << "------------------------------------------------" << endl;

    cout << endl;

    cout << "------------------------------------------------" << endl;
    cout << "Trying to assign name and id to a programmer employee ~" << endl;
    emp2.emp_name = "Shantanu";
    emp2.emp_id = 50;
    emp2.displayData();

    return 0;
}
```

### Output
```cmd
01-inheritance.cpp: In function 'int main()':
01-inheritance.cpp:95:10: error: 'std::__cxx11::string Employee::emp_name' is inaccessible within this context
     emp2.emp_name = "Shantanu";
          ^~~~~~~~
01-inheritance.cpp:10:16: note: declared here
         string emp_name;
                ^~~~~~~~
01-inheritance.cpp:96:10: error: 'int Employee::emp_id' is inaccessible within this context
     emp2.emp_id = 50;
          ^~~~~~
01-inheritance.cpp:13:13: note: declared here
         int emp_id;
```

But as you see, the output has disappointed. Again we are doing a mistake.

## *From the above example, it is pretty clear that if the inheritance is private, then even the public members of the base class are inherited as private members of the derived class.*

### Example 2 ~
- This time, what we are actually doing is that, we are creating a new member function, `addData()` function to add the programmer employee name, and ID. Becuase in this case, the employee name and ID are accessible to us, but the only thing which is preventing us from accessing them is that they are in the private section of our `Programmer` class.
- That is why, we have created an `addData()` function to access them inside the `Programmer` class.
- Also there is one more problem, since all the things are coming as private members in the derived class, the `displayData()` function, which is displaying the employee name and ID, is also in the private domain.
- To resolve this, we have made two changes.
  - first of all, just to that ambiguity situation (as before), we have changed the name of the `displayData()` unique to `Programmer` class to `displayDataProgrammer()` function.
  - second, we are creating a new function `displayDataProgrammer2()` function, which will be used to print them on the terminal.
- Thats it... Now lets see if that all is actually working or not!

```cpp
#include<iostream>
#include<string>
using namespace std;

// Base class Employee
class Employee{
    public:
        // Employee Name
        string emp_name;

        // Employee ID no.
        int emp_id;

        // Default construtor
        Employee(){
            cout << "New employee with garbage value has been created" << endl;
        }

        // Parameterised Constructor
        Employee(string name, int id){
            cout << "New employee with provided values has been created" << endl;
            emp_name = name;
            emp_id = id;
        }

        // A function to display data
        void displayData(){
            cout << "Employee name : " << emp_name << endl;
            cout << "Employee ID : " << emp_id << endl;
        }
};

// A Programmer class which is Derived from the Employee class 
//          OR
// A Company has an employee which is also a programmer, but not all the employees are programmer
class Programmer : Employee{
    private: 
        string programmingLanguage;
        int totalProjects;
    public:
        Programmer(){
            cout << "A programmer employee has been created with default values" << endl;
            programmingLanguage = "C";
            totalProjects = 5;
        }
        
        Programmer(string langName, int projectsCount){
            cout << "A programmer employee has been created with the passed values" << endl;
            programmingLanguage = langName;
            totalProjects = projectsCount;
        }

        void displayDataProgrammer(){
            cout << "Programming Language : " << programmingLanguage << endl;
            cout << "Total Projects Completed Till Noe : " << totalProjects << endl;
        }

        void displayDataProgrammer2(){
            cout << "Employee name : " << emp_name << endl;
            cout << "Employee ID : " << emp_id << endl;
        }

        void addData(string name, int id){
            emp_name = name;
            emp_id = id;
        }
};

int main()
{
    cout << "------------------------------------------------" << endl;
    cout << "Creating one Employee using the Employee class" << endl;
    Employee emp1("mona", 1245);
    cout << "------------------------------------------------" << endl;

    cout << endl;
    cout << "These are my regular employees" << endl;
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 1" << endl;
    emp1.displayData();

    cout << "------------------------------------------------" << endl;
    cout << "Creating One Programmer Employee using the Programmer class" << endl;
    Programmer emp2("C", 5);
    cout << "------------------------------------------------" << endl;

    cout << "This is a programmer employee " << endl;
    emp2.displayDataProgrammer();
    cout << "------------------------------------------------" << endl;

    cout << endl;

    cout << "------------------------------------------------" << endl;
    cout << "Accesing the name and id of the employee ~ " << endl;
    emp1.emp_name = "Nishant";
    emp1.emp_id = 22;
    emp1.displayData();
    cout << "------------------------------------------------" << endl;

    cout << endl;

    cout << "------------------------------------------------" << endl;
    cout << "Trying to assign name and id to a programmer employee ~" << endl;
    emp2.addData("Shantanu", 50);
    // emp2.emp_name = "Shantanu";
    // emp2.emp_id = 50;
    emp2.displayDataProgrammer();
    emp2.displayDataProgrammer2();

    return 0;
}
```

### Output ~

```cmd
------------------------------------------------
Creating one Employee using the Employee class
New employee with provided values has been created
------------------------------------------------

These are my regular employees
------------------------------------------------
Employee 1
Employee name : mona
Employee ID : 1245
------------------------------------------------
Creating One Programmer Employee using the Programmer class
New employee with garbage value has been created
A programmer employee has been created with the passed values
------------------------------------------------
This is a programmer employee
Programming Language : C
Total Projects Completed Till Noe : 5
------------------------------------------------

------------------------------------------------
Accesing the name and id of the employee ~
Employee name : Nishant
Employee ID : 22
------------------------------------------------

------------------------------------------------
Trying to assign name and id to a programmer employee ~
Programming Language : C
Total Projects Completed Till Noe : 5
Employee name : Shantanu
Employee ID : 50
```

So Yes, it is working.

## Example 3 ~
- What if we just make the inheritance public ?
- I hope all the problems will be solved.

```cpp
#include<iostream>
#include<string>
using namespace std;

// Base class Employee
class Employee{
    public:

        // Employee Name
        string emp_name;

        // Employee ID no.
        int emp_id;

        // Default construtor
        Employee(){
            cout << "New employee with garbage value has been created" << endl;
        }

        // Parameterised Constructor
        Employee(string name, int id){
            cout << "New employee with provided values has been created" << endl;
            emp_name = name;
            emp_id = id;
        }

        // A function to display data
        void displayData(){
            cout << "Employee name : " << emp_name << endl;
            cout << "Employee ID : " << emp_id << endl;
        }
};

// A Programmer class which is Derived from the Employee class 
//          OR
// A Company has an employee which is also a programmer, but not all the employees are programmer
class Programmer : public Employee{
    private: 
        string programmingLanguage;
        int totalProjects;
    public:
        Programmer(){
            cout << "A programmer employee has been created with default values" << endl;
            programmingLanguage = "C";
            totalProjects = 5;
        }
        
        Programmer(string langName, int projectsCount){
            cout << "A programmer employee has been created with the passed values" << endl;
            programmingLanguage = langName;
            totalProjects = projectsCount;
        }

        void displayDataProgrammer(){
            cout << "Programming Language : " << programmingLanguage << endl;
            cout << "Total Projects Completed Till Now : " << totalProjects << endl;
        }
};

int main()
{
    cout << "------------------------------------------------" << endl;
    cout << "Creating one Employee using the Employee class" << endl;
    Employee emp1("mona", 1245);
    cout << "------------------------------------------------" << endl;

    cout << endl;
    cout << "These are my regular employees" << endl;
    cout << "------------------------------------------------" << endl;
    cout <<  "Employee 1" << endl;
    emp1.displayData();

    cout << "------------------------------------------------" << endl;
    cout << "Creating One Programmer Employee using the Programmer class" << endl;
    Programmer emp2("C", 5);
    cout << "------------------------------------------------" << endl;

    cout << "This is a programmer employee " << endl;
    emp2.displayData();
    cout << "------------------------------------------------" << endl;

    cout << endl;

    cout << "------------------------------------------------" << endl;
    cout << "Accesing the name and id of the employee ~ " << endl;
    emp1.emp_name = "Nishant";
    emp1.emp_id = 22;
    emp1.displayData();
    cout << "------------------------------------------------" << endl;

    cout << endl;

    cout << "------------------------------------------------" << endl;
    cout << "Trying to assign name and id to a programmer employee ~" << endl;
    emp2.emp_name = "Shantanu";
    emp2.emp_id = 50;
    emp2.displayData();
    emp2.displayDataProgrammer();

    return 0;
}
```

```cmd
------------------------------------------------
Creating one Employee using the Employee class
New employee with provided values has been created
------------------------------------------------

These are my regular employees
------------------------------------------------
Employee 1
Employee name : mona
Employee ID : 1245
------------------------------------------------
Creating One Programmer Employee using the Programmer class
New employee with garbage value has been created
A programmer employee has been created with the passed values
------------------------------------------------
This is a programmer employee
Employee name :
Employee ID : 4199136
------------------------------------------------

------------------------------------------------
Accesing the name and id of the employee ~
Employee name : Nishant
Employee ID : 22
------------------------------------------------

------------------------------------------------
Trying to assign name and id to a programmer employee ~
Employee name : Shantanu
Employee ID : 50
Programming Language : C
Total Projects Completed Till Now : 5
```

Guess what. Success......