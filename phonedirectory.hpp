#ifndef PHONEDIRECTORY_HPP_INCLUDED
#define PHONEDIRECTORY_HPP_INCLUDED
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>
#define cls system("cls")
using namespace std;
class dnode
{
    public:
    string number;
    string email;
    string name;
    char* nam;
    dnode *prev,*next;
    dnode(string n,string r,string e)
    {
        name=n;
        number=r;
        email=e;
        next=NULL;
        prev=NULL;
    }
	friend class dlist;
};
class dlist
{
    dnode *head,*temp,*ptr,*ptr1,*ptr2,*dup;
    public:
    dnode *prevn;
    void insert(const char*);
    void accept(const char*);
    void deleteContact(const char*,string);
    void deleteSameName(const char*);
    void deleteSameNumber(const char*);
    void deleteSameEmail(const char*);
    void searchByName(string);
    void searchByNumber(string);
    void searchByEmail(string);
    void display(const char*);
    void update(const char*,string);
    void updateFile(const char*,string);
    void pushIntoFile(dnode*,const char*);
    dlist()
    {
        head=NULL;
        temp=NULL;
        ptr=NULL;
        ptr1=NULL;
        ptr2=NULL;
        dup=NULL;
    }
};


#endif // PHONEDIRECTORY_HPP_INCLUDED
