#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

string user()
{
    string user;
    cout << "Enter user name file-->";
    cin >> user;
    system("cls");
    return user;
}
string user1 = user();
string user_name = user1 + "@gmail.com";
void user_detail()
{
    string name;
    cout << "Enter name--->";
    cin >> name;
    string address;
    cout << "\nEnter address--->";
    cin >> address;
    string event_shed;
    cout << "\nName of Event Organising-->";
    cin >> event_shed;
    string room;
    cout << "\nEnter the code of room booked---> (eg C1)";
    cin >> room;
    string price = "";
    if (room == "C1")
    {
        price = "10,000";
    }
    else if (room == "C2")
    {
        price = "30,000";
    }
    else if (room == "C3")
    {
        price = "40,000";
    }
    else if (room == "C4")
    {
        price = "10,000";
    }
    else if (room == "C5")
    {
        price = "30,000";
    }
    else
    {
        cout << "code is incorrect for Receipt " << endl;
        user_detail();
    }
    string email;
    cout << "user mail id-->" << user_name;
start:
    string phone_num;
    cout << "\nEnter phone Number-->";
    cin >> phone_num;
    /*
    stringstream ss;
    ss << phone_num;
    string h;
    ss >> h;  */
    if (phone_num.length() == 10)
    {
        cout << ".";
    }
    else if (phone_num.length() > 10)
    {
        cout << "Incorrect phone number\n";
        goto start;
    }
    else if (phone_num.length() < 10)
    {
        cout << "Incorrect phone number\n";
        goto start;
    }

    ofstream file10(user1 + "_Recipt" + ".txt", ios::app);
    file10 << "\n*--------------------------------------------*\n";
    file10 << "*\t\tNAME-->" << name << "\t\t\t";
    file10 << "\n";
    file10 << "*\t\tADDRESS-->" << address << "\t\t\t\t\t";
    file10 << "\n";
    file10 << "*\t\tPHONE_NUMBER-->" << phone_num << "\t\t";
    file10 << "\n";
    file10 << "*\t\tEMAIL.ID-->" << user_name << "\t\t";
    file10 << "\n";
    file10 << "*\t\tEVENT_SHEDULING-->" << event_shed << "\t\t\t\t";
    file10 << "\n";
    file10 << "*\t\tDATE IS-->" << __DATE__ << "\t\t\t\t";
    file10 << "\n";
    file10 << "*\t\tTIME IS-->" << __TIME__ << "\t\t\t\t";
    file10 << "\n";
    file10 << "*\t\tROOM -->" << room << "\t\t\t\t";
    file10 << "\n";
    file10 << "*\t\tPRICE-->" << price << "\t\t\t\t\n";
    file10 << "-------------------------------------------";
    file10.close();
}
void captcha();
void login();
void registr();
void exit();
void main2();
void Booking();
void Non_AC_delete();
void AC_delete();
void user_delete();
void Recipt();
void Cancel();
void ACC_with_Projector();
void Non_ACC_with_Projector();
void Specification_1();
void Specification_2();
void Specification_3();
void Specification_4();
void Specification_5();
int main()
{
    int choice;
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t|------>WELCOME TO EVENT SCHEDULING PAGE <------|\n";
    cout << "\t\t\t\t*******************LOGIN*************************\n";
    cout << "1.Login";
    cout << "\n2.Register";
    cout << "\n3.Exit\n";
    cout << "Choose Option-->";
    cin >> choice;
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        exit();
        break;
    default:
        main();
    }
    return (0);
}
void registr()
{
    string reguser, regpass;
    system("cls");
    cout << "Enter the username-->";
    cin >> reguser;
    cout << "Enter the password-->";
    cin >> regpass;
    captcha();
    ofstream reg("database.txt", ios::app);
    reg << reguser << "@gmail.com"
        << " " << regpass << endl;
    system("cls");
    cout << "Registration is successfull\n";
    main();
}
void login()
{
    int exist = 0;
    string user, pass, u, p;
    system("cls");
    cout << "Enter the username : ";
    cin >> user;
    cout << "Enter the password : ";
    cin >> pass;
    captcha();
    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user + "@gmail.com" && p == pass)
        {
            exist = 1;
        }
    }
    input.close();
    if (exist == 1)
    {
        cout << "\t\t\tHello " << user1 << "\n\t\t\t---->>>Successfully logged In<<<----\n";
        ofstream str(user + "@gmail.com" + ".txt", ios::app);
        // str << "WELCOME USER-->" << user;
        str.close();
        cin.get();
        cin.get();
        main2();
    }
    else
    {
        cout << "\n\t\t\t--->>Sorry , login error<<---";
        cin.get();
        cin.get();
        main();
    }
}
void exit()
{
    cout << "\t\t\t\t***********************";
    cout << "\n\t\t\t\t|Thank You Visit Again|\n";
    cout << "\t\t\t\t***********************";
    cout << "\n\n\n\n";
}
void main2()
{
    int user;
    cout << "\t\t\t\t****************************";
    cout << "\n\t\t\t\t|WELCOME TO OUR BRANCH SITE|\n";
    cout << "\t\t\t\t****************************\n";
    cout << "Our Service Your Choice--->\n";
    cout << "1.Booking";
    cout << "\n2.Cancel";
    cout << "\n3.User_Recipt";
    cout << "\n4.Exit";
    cout << "\nChoose Option-->";
    cin >> user;
    system("cls");
    if (user == 1)
    {
        Booking();
    }
    else if (user == 2)
    {
        Cancel();
    }
    else if (user == 3)
    {
        Recipt();
    }
    else if (user == 4)
    {
        main();
    }
    else
    {
        cout << "\t\t\t --->>Enter choice doesn't exist . Try Again <---";
        main2();
    }
}
void Booking()
{
    int choice;
    cout << "\t\t\t\t**********Two types of Confrence Room Avaiable************"; // edit karna hai
    cout << "\n1.AC With Projector \n";
    cout << "2.Non AC & With Projector\n";
    cout << "3.Exit\n";
    cout << "Choose Option-->";
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:
        ACC_with_Projector();
        break;
    case 2:
        Non_ACC_with_Projector();
        break;
    case 3:
        main2();
        break;
    default:
        cout << "\t\t\t--->>Unexpected key entered<<---";
        Booking();
    }
}
void ACC_with_Projector()
{
    int user_choice;
    cout << "\n\t\t\t@-@-@-->The list of ACC room available<--@-@-@\n";
    cout << "\n\t\t\t@-@-->KINDLY CHECK THE STATUS FIRST BEFORE BOOKING<--@-@\n";
    cout << "\n1.Confrence Room 1";
    cout << "\n2.Confrence Room 2";
    cout << "\n3.Confrence Room 3";
    cout << "\n4.Specification of above Rooms";
    cout << "\n5.Status of Current Rooms available";
    cout << "\n6.Exit";
    cout << "\nChoose Option-->";
    cin >> user_choice;
    system("cls");
    if (user_choice == 1)
    {
        cout << "Welcome to Room 1 site";
        cout << "\n For Booking Enter following details\n";
        user_detail();
        ofstream file1("AC booking_details.txt", ios::app);
        file1 << user1;
        file1 << "\t\t\t_Rooms_booked_--->C1\n";
        file1.close();
        ofstream file2(user_name + ".txt", ios::app);
        file2 << "Rooms booked by user -";
        file2 << "C1\n";
        file2.close();
        cout << "Room is booked";
        ACC_with_Projector();
    }
    else if (user_choice == 2)
    {
        cout << "\nWelcome to Room 2 site";
        cout << "\n For Booking Enter following details";
        user_detail();
        ofstream file3("AC booking_details.txt", ios::app);
        file3 << user1;
        file3 << "\t\t\t_Rooms_booked_--->C2\n";
        file3.close();
        ofstream file4(user_name + ".txt", ios::app);
        file4 << "Rooms booked by user ";
        file4 << "C2\n";
        file4.close();
        cout << "Room is booked";
        ACC_with_Projector();
    }
    else if (user_choice == 3)
    {
        cout << "Welcome to Room 3 site";
        cout << "\n For Booking Enter following details";
        user_detail();
        ofstream file5("AC booking_details.txt", ios::app);
        file5 << user1;
        file5 << "\t\t\t_Rooms_booked_--->C3\n";
        file5.close();
        ofstream file6(user_name + ".txt", ios::app);
        file6 << "Rooms booked by user -";
        file6 << "C3\n";
        file6.close();
        cout << "Room is booked";
        ACC_with_Projector();
    }
    else if (user_choice == 4)
    {
        system("cls");
        Specification_1();
        Specification_2();
        Specification_3();
        ACC_with_Projector();
    }
    else if (user_choice == 5)
    {
        ifstream file7("AC booking_details.txt");
        char ch;
        while (file7.get(ch))
            cout << ch;
        file7.close();
        ACC_with_Projector();
    }
    else if (user_choice == 6)
    {
        Booking();
    }
    else
    {
        cout << "\t\t\t--->>Invalid choice<<--";
        Booking();
    }
}
void Non_ACC_with_Projector() // sabko edit karna hai ismay
{
    int user_choice;
    cout << "\n\t\t\t@-@-@-->The list of ACC room available<--@-@-@\n"; // sabko edit karna hai
    cout << "\n\t\t\t@-@-->KINDLY CHECK THE STATUS FIRST BEFORE BOOKING<--@-@\n";
    cout << "\n1.Confrence Room 4";
    cout << "\n2.Confrence Room 5";
    cout << "\n3.Status of Current Rooms available";
    cout << "\n4.Specification";
    cout << "\n5.Exit";
    cout << "\nChoose option-->";
    cin >> user_choice;
    system("cls");
    if (user_choice == 1)
    {
        cout << "\nWelcome to Room 1 site";
        cout << "\n For Booking Enter following details\n";
        user_detail();
        ofstream file1("Non_AC_booking_details.txt", ios::app);
        file1 << user1;
        file1 << "\t\t\t_Rooms_booked_--->C4";
        file1.close();
        ofstream file2(user_name + ".txt", ios::app);
        file2 << "Rooms booked by user -";
        file2 << "C4\n";
        file2.close();
        cout << "\nRoom is booked";
        Non_ACC_with_Projector();
    }
    else if (user_choice == 2)
    {
        cout << "Welcome to Room 2 site";
        cout << "\n For Booking Enter following details";
        user_detail();
        ofstream file3("Non_AC_booking_details.txt", ios::app);
        file3 << user1;
        file3 << "\t\t\t_Rooms_booked_--->C5";
        file3.close();
        ofstream file4(user_name + ".txt", ios::app);
        file4 << "Rooms booked by user -";
        file4 << "C5\n";
        file4.close();
        cout << "Room is booked";
        Non_ACC_with_Projector();
    }
    else if (user_choice == 3)
    {
        ifstream file7("Non_AC_booking_details.txt");
        char ch;
        while (file7.get(ch))
            cout << ch;
        file7.close();
        Non_ACC_with_Projector();
    }
    else if (user_choice == 4)
    {
        system("cls");
        Specification_4();
        Specification_5();
        Non_ACC_with_Projector();
    }
    else if (user_choice == 5)
    {
        Booking();
    }
    else
    {
        cout << "\n\t\t\t ---->>Invalid choice<<----";
        Booking();
    }
}
void Cancel()
{
    int choice;
    cout << "Which Type of Room u want to choose-->\n";
    cout << "\n1.AC Room (C1,C2,C3)";
    cout << "\n2.Non AC Room(C4,C5)";
    cout << "\n3.Exit";
    cout << "Choose Option-->";
    cin >> choice;
    if (choice == 1)
    {
        cout << user1 << " booked following rooms\n";
        ifstream file0(user_name + ".txt");
        string word1;
        while (!file0.eof())
        {
            getline(file0, word1);
            cout << word1 << endl;
        }
        AC_delete();
        user_delete();
        cout << "\nSuccessfully Cancelled";
        main2();
    }
    else if (choice == 2)
    {
        cout << user1 << " booked following rooms\n";
        ifstream file0(user_name + ".txt");
        string word1;
        while (!file0.eof())
        {
            getline(file0, word1);
            cout << word1 << endl;
        }
        Non_AC_delete();
        user_delete();
        cout << "\nSuccessfully Cancelled";
        main2();
    }
    else if (choice == 3)
    {
        cout << "\nSuccessfully Cancelled";
        Booking();
    }
    else
    {
        cout << "Invalid Option\n";
        Cancel();
    }
}
void Specification_1()
{
    cout << "\n********* Confrence Room 1 *********";
    cout << "\n#Features of the room : -";
    cout << "\n1.) Room size - 15 * 10 .";
    cout << "\n2.)Fully air conditioned(2 Ac).";
    cout << "\n3.) Flooring and Room finishing give luxurious look.";
    cout << "\n4.) Pre-installed Projector Having Hd Quality.";
    cout << "\n5.) Seating capacity = 50 people(approx)";
    cout << "\nPrice-- - 10, 000 / day-";
}
void Specification_2()
{
    cout << "\n\n********* Confrence Room 2 *********";
    cout << "\n#Features of the room : -";
    cout << "\n1.) Room size- 25 * 20.";
    cout << "\n2.)Fully Air conditioned (4 Ac).";
    cout << "\n3.) Glass is ventilated and marbled.";
    cout << "\n4.) Pre-installed Projector Having Big Screen.";
    cout << "\n5.)Seating capacity = 100 to 150. people(approx)";
    cout << "\nPrice--- 30,000/day";
}
void Specification_3()
{
    cout << "\n\n********* Confrence Room 3 *********";
    cout << "\n#Features of the room : -";
    cout << "\n1.) Room size - 25 * 30 .";
    cout << "\n2.)Fully air conditioned(6 Ac).";
    cout << "\n3.) Flooring and Room finishing give luxurious look.";
    cout << "\n4.) Preinstalled Projector Having Hd Quality.";
    cout << "\n5.) Seating capacity = 500 people(approx)";
    cout << "\nPrice-- - 40, 000 / day-";
}
void Specification_4()
{
    cout << "\n\n********* Confrence Room 4 *********";
    cout << "\n#Features of the room : -";
    cout << "\n1.) Room size - 10 * 20 .";
    cout << "\n2.)Fully Ventilated(Non Ac).";
    cout << "\n3.) Flooring and Room finishing give luxurious look.";
    cout << "\n4.) White board avaibility";
    cout << "\n5.) Seating capacity = 50 people(approx)";
    cout << "\nPrice-- - 10, 000 / day-";
}
void Specification_5()
{
    cout << "\n\n********* Confrence Room 5 *********";
    cout << "\n#Features of the room : -";
    cout << "\n1.) Room size - 15 * 10 .";
    cout << "\n2.)Fully Ventilated(Non Ac).";
    cout << "\n3.) Glass is ventilated and marbled.";
    cout << "\n4.) White board availibility.";
    cout << "\n5.) Seating capacity = 100 people(approx)";
    cout << "\nPrice-- - 20, 000 / day-";
}
void captcha()
{
    cout << "Please ADD the following Value" << endl;
    srand(time(0));
    int c = rand() % 99;
    int a = rand() % 99;
    int b = rand() % 99;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "\nEnter the above CAPTCHA: " << endl;
    cin >> c;
    if (c == a + b)
    {
        cout << " You are not a robot\n";
    }
    else
    {
        cout << "Invalid captcha\n";
        captcha();
    }
}
void AC_delete()
{
    string word;
    string pre;
    cout << "Enter the code of confrence room to be deleted from AC file-->";
    cin >> pre;
    ifstream file("AC booking_details.txt");
    ofstream file2("AC booking_details.txt", ios::app);
    while (!file.eof())
    {
        getline(file, word);
        if (strstr(word.c_str(), pre.c_str()))
        {
            word.replace(0, word.length(), pre + "-->update--->Cancelled");
            file2 << word << "\n";
        }
    }
    file.close();
    file2.close();
    // main2();
    if (pre == "C1")
    {
        ofstream file11(user1 + "_Recipt" + ".txt", ios::app);
        file11 << "\n !!!!ABOVE MENTIONED RECEIPT CANCEL!!!" << pre;
        file11.close();
    }
    else if (pre == "C2")
    {
        ofstream file11(user1 + "_Recipt" + ".txt", ios::app);
        file11 << "\n !!!!ABOVE MENTIONED RECEIPT CANCEL!!!" << pre;
        file11.close();
    }
    else if (pre == "C3")
    {
        ofstream file11(user1 + "_Recipt" + ".txt", ios::app);
        file11 << "\n !!!!ABOVE MENTIONED RECEIPT CANCEL!!!" << pre;
        file11.close();
    }
    else if (pre == "C4")
    {
        ofstream file11(user1 + "_Recipt" + ".txt", ios::app);
        file11 << "\n !!!!ABOVE MENTIONED RECEIPT CANCEL!!!" << pre;
        file11.close();
    }
    else if (pre == "C5")
    {
        ofstream file11(user1 + "_Recipt" + ".txt", ios::app);
        file11 << "\n !!!!ABOVE MENTIONED RECEIPT CANCEL!!!" << pre;
        file11.close();
    }
}

void Non_AC_delete()
{
    string word;
    string pre;
    cout << "Enter the code of confrence room to be deleted from Non AC-->";
    cin >> pre;
    ifstream file("Non_AC_booking_details.txt");
    ofstream file2("Non_AC_booking_details.txt", ios::app);
    while (!file.eof())
    {
        getline(file, word);
        if (strstr(word.c_str(), pre.c_str()))
        {
            word.replace(0, word.length(), pre + "-->update-->Cancelled");
            file2 << word << "\n";
        }
    }
    file.close();
    file2.close();
    // main2();

    if (pre == "C1")
    {
        ofstream file11(user1 + "_Recipt" + ".txt", ios::app);
        file11 << "\n !!!!ABOVE MENTIONED RECEIPT CANCEL!!!" << pre;
        file11.close();
    }
    else if (pre == "C2")
    {
        ofstream file11(user1 + "_Recipt" + ".txt", ios::app);
        file11 << "\n !!!!ABOVE MENTIONED RECEIPT CANCEL!!!" << pre;
        file11.close();
    }
    else if (pre == "C3")
    {
        ofstream file11(user1 + "_Recipt" + ".txt", ios::app);
        file11 << "\n !!!!ABOVE MENTIONED RECEIPT CANCEL!!!" << pre;
        file11.close();
    }
    else if (pre == "C4")
    {
        ofstream file11(user1 + "_Recipt" + ".txt", ios::app);
        file11 << "\n !!!!ABOVE MENTIONED RECEIPT CANCEL!!!" << pre;
        file11.close();
    }
    else if (pre == "C5")
    {
        ofstream file11(user1 + "_Recipt" + ".txt", ios::app);
        file11 << "\n !!!!ABOVE MENTIONED RECEIPT CANCEL!!!" << pre;
        file11.close();
    }
}

void user_delete()
{
    string word;
    string pre;
    cout << "Enter the code of confrence room to be deleted from user file-->";
    cin >> pre;
    ifstream file(user_name + ".txt");
    ofstream file2(user_name + ".txt", ios::app);
    while (!file.eof())
    {
        getline(file, word);
        if (strstr(word.c_str(), pre.c_str()))
        {
            word.replace(0, word.length(), pre + "-->update--->Cancelled");
            file2 << word << "\n";
        }
    }
    file.close();
    file2.close();
    // main2();
}
void Recipt()
{
    ifstream file11(user1 + "_Recipt" + ".txt");
    string word;
    if (file11.is_open())
    {
        while (!file11.eof())
        {
            getline(file11, word);
            cout << word << endl;
        }
        file11.close();
    }
    else
    {
        cout << "No Booking Avaiable";
        file11.close();
    }
    cin.get();
    cin.get();
    system("cls");
    main2();
}