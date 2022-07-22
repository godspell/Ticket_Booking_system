#include <windows.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
void fontsize(int a, int b)
{
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
    lpConsoleCurrentFontEx->dwFontSize.X = a;
    lpConsoleCurrentFontEx->dwFontSize.Y = b;
    SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}
void w()
{
    cout << "\n\n\n\n\n\n\n";
    SetConsoleTextAttribute(hConsole, 11);
    fontsize(50, 50);
    cout << "\t\t\t            WELCOME!!";
    SetConsoleTextAttribute(hConsole, 0);
    for (int i = 0; i < 750000000; i++)
        ;
}
struct cars
{
    int seats;
    bool seat[30];
};
cars train[10];
void Start()
{
    fstream Trains;
    Trains.open("Trains.data");
    for (int i = 0; i < 10; i++)
    {
        train[i].seats = 30;
        for (int j = 0; j < 30; j++)
        {
            if (!Trains.eof())
            {
                Trains >> train[i].seat[j];
                if (train[i].seat[j])
                    train[i].seats--;
            }
            else
                train[i].seat[j] = 0;
        }
    }
    Trains.close();
}

void End()
{
    fstream Trains;
    Trains.open("Trains.data", fstream::out);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            Trains << train[i].seat[j] << '\n';
        }
    }
    Trains.close();
    SetConsoleTextAttribute(hConsole, 0);
}

void Introduction()
{
    system("CLS");
    SetConsoleTextAttribute(hConsole, 9);
    cout << setw(26) << setfill('-') << " "
         << "Ticket Booking System " << setw(26) << setfill('-') << " "
         << "\n\n";
}

void sd(int &n)
{
    n = 0;
    string d;
    cin >> d;
    bool b = 0;
    for (int i = 0; i < d.size(); i++)
    {
        n *= 10;
        if (d[i] >= '0' && d[i] <= '9')
        {
            n += (d[i] - '0');
        }
        else
        {
            n = -1;
            system("CLS");
            Introduction();
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t                 !!error!!\n\a      ";
            SetConsoleTextAttribute(hConsole, 7);
            cout << "\t                 Try again \n\n\a";
            SetConsoleTextAttribute(hConsole, 0);
            b = 1;
            system("pause");
        }
        if (b)
        {
            break;
        }
    }
}

void menu()
{
    SetConsoleTextAttribute(hConsole, 11);
    cout << setw(72) << setfill('_') << " "
         << "\n\n";
    SetConsoleTextAttribute(hConsole, 7);
    cout << "1:\tReserve a ticket.\n";
    SetConsoleTextAttribute(hConsole, 11);
    cout << setw(72) << setfill('_') << " "
         << "\n\n";
    SetConsoleTextAttribute(hConsole, 7);
    cout << "2:\tCancel reservation.\n";
    SetConsoleTextAttribute(hConsole, 11);
    cout << setw(72) << setfill('_') << " "
         << "\n\n";
    SetConsoleTextAttribute(hConsole, 7);
    cout << "3:\tCheck whether a specific car has available seat or not.\n";
    SetConsoleTextAttribute(hConsole, 11);
    cout << setw(72) << setfill('_') << " "
         << "\n\n";
    SetConsoleTextAttribute(hConsole, 7);
    cout << "4:\tCheck whether a specific seat is available or not.\n";
    SetConsoleTextAttribute(hConsole, 11);
    cout << setw(72) << setfill('_') << " "
         << "\n\n";
    SetConsoleTextAttribute(hConsole, 7);
    cout << "5:\tGet the number of the available seats in a specific car.\n";
    SetConsoleTextAttribute(hConsole, 11);
    cout << setw(72) << setfill('_') << " "
         << "\n\n";
    SetConsoleTextAttribute(hConsole, 7);
    cout << "6:\tShow all the seats status of a specific car.\n";
    SetConsoleTextAttribute(hConsole, 11);
    cout << setw(72) << setfill('_') << " "
         << "\n\n";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "7:\tExit.\n\n";
    SetConsoleTextAttribute(hConsole, 11);
    cout << setw(72) << setfill('_') << " "
         << "\n\n";
}

void inputcar(int &c)
{
    bool b = 0;
    do
    {
        Introduction();
        if (b == 1)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "!!This train contains cars with numbers between << 1 >> and << 10 >> only.!!\n\n\a";
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout << "Enter the number of car : \t";
        sd(c);
        cout << '\n';
        b = 1;
    } while (c < 1 || c > 10);
}

void inputseat(int &s)
{
    bool b = 0;
    do
    {
        Introduction();
        if (b == 1)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "!!This car contains seats with numbers between << 1 >> and << 30 >> only.!!\n\n\a";
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout << "Enter the number of seat : \t";
        sd(s);
        cout << '\n';
        b = 1;
    } while (s < 1 || s > 30);
}

bool repetition(string ch)
{
    int choice;
    bool b = 0;
    do
    {
        if (b == 1)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\t!!Not define choice.!!\n\n";
            cout << "your choice shoulde be 1 or 2\n\n";
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout << "1:\t" << ch << ".\n";
        cout << "2:\tBack to menu.\n\n";
        cout << "Enter your choice : \t";
        sd(choice);
        cout << '\n';
        b = 1;
    } while (choice < 1 || choice > 2);
    if (choice == 2)
    {
        Introduction();
        return 0;
    }
    return 1;
}

void Reserve_a_ticket()
{
    bool f = 0;
    do
    {
        int c;
        inputcar(c);
        int s;
        inputseat(s);
        if (train[c - 1].seat[s - 1] == 1)
        {
            Introduction();
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\t!!This seat is already reserved.!!\n\n";
        }
        else
        {
            Introduction();
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\tThe reservation is completed.\n\n";
            train[c - 1].seat[s - 1] = 1;
            train[c - 1].seats--;
        }
        f = repetition("Reserve another ticket");
        End();
    } while (f == 1);
}
void Cancel_reservation()
{
    bool f = 0;
    do
    {
        int c;
        inputcar(c);
        int s;
        inputseat(s);
        if (train[c - 1].seat[s - 1] == 1)
        {
            train[c - 1].seat[s - 1] = 0;
            train[c - 1].seats++;
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\tThe reservation is canceled.\n\n";
        }
        else
        {
            Introduction();
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\t!!The seat is already available.!!\n\n";
        }
        f = repetition("Cancel another reservation");
        End();
    } while (f == 1);
}
void Check_whether_a_specific_car_has_available_seat_or_not()
{
    bool f = 0;
    do
    {
        int c;
        inputcar(c);
        if (train[c - 1].seats > 0)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t\t||  Available.  ||\n\n";
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\t\t||Not available.||\n\n";
        }
        f = repetition("Check whether another car has available seat or not");
    } while (f == 1);
}
void Check_whether_a_specific_seat_is_available_or_not()
{
    bool f = 0;
    do
    {
        int c;
        inputcar(c);
        int s;
        inputseat(s);
        if (train[c - 1].seat[s - 1] == 1)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\t\t||Not available.||\n\n";
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t\t|| Available. ||\n\n";
        }
        f = repetition("Check whether another seat is available or not");
    } while (f == 1);
}
void Get_the_number_of_the_available_seats_in_a_specific_car()
{
    bool f = 0;
    do
    {
        int c;
        inputcar(c);
        SetConsoleTextAttribute(hConsole, 14);
        cout << "The number of the available seats in car number ";
        SetConsoleTextAttribute(hConsole, 7);
        cout << c;
        SetConsoleTextAttribute(hConsole, 14);
        cout << " is : ";
        if (train[c - 1].seats)
        {
            SetConsoleTextAttribute(hConsole, 10);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
        }
        cout << train[c - 1].seats << "\n\n";
        f = repetition("Get the number of the available seats in another car");
    } while (f == 1);
}
void Show_all_the_seats_status_of_a_specific_car()
{
    bool f = 0;
    do
    {
        int c;
        inputcar(c);
        for (int i = 0; i < 30; i++)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout << "seat:\t";
            SetConsoleTextAttribute(hConsole, 7);
            cout << i + 1;
            if (train[c - 1].seat[i] == 1)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t||Not available.||\n";
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 10);
                cout << "\t\t||  Available.  ||\n";
            }
        }
        cout << '\n';
        f = repetition("Show all the seats status of another car");
    } while (f == 1);
}
int main()
{
    w();
    fontsize(16, 16);
    Start();
    Introduction();
    int choice;
    do
    {
        menu();
        SetConsoleTextAttribute(hConsole, 7);
        cout << "Enter your choice : \t";
        sd(choice);
        cout << '\n';
        switch (choice)
        {
        case 1:
            Reserve_a_ticket();
            break;
        case 2:
            Cancel_reservation();
            break;
        case 3:
            Check_whether_a_specific_car_has_available_seat_or_not();
            break;
        case 4:
            Check_whether_a_specific_seat_is_available_or_not();
            break;
        case 5:
            Get_the_number_of_the_available_seats_in_a_specific_car();
            break;
        case 6:
            Show_all_the_seats_status_of_a_specific_car();
            break;
        case 7:
            End();
            system("CLS");
            fontsize(40, 40);
            cout << "\n\n\n\n";
            SetConsoleTextAttribute(hConsole, 28);
            cout << "\t\t\tThank you for using our ticketing system\n\n";
            for (int i = 0; i < 750000000; i++)
                ;
            SetConsoleTextAttribute(hConsole, 0);
            system("CLS");
            fontsize(30, 30);
            SetConsoleTextAttribute(hConsole, 144);
            cout << "\t\tBy\n\t\t  Eng   : Ahmed Mohamed Fathy\n\t\t  Eng   : Najm Adin Osman Sayed";
            SetConsoleTextAttribute(hConsole, 0);
            return 0;
        default:
            Introduction();
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\tNot define choice.\n\n";
        }
    } while (true);
}