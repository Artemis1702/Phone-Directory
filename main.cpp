#include"phonedirectory.hpp"
using namespace std;
int main()
{
    string n;
    char nam[20];
    string name;
    string number;
    string email;
    dlist d1;
    string ans;
    int ch,a;
    cout<<"Please Enter Username: ";
    cin>>nam;
    name=nam;
    const char* str=strcat(nam,".txt");
    cls;
    d1.accept(str);
    do
    {
        cout<<"1. Display All Your Contacts\n";
        cout<<"2. Add A New Contact\n";
        cout<<"3. Update Existing Contact Details\n";
        cout<<"4. Delete A Contact\n";
        cout<<"5. Delete Duplicate Names In Your Phonebook\n";
        cout<<"6. Delete Duplicate Numbers In Your Phonebook\n";
        cout<<"7. Delete Duplicate E-Mail IDs In Your Phonebook\n";
        cout<<"8. Search For A Contact\n";
        cin>>ch;
        cls;
        switch(ch)
        {
            case 1:
                cls;
                d1.display(str);
                break;

            case 2:
                cls;
                d1.insert(str);
                break;

            case 3:
                cls;
                cout<<"Enter The Contact Name You Would Like To Update: ";
                cin>>n;
                d1.update(str,n);
                break;

            case 4:
                cls;
                cout<<"Enter The Contact Name You Would Like To Delete: ";
                cin>>name;
                d1.deleteContact(str,name);
                break;

            case 5:
                cls;
                d1.deleteSameName(str);
                break;

            case 6:
                cls;
                d1.deleteSameNumber(str);
                break;

            case 7:
                cls;
                d1.deleteSameEmail(str);
                break;

            case 8:
                cls;
                do
                {
                    cout<<"1. Search By Name\n";
                    cout<<"2. Search By Number\n";
                    cout<<"3. Search By E-Mail ID\n";
                    cin>>a;
                    cls;
                    switch(a)
                    {
                        case 1:
                            cout<<"Enter Name To Be Searched\n";
                            cin>>name;
                            d1.searchByName(name);
                            break;

                        case 2:
                            cout<<"Enter Number To Be Searched\n";
                            cin>>number;
                            d1.searchByNumber(number);
                            break;

                        case 3:
                            cout<<"Enter E-Mail ID To Be Searched\n";
                            cin>>email;
                            d1.searchByEmail(email);
                        break;

                        default:cout<<"Invalid Input\n";
                    }
                    cout<<"Do You Want To Search For More Contacts?\n";
                    cin>>ans;
                }while((ans=="y")||(ans=="Y")||(ans=="Yes")||(ans=="yes"));
                break;

            default:
                cls;
                cout<<"Invalid Input\n";
        }
        cout<<"Do You Want To Continue?\n";
        cin>>ans;
        cls;
    }while((ans=="y")||(ans=="Y")||(ans=="Yes")||(ans=="yes"));
    cout<<str;
}
