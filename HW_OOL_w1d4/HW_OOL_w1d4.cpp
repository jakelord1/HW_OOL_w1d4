#include <iostream>
using namespace std;

class Abonent {
    char* ContactName;
    char HomeNum[11];
    char WorkNum[11];
    char MobilNum[11];
    char Info[50];
public:
    Abonent() {
        ContactName = nullptr;
        for (size_t i = 0; i < 50; i++)
        {
            if (i < 11) {
                HomeNum[i] = ' ';
                WorkNum[i] = ' ';
                MobilNum[i] = ' ';
            }
            Info[i] = ' ';
        }
    };
    Abonent(const char* n, char h[], char w[], char m[], char i[]) {
        ContactName = new char[strlen(n) + 1];
        strcpy_s(ContactName, strlen(n) + 1, n);
        strcpy_s(HomeNum, strlen(h), h);
        strcpy_s(WorkNum, strlen(w), w);
        strcpy_s(MobilNum, strlen(m), m);
        strcpy_s(Info, strlen(i), i);
    };
    ~Abonent()
    {
        delete[] ContactName;
    }
    void Enter() {
        char buff[20];
        cout << "Enter name: ";
        cin >> buff;
        if (ContactName != nullptr)
        {
            delete[] ContactName;
        }
        ContactName = new char[strlen(buff) + 1];
        strcpy_s(ContactName, strlen(buff) + 1, buff);
        cout << endl << "Enter Home number: ";
        cin >> HomeNum;
        cout << endl << "Enter Work number: ";
        cin >> WorkNum;
        cout << endl << "Enter Mobile number: ";
        cin >> MobilNum;
        cout << endl << "Enter Information: ";
        cin >> Info;
    }
    void Delete() {
        ContactName = nullptr;
        for (size_t i = 0; i < 50; i++)
        {
            if (i < 11) {
                HomeNum[i] = ' ';
                WorkNum[i] = ' ';
                MobilNum[i] = ' ';
            }
            Info[i] = ' ';
        }
    }
};
int main()
{
    Abonent people[15];
}
