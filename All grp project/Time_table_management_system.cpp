#include <bits/stdc++.h>
using namespace std;
ofstream ofile;
class teacher
{
public:
    string t[6][6];
    teacher();
    void tt(int, int[], string[6][6], string[6][6], string[6][6], string[6][6]);
    void display();
};
class sections
{
    string s[6][6];

public:
    sections();
    void s_display();
    void h_display();
    void c_display();
    void transfer(int, string[6][6], string[6][6], string[6][6], string[6][6], string[6][6]);
};
void teacher::tt(int sec, int n[], string t1[6][6], string t2[6][6], string t3[6][6], string t4[6][6])
{
    for (int k = 0; k < sec; k++)
    {
        int i = 0, j = 0;
        while (n[k] != 0)
        {
            int s = k + 1;
            string ss;
            ss = char('0' + s);
            if (t[i][j] == "" && i < 6 && t1[i][j] != ss && t2[i][j] != ss && t3[i][j] != ss && t4[i][j] != ss)
            {
                t[i][j] = char('0' + s);
                n[k]--;
                i++;
            }
            else
            {
                if (i > 5)
                {
                    i = 0;
                    j++;
                }
                else
                {
                    i++;
                }
            }
        }
    }
}
void teacher::display()
{
    ofile << "\t\t8-9\t9-10\t10-11\t11:30-12:30\t12:30-1:30\t1:30-2:30\n";
    for (int i = 0; i < 6; i++)
    {
        while (i < 6)
        {
            if (i == 0)
            {
                ofile << "MONDAY\t\t";
                break;
            }
            else
            {
                if (i == 1)
                {
                    ofile << "TUESDAY\t\t";

                    break;
                }
                else
                {
                    if (i == 2)
                    {
                        ofile << "WEDNESDAY\t\t";
                        break;
                    }
                    else
                    {
                        if (i == 3)
                        {
                            ofile << "THURSDAY\t\t";
                            break;
                        }
                        else
                        {
                            if (i == 4)
                            {
                                ofile << "FRIDAY\t\t";
                                break;
                            }
                            else
                            {
                                ofile << "SATURDAY\t\t";
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < 6; j++)
        {
            if (j == 4)
            {
                ofile << "\t";
            }
            else
            {
                if (j == 5)
                    ofile << "\t";
            }
            if (t[i][j] == "")
            {
                ofile << "FREE\t";
            }
            else
            {
                ofile << "SEC " << t[i][j] << "\t";
            }
        }
        ofile << endl;
    }
}

teacher::teacher()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            t[i][j] = "";
        }
    }
}
void error(int n[], int sec)
{
    int sum = 0;
    for (int i = 0; i < sec; i++)
    {
        sum = sum + n[i];
    }
    if (sum > 36)
    {
        cout << "        ERROR\n";
        cout << "Number of classes for teacher exceeded.\n";
        cout << "Please enter a valid value.";
        exit(0);
    }
}
int main()
{
    ofile.open("Time-Table.txt");
    if (!ofile)
    {
        cout << "ERROR";
        exit(-1);
    }
    cout << "                                     TIME TABLE\n";
    cout << "Time-table for Science,Humanities and Commerce classes from Monday to Saturday which have classes from 8 A.M to 2:30 P.M.\n";
    cout << "There are a total of 5 subjects with one teacher for each subject for each class.There are 6 periods everyday\n";
    cout << "thus,making a total of 36 periods every week.User have to input the number of sections and number\n";
    cout << "of classes for each subject of each class.\n";
    cout << "For which Class you want the time-table, Please enter the name of the class.\n";
    cout << "SCIENCE\n";
    cout << "COMMERCE\n";
    cout << "HUMANITIES\n";
    string clas;
    cin >> clas;
    for (int l = 0; l < clas.length(); l++)
    {
        clas[l] = toupper(clas[l]);
    }

    if (clas == "SCIENCE")
    {
        int sec;
        cout << "Enter the number of science class sections: ";
        cin >> sec;
        int math[sec], phy[sec], chem[sec], eng[sec], cs[sec];
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Maths classes for Section " << i + 1 << ": ";

            cin >> math[i];
            if (math[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(math, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Physics classes for Section " << i + 1 << ": ";
            cin >> phy[i];
            if (phy[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(phy, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Chemistry classes for Section " << i + 1 << ": ";
            cin >> chem[i];
            if (chem[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(chem, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of English classes for Section " << i + 1 << ": ";
            cin >> eng[i];
            if (eng[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(eng, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Computer Science classes for Section " << i + 1 << ": ";
            cin >> cs[i];
            if (cs[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(cs, sec);

        teacher maths, physics, chemistry, english, compsc, dummy;
        maths.tt(sec, math, english.t, compsc.t, physics.t, chemistry.t);
        physics.tt(sec, phy, maths.t, english.t, compsc.t, chemistry.t);
        chemistry.tt(sec, chem, maths.t, english.t, compsc.t, physics.t);
        english.tt(sec, eng, maths.t, compsc.t, physics.t, chemistry.t);
        compsc.tt(sec, cs, maths.t, english.t, physics.t, chemistry.t);
        ofile << "\n\n                         Time-Table for Teacher of Maths\n";
        maths.display();
        ofile << "\n\n                         Time-Table for Teacher of Physics\n";
        physics.display();
        ofile << "\n\n                         Time-Table for Teacher of English\n";
        english.display();
        ofile << "\n\n                         Time-Table for Teacher of Chemistry\n";
        chemistry.display();
        ofile << "\n\n                     Time-Table for Teacher of Computer Science\n";
        compsc.display();
        ofile << "\n\n";
        for (int i = 0; i < sec; i++)
        {
            sections p;
            p.transfer(i + 1, maths.t, english.t, compsc.t, physics.t, chemistry.t);
            ofile << "                         Time-Table for Science Class Section " << i + 1 << endl;
            p.s_display();
            ofile << "\n\n";
        }
    }
    else if (clas == "HUMANITIES")
    {
        int sec;
        cout << "Enter the number of Humanities class sections: ";
        cin >> sec;
        int math[sec], hind[sec], geo[sec], eng[sec], pol[sec];
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Maths classes for Section " << i + 1 << ": ";
            cin >> math[i];
            if (math[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(math, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Hindi classes for Section " << i + 1 << ": ";
            cin >> hind[i];
            if (hind[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(hind, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Geography classes for Section " << i + 1 << ": ";
            cin >> geo[i];
            if (geo[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(geo, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of English classes for Section " << i + 1 << ": ";
            cin >> eng[i];
            if (eng[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(eng, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Political Science classes for Section " << i + 1 << ": ";
            cin >> pol[i];
            if (pol[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(pol, sec);

        teacher maths, hindi, geography, english, polsc, dummy;
        maths.tt(sec, math, english.t, polsc.t, geography.t, hindi.t);
        hindi.tt(sec, hind, maths.t, english.t, polsc.t, geography.t);
        geography.tt(sec, geo, maths.t, english.t, polsc.t, hindi.t);
        english.tt(sec, eng, maths.t, polsc.t, geography.t, hindi.t);
        polsc.tt(sec, pol, maths.t, english.t, geography.t, hindi.t);
        ofile << "\n\n                         Time-Table for Teacher of Maths\n";
        maths.display();
        ofile << "\n\n                         Time-Table for Teacher of Geography\n";
        geography.display();
        ofile << "\n\n                         Time-Table for Teacher of English\n";
        english.display();
        ofile << "\n\n                         Time-Table for Teacher of Hindi\n";
        hindi.display();
        ofile << "\n\n                         Time-Table for Teacher of Political Science\n";
        polsc.display();
        ofile << "\n\n";
        for (int i = 0; i < sec; i++)
        {
            sections p;
            p.transfer(i + 1, maths.t, english.t, polsc.t, geography.t, hindi.t);
            ofile << "                          Time-Table for Humanities Class Section " << i + 1 << endl;
            p.h_display();
            ofile << "\n\n";
        }
    }
    else if (clas == "COMMERCE")
    {
        int sec;
        cout << "Enter the number of Commerce class sections: ";
        cin >> sec;
        int math[sec], acc[sec], buss[sec], eng[sec], eco[sec];
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Maths classes for Section " << i + 1 << ": ";
            cin >> math[i];
            if (math[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(math, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Accounts classes for Section " << i + 1 << ": ";
            cin >> acc[i];
            if (acc[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(acc, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Business Studies classes for Section " << i + 1 << ": ";
            cin >> buss[i];
            if (buss[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(buss, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of English classes for Section " << i + 1 << ": ";
            cin >> eng[i];
            if (eng[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(eng, sec);
        for (int i = 0; i < sec; i++)
        {
            cout << "Enter number of Economics classes for Section " << i + 1 << ": ";
            cin >> eco[i];
            if (eco[i] < 3)
            {
                cout << "Error\n";
                cout << "!!! Enter a number greater than 3 !!!\n";
                exit(-1);
                // break;
            }
        }
        error(eco, sec);

        teacher maths, accounts, bus_st, english, economics, dummy;
        maths.tt(sec, math, english.t, economics.t, bus_st.t, accounts.t);
        accounts.tt(sec, acc, maths.t, english.t, economics.t, bus_st.t);
        bus_st.tt(sec, buss, maths.t, english.t, accounts.t, economics.t);
        english.tt(sec, eng, maths.t, economics.t, accounts.t, bus_st.t);
        economics.tt(sec, eco, maths.t, english.t, bus_st.t, accounts.t);
        ofile << "\n\n                         Time-Table for Teacher of Maths\n";
        maths.display();
        ofile << "\n\n                         Time-Table for Teacher of Business Studiess\n";
        bus_st.display();
        ofile << "\n\n                         Time-Table for Teacher of English\n";
        english.display();
        ofile << "\n\n                         Time-Table for Teacher of Economics\n";
        economics.display();
        ofile << "\n\n                         Time-Table for Teacher of Accounts\n";
        accounts.display();
        ofile << "\n\n";
        for (int i = 0; i < sec; i++)
        {
            sections p;
            p.transfer(i + 1, maths.t, english.t, bus_st.t, accounts.t, economics.t);
            ofile << "                         Time-Table for Commerce Class Section " << i + 1 << endl;
            p.c_display();
            ofile << "\n\n";
        }
        ofile.close();
    }
    else
    {
        cout << "\n\nPlease enter a valid Class";
        cout << "\n     Exiting progam";
        exit(2);
    }
    cout << "\nPlease check the output file in the location of this program,\nAll the time-tables have been put up in the file.";
    ofile << "\n\nAbbreviations used:\n";
    ofile << "ENG\t : \tEnglish\n";
    ofile << "C.S.\t : \tComputer Science\n";
    ofile << "PHY\t : \tPhysics\n";
    ofile << "CHEM\t : \tChemistry\n";
    ofile << "P.S.\t : \tPolitical Studies\n";
    ofile << "GEO\t : \tGeography\n";
    ofile << "B.S.\t : \tBusiness Studies\n";
    ofile << "ACC\t : \tAccounts\n";
    ofile << "ECO\t : \tEconomics\n";
}
sections::sections()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            s[i][j] = "";
        }
    }
}
void sections::s_display()
{
    ofile << "\t\t8-9\t9-10\t10-11\t11:30-12:30\t12:30-1:30\t1:30-2:30\n";
    for (int i = 0; i < 6; i++)
    {
        while (i < 10)
        {
            if (i == 0)
            {
                ofile << "MONDAY\t\t";
                break;
            }
            else
            {
                if (i == 1)
                {
                    ofile << "TUESDAY\t\t";
                    break;
                }
                else
                {
                    if (i == 2)
                    {
                        ofile << "WEDNESDAY\t\t";
                        break;
                    }
                    else
                    {
                        if (i == 3)
                        {
                            ofile << "THURSDAY\t\t";
                            break;
                        }
                        else
                        {
                            if (i == 4)
                            {
                                ofile << "FRIDAY\t\t";
                                break;
                            }
                            else
                            {
                                ofile << "SATURDAY\t\t";
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < 6; j++)
        {
            if (j == 4)
            {
                ofile << "\t";
            }
            else
            {
                if (j == 5)
                    ofile << "\t";
            }
            if (s[i][j] == "")
            {
                ofile << "FREE\t";
            }
            if (s[i][j] == "1")
            {
                ofile << "MATHS\t";
            }
            if (s[i][j] == "2")
            {
                ofile << "ENG\t";
            }
            if (s[i][j] == "3")
            {
                ofile << "C.S.\t";
            }
            if (s[i][j] == "4")
            {
                ofile << "PHY\t";
            }
            if (s[i][j] == "5")
            {
                ofile << "CHEM\t";
            }
        }
        ofile << endl;
    }
}

void sections::h_display()
{
    ofile << "\t\t8-9\t9-10\t10-11\t11:30-12:30\t12:30-1:30\t1:30-2:30\n";
    for (int i = 0; i < 6; i++)
    {
        while (i < 10)
        {
            if (i == 0)
            {
                ofile << "MONDAY\t\t";
                break;
            }
            else
            {
                if (i == 1)
                {
                    ofile << "TUESDAY\t\t";
                    break;
                }
                else
                {
                    if (i == 2)
                    {
                        ofile << "WEDNESDAY\t\t";
                        break;
                    }
                    else
                    {
                        if (i == 3)
                        {
                            ofile << "THURSDAY\t\t";
                            break;
                        }
                        else
                        {
                            if (i == 4)
                            {
                                ofile << "FRIDAY\t\t";
                                break;
                            }
                            else
                            {
                                ofile << "SATURDAY\t\t";
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < 6; j++)
        {
            if (j == 4)
            {
                ofile << "\t";
            }
            else
            {
                if (j == 5)
                    ofile << "\t";
            }
            if (s[i][j] == "")
            {
                ofile << "FREE\t";
            }
            if (s[i][j] == "1")
            {
                ofile << "MATHS\t";
            }
            if (s[i][j] == "2")
            {
                ofile << "ENG\t";
            }
            if (s[i][j] == "3")
            {
                ofile << "P.S.\t";
            }
            if (s[i][j] == "4")
            {
                ofile << "GEO\t";
            }
            if (s[i][j] == "5")
            {
                ofile << "HINDI\t";
            }
        }
        ofile << endl;
    }
}
void sections::c_display()
{
    ofile << "\t\t8-9\t9-10\t10-11\t11:30-12:30\t12:30-1:30\t1:30-2:30\n";
    for (int i = 0; i < 6; i++)
    {
        while (i < 10)
        {
            if (i == 0)
            {
                ofile << "MONDAY\t\t";
                break;
            }
            else
            {
                if (i == 1)
                {
                    ofile << "TUESDAY\t\t";
                    break;
                }
                else
                {
                    if (i == 2)
                    {
                        ofile << "WEDNESDAY\t";
                        break;
                    }
                    else
                    {
                        if (i == 3)
                        {
                            ofile << "THURSDAY\t";
                            break;
                        }
                        else
                        {
                            if (i == 4)
                            {
                                ofile << "FRIDAY\t\t";
                                break;
                            }
                            else
                            {
                                ofile << "SATURDAY\t";
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < 6; j++)
        {
            if (j == 4)
            {
                ofile << "\t";
            }
            else
            {
                if (j == 5)
                    ofile << "\t";
            }
            if (s[i][j] == "")
            {
                ofile << "FREE\t";
            }
            if (s[i][j] == "1")
            {
                ofile << "MATHS\t";
            }
            if (s[i][j] == "2")
            {
                ofile << "ENG\t";
            }
            if (s[i][j] == "3")
            {
                ofile << "B.S.\t";
            }
            if (s[i][j] == "4")
            {
                ofile << "ACC\t";
            }
            if (s[i][j] == "5")
            {
                ofile << "ECO\t";
            }
        }
        ofile << endl;
    }
}
void sections::transfer(int n, string t1[6][6], string t2[6][6], string t3[6][6], string t4[6][6], string t5[6][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int s = n;
            string ss;
            ss = char('0' + s);
            if (t1[i][j] == ss)
            {
                this->s[i][j] = "1";
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int s = n;
            string ss;
            ss = char('0' + s);
            if (t2[i][j] == ss)
            {
                this->s[i][j] = "2";
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int s = n;
            string ss;
            ss = char('0' + s);
            if (t3[i][j] == ss)
            {
                this->s[i][j] = "3";
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int s = n;
            string ss;
            ss = char('0' + s);
            if (t4[i][j] == ss)
            {
                this->s[i][j] = "4";
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int s = n;
            string ss;
            ss = char('0' + s);
            if (t5[i][j] == ss)
            {
                this->s[i][j] = "5";
            }
        }
    }
}