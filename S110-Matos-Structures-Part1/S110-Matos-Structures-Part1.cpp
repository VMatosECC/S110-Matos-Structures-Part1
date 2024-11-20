// S110-Matos-Structures-Part1.cpp 

//Preprocessor declarations -------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//Structures --------------------------------------------
struct Person {
    string  name;
    string  email;
    int     age;
};

//Prototypes ---------------------------------------------
void experiment01();
void experiment02();
void experiment03();
void printPerson(Person p);
void printPerson(Person* p);
vector <Person> makeDatabaseFile();
void  findOldestYoungest(vector<Person>& vpeople, int& posOldest, int& posYoungest);
void sortPeopleFile(vector<Person>& v);


int main()
{
    //experiment01();
    experiment02();

    cout << "\nAll done!\n";
}


//----------------------------------------------------------
// User-defined functions
//----------------------------------------------------------

void experiment02()
{
    //Creating myPeople memory file
    vector<Person> vpeople = makeDatabaseFile();
    cout << "\nmyPeople Database File\n";
    for (Person p : vpeople) {
        printPerson(p);
    }
    //Show the oldest and youngest person from the database file
    int posOldest = 0;
    int posYoungest = 0;
    findOldestYoungest(vpeople, posOldest, posYoungest);
    cout << "The oldest person is: " << endl;
    printPerson(vpeople[posOldest]);

    cout << "The youngest person is: " << endl;
    printPerson(vpeople[posYoungest]);

    //List the three oldest/youngest people in the database file
    sortPeopleFile(vpeople);
    cout << "\nYoungest people (sample of size 3)\n";
    for (int i = 0; i < 3; i++) printPerson(vpeople[i]);
}
//--------------------------------------------------------=----
void sortPeopleFile(vector<Person>& v)
{
    //bubblesort approach
    for (int last = v.size() - 1; last > 0; last--) {
        for (int i = 0; i < last; i++)
        {
            if (v[i].age > v[i + 1].age) {
                Person temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
}


// --------------------------------------------------------------
void  findOldestYoungest(vector<Person>& v, int& posOldest, int& posYoungest)
{
    int maxAge = v[0].age;
    int minAge = v[0].age;
    for (int i = 1; i < v.size(); i++) {
        Person p = v[i];
        if (p.age > maxAge) {
            maxAge = p.age;
            posOldest = i;
        }
        if (p.age < minAge) {
            minAge = p.age;
            posYoungest = i;
        }
    }


}


//----------------------------------------------------------------
vector <Person> makeDatabaseFile() {
    ifstream myfile("c:/temp/mypeople.txt");
    if (!myfile) {
        cout << "FATAL ERROR - File not found\n";
        exit(1);
    }

    string n, e, astr;
    vector<Person> v;
    while (getline(myfile, n, ',')) {
        getline(myfile, e, ',');
        getline(myfile, astr);
        v.push_back(Person({ n, e, stoi(astr) }));
    }
    myfile.close();
    return v;
}






void experiment01() {
    Person p1;
    p1.name = "Bart Simpson";
    p1.email = "bs@gmail.com";
    p1.age = 10;

    printPerson(p1);

    Person p2({ "Lisa Simpson", "ls@gmail.com", 8 });
    printPerson(p2);

    vector<Person> simpsons{ p1, p2 };
    simpsons.push_back(Person({ "Homer Simpson", "hs@aol.com", 39 }));
    simpsons.push_back(Person({ "Marge Simpson", "ms@elcamino.edu", 36 }));
    simpsons.push_back(Person({ "Maggie Simpson", "none", 1 }));

    cout << "\nThe Simpsons: \n";
    for (Person p : simpsons)
    {
        printPerson(p);
    }

    cout << endl;
    Person* ptr1 = new Person({ "Peter Parker", "pp@gmail.com", 22 });
    printPerson(*ptr1);

    printPerson(ptr1);

}

void printPerson(Person p)
{
    cout << "Name: " << p.name
        << "\temail: " << p.email
        << "\tAge: " << p.age
        << endl;
}

void printPerson(Person* p)
{
    cout << "Name: " << p->name
        << "\temail: " << p->email
        << "\tAge: " << p->age
        << endl;
}