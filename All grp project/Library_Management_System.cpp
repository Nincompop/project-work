#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class Lib
{
   public:
       char bookname[100],auname[50],sc[20],sc1[50];
       int q,B,p;
       Lib()
       {
           strcpy(bookname,"NO Book Name");
           strcpy(auname,"No Author Name");
           strcpy(sc,"No Book ID");
           q=0;
           B=0;
           p=0;
       }
          void get();
          void student();
          void librarian();
          void getdata();
          void show(int);
          void booklist(int);
          void modify();
          void see(int);
          void issue();
          void der(char[],int);
          void retrn(int,int,int,int,int,int);
};
void Lib::getdata()
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tEnter the details :-\n";
                    cout<<"\n\t\tEnter Book's Name : ";
                    cin.getline(bookname,100);
                    for(i=0;bookname[i]!='\0';i++)
                    {
                    if(bookname[i]>='a'&&bookname[i]<='z')
                       bookname[i]-=32;
                    }
                    cout<<"\n\t\tEnter Author's Name : ";
                    cin.getline(auname,50);
                    cout<<"\n\t\tEnter Book's ID : ";
                    cin.getline(sc,20);
                    cout<<"\n\t\tEnter Book's Price : ";
                    cin>>p;
                    cout<<"\n\t\tEnter Book's Quantity : ";
                    cin>>q;
}
void Lib::show(int i)
{
    cout<<"\n\t\tBook Name : "<<bookname<<endl;
    cout<<"\n\t\tBook's Author Name : "<<auname<<endl;
    cout<<"\n\t\tBook's ID : "<<sc<<endl;
    if(i==2)
    {
        cout<<"\n\t\tBook's Price : "<<p<<endl;
        cout<<"\n\t\tBook's Quantity : "<<q<<endl;
    }
}
  void Lib::booklist(int i)
  {
                int r=0;
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                    cout<<"\n\t    ************ Book List ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(q==0 && i==1)
                    {

                    }
                    else
                        {
                            r++;
                            cout<<"\n\t\t********** "<<r<<". ********** \n";
                            show(i);
                        }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                if(i==1)
                    student();
                else
                    librarian();
    }
  void Lib::modify()
  {
    char ch;
    int i=0;
    system("cls");
    cout<<"\n\t\t>>Please Choose one option :-\n";
    cout<<"\n\t\t1.Add New Book\n\n\t\t2.Go back\n";
    cout<<"\n\n\t\tEnter your choice : ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    getdata();
                    ofstream outf("Booksdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tBook added Successfully.\n";
    }
    else if(i==2)
    {
    system("cls");
    librarian();
    }
    else
    {
    cout<<"\n\t\tWrong Input.\n";
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    modify();
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian();

  }
  void Lib::see(int x)
  {
      int i,cont=0;
      char ch[100];
      system("cls");
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(x==1)
            student();
            else
            librarian();
        }

      system("cls");
      cout<<"\n\t\tPlease Choose one option :-\n";
      cout<<"\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
      cout<<"\n\t\tEnter Your Choice : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tEnter Book's Name : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;q!=0&&bookname[i]!='\0'&&ch[i]!='\0'&&(ch[i]==bookname[i]||ch[i]==bookname[i]+32);i++);
            if(bookname[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tBook Found :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tEnter Book's ID : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;q!=0&&sc[i]!='\0'&&ch[i]!='\0'&&ch[i]==sc[i];i++);
              if(sc[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tBook Found :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tPlease enter correct option :(";
             getch();
             system("cls");
             see(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tThis Book is not available :( \n";

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(x==1)
    student();
    else
    librarian();


  }
void Lib::issue()
{
    char st[50],st1[20];
    int i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t\t->Please Choose one option :-\n";
    cout<<"\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search student who isuued books\n\n\t\t4.Return Book\n\n\t\t5.Go back to menu\n\n\t\tEnter Your Choice : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book Name : ";
    cin.getline(bookname,100);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(sc,20);
    //strcpy(st,sc);
    der(sc,1);
    cout<<"\n\t\tEnter Student Name : ";
    cin.getline(auname,100);
    cout<<"\n\t\tEnter Student's ID : ";
    cin.getline(sc1,20);
    cout<<"\n\t\t--------Enter date--------\n";
    cout<<"\t\tDay:";
    cin>>q;
    cout<<"\t\tMonth:";
    cin>>B;
    cout<<"\t\tYear:";
    cin>>p;
    ofstream outf("student.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\n\t\tIssue Successfully.\n";
    }
    else if(i==2)
    {
    ifstream intf("student.txt",ios::binary);
    system("cls");
    cout<<"\n\t\t->The Details are :-\n";
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    {
    i++;
    cout<<"\n\t\t********** "<<i<<". ********** \n";
    cout<<"\n\t\tStudent Name : "<<auname<<"\n\t\t"<<"Student's ID : "<<sc1<<"\n\t\t"<<"Book Name : "<<bookname<<"\n\t\t"<<"Book's ID : "<<sc<<"\n\t\t"<<"Date : "<<q<<"/"<<B<<"/"<<p<<"\n";
    intf.read((char*)this,sizeof(*this));
    }
    intf.close();
    }
    else if(i==3)
    {
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Please Enter Details :-\n";
        cout<<"\n\n\t\tEnter Student Name : ";
        cin.getline(st,50);
        cout<<"\n\n\t\tEnter Student's ID : ";
        cin.getline(st1,20);
        system("cls");
        ifstream intf("student.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              for(i=0;sc1[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc1[i];i++);
              if(sc1[i]=='\0'&&st1[i]=='\0')
              {
                  cont++;
                  if(cont==1)
                  {
                      cout<<"\n\t\t->The Details are :-\n";
                      cout<<"\n\t\tStudent Name : "<<auname;
                      cout<<"\n\t\tStudent's ID : "<<sc1;
                  }
                  cout<<"\n\n\t\t******* "<<cont<<". Book details *******\n";
                  cout<<"\n\t\tBook Name : "<<bookname;
                  cout<<"\n\t\tBook's ID : "<<sc;
                  cout<<"\n\t\tDate : "<<q<<"/"<<B<<"/"<<p<<"\n";
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
        if(cont==0)
            cout<<"\n\t\tNo record found.";
    }
    else if(i==4)
    {
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    der(st1,2);
    cout<<"\n\n\t\tEnter Student's ID : ";
    cin.getline(st,20);
    cout<<"\n\t\t--------Enter Present date--------\n";
    cout<<"\t\tDay:";
    cin>>d;
    cout<<"\t\tMonth:";
    cin>>m;
    cout<<"\t\tYear";
    cin>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("student.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
            for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
            if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    retrn(q,B,p,d,m,y);
                    cout<<"\n\t\tReturned successfully.";
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    getch();
    remove("student.txt");
    rename("temp.txt","student.txt");
    }
    else if(i==5)
    {
    system("cls");
    librarian();
    }
    else
        cout<<"\n\t\tWrong Input.\n";

    cout<<"\n\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian();
}
void Lib::retrn(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i]; //fn1353
    years = y;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    cout<<"\t\tReturned after "<<n1 << " days";
    if(n1>7)
        cout<<"\n\t\tNo further issuance is allowed :(";
    else
        cout<<"\n\t\t:)";
}
void Lib::der(char st[],int x)
{
    int i,cont=0;
    fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(i=0;sc[i]!='\0'&&st[i]!='\0'&&st[i]==sc[i];i++);
        if(sc[i]=='\0'&&st[i]=='\0')
        {
            cont++;
            if(x==1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\n\t\tBook not found.\n";
        cout<<"\n\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}
void Lib::get()
{
   int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
        cout<<"\n\t\t>>Please Choose Any Option To login \n";
        cout<<"\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            student();
        }
        else if(i==2)
            librarian();
        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("CLS");
            get();
        }
}
void Lib::student()
{
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
                booklist(1);
            else if(i==2)
                see(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tPlease enter correct option :(";
                getch();
                system("cls");
                student();
            }
}

void Lib::librarian()
{
    int i;
        cout<<"\n\t************ WELCOME LIBRARIAN ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Modify/Add Book\n\n\t\t4.Issue Book\n\n\t\t5.Go to main menu\n\n\t\t6.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:see(2);
                     break;
            case 3:modify();
                     break;
            case 4:issue();
                     break;
            case 5:system("cls");
                     get();
                     break;
            case 6:exit(0);
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            librarian();
        }
}

int main()
{
    Lib obj;
    obj.get();
    getch();
    return 0;
}
