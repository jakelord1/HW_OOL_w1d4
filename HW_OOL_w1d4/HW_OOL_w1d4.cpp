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
    char* GetName() {
        return ContactName;
    }
    char GetNum(int i) {
        return HomeNum[i];
    }
    void Reseter() {
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
    void Show(int i) {
        cout << i+1 << " " << ContactName << "\t" << HomeNum << "\t" << WorkNum << "\t" << MobilNum << endl;
    }
};
void ShowList(Abonent p[]) {
    for (size_t i = 0; i < 15; i++)
    {
        p[i].Show(i);
    }
}
void SearchSecName(Abonent* p) {
    char comp[5], search[5];
    cin.getline(search, 5);
    for (size_t i = 0; i < 25; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            comp[j] = p[i].GetName()[j];
        }
        if (strcmp(comp, search) == 0) {
            cout << "Second Name: " << p[i].GetName() << " Name: ";
            for (size_t i = 0; i < 11; i++)
            {
                cout << p->GetNum(i);
            }
            cout << endl;
        }
    }
}
Abonent EditAb(Abonent p) {
    p.Enter();
    return p;
}
Abonent DeleteAb(Abonent p) {
    p.Reseter();
    return p;
}
int main()
{
    Abonent people[15];
    int choose, pos;
    while (1) {
        cout << "Phone book\nMenu:\n1 - Choose from list\t2 - Edit Abonent\t3 - Delete Abonent\t4 - Search by Contact Name\t0 - Exit" << endl << "Write action: ";
        cin >> choose;
        switch (choose) {
        case 1: {
            ShowList(people);
            cin >> pos;
            pos--;
            break;
        }
        case 2: {
            EditAb(people[pos]);
            break;
        }
        case 3: {
            DeleteAb(people[pos]);
            break;
        }
        case 4: {
            SearchSecName(people);
            break;
        }
        case 0: {
            exit(0);
            break;
        }
        default: {
            break;
        }
        }
    }
}
