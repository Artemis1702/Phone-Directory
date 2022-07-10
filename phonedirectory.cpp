#include"phonedirectory.hpp"
void dlist::accept(const char* str)
{
    string number;
    string email;
    string name;
    string ans;
    do
    {
        cls;
        cout<<"Please Enter Contact Details For Your Phonebook!\n";
        cout<<"\nEnter Contact Name:      ";
        cin>>name;
        cout<<"Enter Contact Number:    ";
        cin>>number;
        while(number.length()!=10)
        {
            cout<<"Enter Valid Number:      ";
            cin>>number;
        }
        cout<<"Enter Contact E-mail ID: ";
        cin>>email;
        temp=new dnode(name,number,email);
        pushIntoFile(temp,str);
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->prev=ptr;
        }
        cout<<"\n\nDo You Want To Add More Contacts?\n";
        cin>>ans;
    }while((ans=="y")||(ans=="Y")||(ans=="Yes")||(ans=="yes"));

}
void dlist::display(const char* str)
{
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<"Contact Name:\t"<<ptr->name
            <<"\tContact Number:\t+91-"<<ptr->number
            <<"\tContact E-mail ID:\t"<<ptr->email<<endl<<endl;
        ptr=ptr->next;
    }
}

void dlist::pushIntoFile(dnode* ptr,const char* str)
{
    fstream file;
    file.open(str,ios::app);
    file<<"Contact Name:\t"<<ptr->name
        <<"\tContact Number:\t+91-"<<ptr->number
        <<"\tContact E-mail ID:\t"<<ptr->email<<endl<<endl;
    file.close();
}

void dlist::updateFile(const char* str,string s)
{
    fstream file1,file2;
    string st;
    file1.open(str);
    file2.open("temp.txt",ios::out);
    while(file1)
    {
        getline(file1,st);
        if(st.find(s)==string::npos)
        {
            file2<<st<<endl;
        }
    }
    file1.close();
    file2.close();
    remove(str);
    rename("temp.txt",str);
}

void dlist::insert(const char* str)
{
    accept(str);
}

void dlist::deleteContact(const char* str,string s)
{
    int i,loc=1;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->name==s)
        {
            break;
        }
        else
        {
            ptr=ptr->next;
            loc++;
        }
    }
    ptr=head;
    for(i=1;(ptr!=NULL)&&(i<loc);i++)
    {
        ptr=ptr->next;
    }
    if(head==NULL||ptr==NULL)
    {
        return;
    }
    if(head==ptr)
    {
        head=ptr->next;
    }
    if(ptr->next!=NULL)
    {
        ptr->next->prev=ptr->prev;
    }
    if(ptr->prev!=NULL)
    {
        ptr->prev->next=ptr->next;
    }
    delete(ptr);
    updateFile(str,s);
}
void dlist::deleteSameName(const char* str)
{
    ptr1=head;
    while(ptr1!=NULL&&ptr1->next!=NULL)
    {
        ptr2=ptr1;
        while(ptr2->next!=NULL)
        {
            if(ptr1->name==ptr2->next->name)
            {
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(dup);
            }
            else
            {
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}
void dlist::deleteSameEmail(const char* str)
{
    ptr1=head;
    while(ptr1!=NULL&&ptr1->next!=NULL)
    {
        ptr2=ptr1;
        while(ptr2->next!=NULL)
        {
            if(ptr1->email==ptr2->next->email)
            {
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(dup);
            }
            else
            {
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}
void dlist::deleteSameNumber(const char* str)
{
    ptr1=head;
    while(ptr1!=NULL&&ptr1->next!=NULL)
    {
        ptr2=ptr1;
        while(ptr2->next!=NULL)
        {
            if(ptr1->number==ptr2->next->number)
            {
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(dup);
            }
            else
            {
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}
void dlist::searchByName(string na)
{
    int co=0;
    ptr=head;
    while(ptr!=NULL)
    {
        if(na==ptr->name)
        {
            co++;
            cout<<"Found Contact Details For "<<na<<"!\t"
                <<"\tContact Name:\t"<<ptr->name
                <<"\tContact Number:\t+91-"<<ptr->number
                <<"\tContact E-mail ID:\t"<<ptr->email<<endl<<endl;
        }
        ptr=ptr->next;
    }
    if(co==0)
    {
        cout<<"No Contact Details Found For "<<na<<"!\n"<<endl;
    }
}
void dlist::searchByNumber(string num)
{
    int co=0;
    ptr=head;
    while(ptr!=NULL)
    {
        if(num==ptr->number)
        {
            co++;
            cout<<"Found Contact Details For "<<num<<"!\t"
                <<"\tContact Name:\t"<<ptr->name
                <<"\tContact Number:\t+91-"<<ptr->number
                <<"\tContact E-mail ID:\t"<<ptr->email<<endl<<endl;
        }
        ptr=ptr->next;
    }
    if(co==0)
    {
        cout<<"No Contact Details Found For "<<num<<"!\n"<<endl;
    }
}
void dlist::searchByEmail(string em)
{
    int co=0;
    ptr=head;
    while(ptr!=NULL)
    {
        if(em==ptr->email)
        {
            co++;
            cout<<"Found Contact Details For "<<em<<"!\t"
                <<"\tContact Name:\t"<<ptr->name
                <<"\tContact Number:\t+91-"<<ptr->number
                <<"\tContact E-mail ID:\t"<<ptr->email<<endl<<endl;
        }
        ptr=ptr->next;
    }
    if(co==0)
    {
        cout<<"No Contact Details Found For "<<em<<"!\n"<<endl;
    }
}
void dlist::update(const char* str,string n)
{
    string ans;
    int c;
    ptr=head;
    while(ptr!=NULL)
    {
        if(n==ptr->name)
        {
            do
            {
                cout<<"1. Update Name\n";
                cout<<"2. Update Number\n";
                cout<<"3. Update E-Mail ID\n";
                cin>>c;
                switch(c)
                {
                    case 1:
                        cout<<"Enter New Name: ";
                        cin>>ptr->name;
                        break;

                    case 2:
                        cout<<"Enter New Number: ";
                        cin>>ptr->number;
                        while(ptr->number.length()!=10)
                        {
                            cout<<"Enter Valid Number: ";
                            cin>>ptr->number;
                        }
                        break;

                    case 3:
                    cout<<"Enter New E-Mail ID: ";
                    cin>>ptr->email;
                    break;
                }
                cout<<"Do You Want To Update Any More Contact Details?\n";
                cin>>ans;
            }while((ans=="y")||(ans=="Y")||(ans=="Yes")||(ans=="yes"));
        }
        ptr=ptr->next;
    }
}
