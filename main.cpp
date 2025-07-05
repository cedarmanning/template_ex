#include "header.h"

// MAIN
// Cedar Manning -- cedarman@pdx.edu
// PROGRAM #2 - CS302 - MAIN

// CONSTANTS
const int QUIT = 0;

// MENU FUNCTIONS

// returns the variable "choice", what the
// user wants to do according to the menu
int getchoice (int bound)
{
    int choice;
    cout << "Enter a number: ";
    cin >> choice;
    cin.ignore(100, '\n');

    while (choice < 0 && choice > bound)
    {
        cout << "Please enter a valid response: ";
        cin >> choice;
        cin.ignore(100, '\n');
    }
    return choice;
}

// simple print function to show the user
// what is available to them
void printMenu()
{
    cout << "0: Quit | 1: [Personal Client]  | 2: [Business Client] | 3: [Corporate Client] | 4: [Display ALL]" << endl;
    return;
}

void subMenu()
{
    cout << "0: Exit Submenu | 1: Insert Client | 2: Display Clients" << endl;
    return;
}

int main()
{
    int choice = -1;
    int choice2 = -1;

    vector<errorCode> errorList;

    DoublyLinkedList<Personal> personalList;
    DoublyLinkedList<Business> businessList;
    DoublyLinkedList<Corporate> corporateList;
    
    printMenu();
    choice = getchoice(5);

    while(choice != QUIT)
    {
        if(choice == 1)
        {
            // personal client
            Personal personalToAdd;
            subMenu();
            choice2 = getchoice(3);

            try
            {
                switch(choice2)
                {
                    case 1: personalToAdd.input(); personalList.insert(personalToAdd);
                    case 2: personalList.display();
                }
            }
            catch(const errorCode & code)
            {
                errorList.push_back(code);
            }

            printMenu();
            choice = getchoice(5);

        }
        if(choice == 2)
        {
            Business businessToAdd;
            subMenu();

            choice2 = getchoice(3);

            try
            {
                switch(choice2)
                {
                    case 1: businessToAdd.input(); businessList.insert(businessToAdd);
                    case 2: businessList.display();
                }
            }
            catch(const errorCode & code)
            {
                errorList.push_back(code);
            }


            printMenu();
            choice = getchoice(5);
        }
        if(choice == 3)
        {
            Corporate corporateToAdd;
            subMenu();

            choice2 = getchoice(3);

            try
            {
                switch(choice2)
                {
                    case 1: corporateToAdd.input(); corporateList.insert(corporateToAdd);
                    case 2: corporateList.display();
                }
            }
            catch(const errorCode & code)
            {
                errorList.push_back(code);
            }

            printMenu();
            choice = getchoice(5);
        }
        if(choice == 4)
        {
            personalList.display();
            businessList.display();
            corporateList.display();

            printMenu();
            choice = getchoice(5);
        }

    }

    if(!errorList.empty())
    {
        cout << "Errors Below: " << endl;
        for (const auto & e : errorList) cout << e.description << endl;
    }

    // goodbye message
    cout << "Bye Bye :)" << endl;


}
