// Phonebook Initial Code

// Day 3, Problem 1
// Phone book, STL vector...
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//struct for contact infos
struct Contact
{
    Contact(
        string firstName,
        string lastName,
        string phoneNumber
        ) : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber)
    {}
    string firstName;
    string lastName;
    string phoneNumber;
};
std::ostream& operator<<(std::ostream& out, Contact c)
{
    out << c.firstName << " " << c.lastName << " " << c.phoneNumber;
    return out;
}
class Phonebook
{
    std::vector<Contact> entries;
public:
    void addEntry(Contact contact) {
        this->entries.push_back(contact);
    }
    const std::vector<Contact>& getentries() const
    {
        return this->entries;
    }
    std::vector<Contact> search(std::string term) const
    {
        std::vector<Contact> result;
        return result;
    }
};
class PhonebookApp
{
    Phonebook phonebook;
public:
    static Contact readContact()
    {
        string FirstName;
        string LastName;
        string PhoneNumber;
        cout << "Read Contact : "  << std::endl;
        cout << "Please enter firstname : "  << std::endl;
        cin >> FirstName;
        cout << "The firstname entered is " << FirstName << std::endl;
        cout << "Please enter last name: "  << std::endl;
        cin >> LastName;
        cout << "The lastname entered is " << LastName << std::endl;
        cout << "Please enter phonenumber: "  << std::endl;
        cin >> PhoneNumber;
        cout << "The name you entered is " << PhoneNumber  << std::endl;
        Contact result(FirstName, LastName, PhoneNumber);
        return result;
    }
    void fillphonebook(const int contactInfos)
    {
        for (int i = 0; i < contactInfos; i++)
        {
            Contact c = PhonebookApp::readContact();
            phonebook.addEntry(c);
        }
    }
    //Lambda std::vector<PhonebookEntry> phonebook:: findmatches(std::string term)
    void menuphonebook()
    {
        //TODO: logic to check 1-6
        bool keepRunning = true;
        while(keepRunning){
            std::cout << "1) search" << std::endl;
            std::cout << "2) add new" << std::endl;
            std::cout << "3) update existing" << std::endl;
            std::cout << "4) delete" << std::endl;
            std::cout << "5) print all" << std::endl;
            std::cout << "6) quit" << std::endl;
            cout << "Enter the desired menu number ...." << std::endl;
            int choice;
            std::cin >> choice;
            switch(choice)
            {
            case 1:
                cout << "Entering search module ...."  << std::endl;
                searchphonebook();
                break;
            case 2:
                cout << "Entering add module ...."  << std::endl;
                this->fillphonebook(1);
                break;
            case 3:
                cout << "Entering update existing module ...."  << std::endl;
                //findmacthes
                updateEntry();
                break;
            case 4:
                cout << "Entering delete module ...."  << std::endl;
                break;
            case 5:
                cout << "Entering print all module ...."  << std::endl;
                this->printphonebook();
                break;
            case 6:
                cout << "Just Quit ...."  << std::endl;
                keepRunning = false;
                break;
            }
        }
    }
    void searchphonebook()
    {
        //Let the user to search some contact
        cout << "Enter the search module and  ...." << std::endl;
        cout << "Please enter your search term...." << std::endl;
        std::string searchTerm;
        std::cin >> searchTerm;
        bool found = false;
        for (int i = 0; i < phonebook.getentries().size(); i++)
        {
            // search the Contact and print the found contact name
            if (phonebook.getentries()[i].firstName == searchTerm)
            {
                found = true;
                cout << "Congrats, The contact you are searching is found: " << phonebook.getentries()[i] << std::endl;
            }
        }
        if (!found)
            cout << "Could not find contact ...." << std::endl;
    }
    void updateEntry()
    {
        //search to update the entry
        cout << "Enter the add update module and  ...." << std::endl;
        cout << "Please enter your search term...." << std::endl;
        std::string searchTerm;
        std::cin >> searchTerm;
        bool found = false;
        for (int i = 0; i < phonebook.getentries().size(); i++)
        {
            // search the Contact and print the found contact information
            if (phonebook.getentries()[i].firstName == searchTerm)
            {
                found = true;
                cout << "Congrats, The contact you are searching is found: " << phonebook.getentries()[i] << std::endl;
            }
            else
                //If the search entry not found then add that entry
                this->fillphonebook(1);
        }
    }
    void printphonebook()
    {
        for (int i = 0; i < phonebook.getentries().size(); i++)
        {
            cout << "Print phonebook contacts: " << phonebook.getentries()[i]<< std::endl;
        }
    }
};
int main ()
{
    PhonebookApp app;
    app.fillphonebook(1); // Fill the phonebook just once
    app.menuphonebook();
    PhonebookApp app2; // For the future TODO
    return 0;
}