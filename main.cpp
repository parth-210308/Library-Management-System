#include "Library.h"
#include <limits>

using namespace std;

int main()
{
    Library library;
    int choice;

    do
    {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Remove Book\n";
        cout << "5. Add Member\n";
        cout << "6. Display Member\n";
        cout << "7. Search Member\n";
        cout << "8. Remove Member\n";
        cout << "9. Exit\n";

        cout << "Enter choice : ";

        do
        {
            cin >> choice;

            if (cin.fail())
            {
                cout << "Please enter a valid number.\n";

                cin.clear();

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        } while (cin.fail());

        cout<<endl;
        
        switch (choice)
        {
        case 1:
            library.addBook();
            break;

        case 2:
            library.displayBooks();
            break;
        
        case 3:
            library.searchBook();
            break;
        
        case 4:
            library.removeBook();
            break;

        case 5:
            library.addMember();
            break;

        case 6:
            library.displayMembers();
            break;

        case 7:
            library.searchMember();
            break;
        
        case 8:
            library.removeMember();
            break;

        case 9:
            cout << "Goodbye!\n";
            break;
            
        default:
            cout << "Invalid Choice\n";
        }
    }while(choice!=9);

    return 0;
}