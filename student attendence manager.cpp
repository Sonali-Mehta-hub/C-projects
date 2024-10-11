#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct student
{
    string name;
    int rollN;
    bool present;
};

void save(const vector<student> &st, const string &stFile)
{
    ofstream out("E:/File/stFile.txt");
    if (!out)
    {
        cerr << "File not found:" << stFile << endl;
    }
    for (int i = 0; i < st.size(); i++)
    {
        out << "Name:" << st[i].name << endl;
        out << "Roll no:" << st[i].rollN << endl;
        out << "status:" << st[i].present << endl
            << endl;
    }
    out.close();
    cout << "saved to file" << stFile << endl;
}

int main()
{
    int value;
    student Student;
    vector<student> st;
    while (true)
    {
        cout << "1. to add student" << endl;
        cout << "2.to attendace" << endl;
        cout << "3.to show detail" << endl;
        cout << "4.to save in file" << endl;
        cout << "5. to exit" << endl;
        cout << "enter choice:";
        cin >> value;
        if (value == 1)
        {
            system("cls");
            char choice;
            do
            {
                cout << "Name:";
                cin >> Student.name;
                cout << "Roll No:";
                cin >> Student.rollN;
                st.push_back(Student);
                cout << "student saved:" << endl;
                cout << "Enter x for exit or c for continue:";
                cin >> choice;
            } while (choice != 'x' && choice == 'c');
        } // if
        else if (value == 2)
        {
            system("cls");
            char choice;
            for (int i = 0; i < st.size(); i++)
            {
                cout << "name:" << st[i].name << endl;
                cout << "Roll no:" << st[i].rollN << endl;
                cout << "'p' for present or 'a' for absent:";
                cin >> choice;
                if (choice == 'p')
                {
                    st[i].present = true;
                }
                else if (choice == 'a')
                {
                    st[i].present = false;
                }
            }
        } // elseif
        else if (value == 3)
        {
            system("cls");
            for (int i = 0; i < st.size(); i++)
            {
                if (st[i].present == true)
                {
                    cout << "Name:" << st[i].name << endl;
                    cout << "roll no:" << st[i].rollN << endl;
                    cout << "status:present" << endl
                         << endl;
                }
                else if (st[i].present == false)
                {
                    cout << "Name:" << st[i].name << endl;
                    cout << "Roll no:" << st[i].rollN << endl;
                    cout << "status: absent" << endl
                         << endl;
                }
            }
        }

        else if (value == 4)
        {
            save(st, "E:/File/stFile.txt");
        }
        else if (value == 0)
        {
            exit(0);
        }
        else
        {
            system("cls");
            cout << "invalid input" << endl;
        }
    }
    return 0;
} // main
