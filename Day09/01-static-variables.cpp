#include<iostream>
#include<string>
using namespace std;

// A Class Kaksha to store the details of the students of a particular kaksha and section. A single kaksha with a section can store a maximum of 35 students only.
class Kaksha{
    private:
        // Name of the student
        string name[35];

        // Roll no of the student
        int rollno[35];

        // gender of the student
        string gender[35];

        // A static count of students, which is basically the count of the all the students in the school (combined of all the kaksha)
        static int total_student_count;

        // Count of total students currently studying in a particular kaksha and section
        int kaksha_student_count;

    public:
        // A function to add details of new students
        void addDetails();

        // A function to fetch the details of existing students 
        void fetchtDetails();

        // A function to initialise the counter of students for a particular kaksha
        void initialiseStudentCount(){
            kaksha_student_count = 0;
        }
} ;

// static variable to hold the count of all the students combined from all tha kaksha of a school
int Kaksha :: total_student_count = 0;

// Definition of the fetchDetails() function
void Kaksha :: fetchtDetails()
{
    if (kaksha_student_count == 0){
        cout << "No students!" << endl ;
        cout << endl;
    }
    else{
        for (int i = 0; i < kaksha_student_count; i++)
        {
            cout << "Name of the student : " << name[i] << endl;
            cout << endl;
            cout << "Roll No. of the student : " << rollno[i] << endl;
            cout << endl;
            cout << "Gender : " << gender[i] << endl; 
            cout << endl;
        }
    }
}

// The definition of the addDetails() function
void Kaksha :: addDetails()
{
    cout << "Enter the details of student ~ " << endl;

    cout << "Name of the student : " << endl;
    cin >> name[kaksha_student_count];
    cout << endl;

    cout << "Enter the gender of the student : " << endl;
    cin >> gender[kaksha_student_count] ;
    cout << endl;

    cout << "Enter the roll no. of the student: " << endl;
    cin >> rollno[kaksha_student_count] ;
    cout << endl;

    kaksha_student_count++ ;
}

int choice;

// Menu functions()
// Main Menu Function
int mainMenu()
{
    cout << "Welcome to the Campus......" << endl;
    cout << "Visit a Kaksha ? The available Kaksha and their sections are as follows ~" << endl;
    cout << "Kaksha 1 - 12, each with 3 sections {A, B and C}" << endl;
    cout << "To visit a kaksha, enter 1 : ";
    cin >> choice;

    return choice;
}

// Kaksha Menu
int kakshaMenu()
{
    cout << "To see the students list, enter 1, " << endl; 
    cout << "To add a new student to the kaksha, enter 2, " << endl;
    cout << "To see the details of a specific student, enter 3" << endl;
    cout << "To exit, enter 0, " << endl;
    cin >> choice;

    return choice;
}

// Main function / Driver program
int main()
{
    // A class 12 B
    Kaksha TwelveB;

    int choice;

    // Menu
    cout << "Welcome to the Best School" << endl;
    cout << "To enter in the school, enter 1, else 0 : ";
    cin >> choice;

    if (choice == 1){
        choice = mainMenu();
        if (choice == 0){
            exit(0);
        }
        else{
            cout << "Enter the kaksha and section ~ \nfor example - to visit kaksha '12 B', input 122";
            cin >> choice;
            switch(choice){
                case 11:
                    cout << "Welcome to kaksha '1 B'" << endl;
                    choice = kakshaMenu();
                    break;
                case 12:
                    break;
                case 13:
                    break;
                case 21:
                    break;
                case 22:
                    break;
                case 23:
                    break;
            }
        }
    }
    else{
        cout << "Exiting from the school......" << endl;
        exit(0);
    }

    // TwelveB.initialiseStudentCount();
    // TwelveB.addDetails();
    // TwelveB.fetchtDetails();

    return 0;
}