#include <iostream>
#include <unistd.h>

using namespace std;

class accomodationAgreement
{
public:
    int roomNumber;
    int roomCapacity;
    bool occupied;
    double pricePerRoom;
    accomodationAgreement() {}
    accomodationAgreement(int number, int capacity, int days, bool pet);
    void extendDays(int days);
    bool HasPet();
    void SetPet();
    int GetDaysOfStay();
    void SetDaysOfStay(int days);
    double GetAmountDue();
    void RefreshAmountDue();

private:
    bool pet;
    int daysOfStay;
    double amountDue;
};

accomodationAgreement::accomodationAgreement(int number, int capacity, int days, bool pet)
    : roomNumber(number), roomCapacity(capacity), daysOfStay(days), pet(pet)
{
    occupied = true;
    amountDue = (capacity * 50) * days;
    if (pet)
        amountDue += 25 * days;
}

bool accomodationAgreement::HasPet()
{
    return pet;
}

void accomodationAgreement::SetPet()
{
    pet = true;
}

int accomodationAgreement::GetDaysOfStay()
{
    return daysOfStay;
}

void accomodationAgreement::SetDaysOfStay(int days)
{
    daysOfStay = days;
}

double accomodationAgreement::GetAmountDue()
{
    return amountDue;
}

void accomodationAgreement::RefreshAmountDue()
{
    amountDue = (roomCapacity * 50) * daysOfStay;
    if (pet)
        amountDue += 25 * daysOfStay;
}

void accomodationAgreement::extendDays(int days)
{
    amountDue += (roomCapacity * 50) * days;
}

int main()
{
    accomodationAgreement Room[10];
    Room[0] = accomodationAgreement(1, 1, 7, false);
    Room[1] = accomodationAgreement(2, 1, 2, true);
    Room[2] = accomodationAgreement(3, 2, 3, false);
    Room[3] = accomodationAgreement(4, 2, 5, false);
    Room[4] = accomodationAgreement(5, 2, 7, false);
    Room[5] = accomodationAgreement(6, 2, 3, false);
    Room[6] = accomodationAgreement(7, 3, 6, false);
    Room[7] = accomodationAgreement(8, 3, 3, true);
    Room[8] = accomodationAgreement(9, 4, 2, false);
    Room[9] = accomodationAgreement(10, 4, 1, true);

    while (true)
    {
        system("clear");

        cout << "Motel Manager v0.0.-1\n"
             << endl;

        /*for (int i = 0; i < 10; i++)
        {
            if (!Room[i].occupied)
            {
                cout << "Room #" << i << " - VACANT";
            }
            else
            {
                cout << "Room #" << i + 1 << " - GUESTS: " << Room[i].roomCapacity << "; DAYS OF STAY: " << Room[i].GetDaysOfStay() << "; AMOUNT DUE: " << Room[i].GetAmountDue() << " ; HAS PET: " << Room[i].HasPet() << endl;
            }
        }*/
        int occupiedRooms = 0, numberOfGuests = 0, currentDailyIncome = 0, menuCommand, submenuCommand;
        for (int i = 0; i < 10; i++)
        {
            if (Room[i].occupied)
            {
                occupiedRooms++;
                numberOfGuests += Room[i].roomCapacity;
                currentDailyIncome += Room[i].roomCapacity * 50;
            }
        }
        cout << " * Stats:" << endl
             << "      - Occupied rooms: " << occupiedRooms << endl
             << "      - Vacant rooms: " << 10 - occupiedRooms << endl
             << "      - Number of guests: " << numberOfGuests << endl
             << "      - Current daily income: " << currentDailyIncome << endl;

        cout << endl
             << "------------------------------" << endl
             << endl
             << "1. Motel management" << endl
             << "2. Room management " << endl
             << endl
             << "9. Exit" << endl
             << endl
             << "------------------------------" << endl
             << endl
             << "Input command: ";

        cin >> menuCommand;

        if (menuCommand == 1)
        {
            system("clear");

            menuCommand = 0;

            cout << endl
                 << "------------------------------" << endl
                 << endl
                 << "1. List all rooms" << endl
                 << endl
                 << "0. Back" << endl
                 << endl
                 << "------------------------------" << endl
                 << endl
                 << "Input command: ";
            cin >> submenuCommand;

            if (submenuCommand == 1)
            {
                system("clear");
                cout << endl
                     << "        | Room number: | Number of guests: | Days of stay: |" << endl;
                for (int i = 0; i < 10; i++)
                {
                    if (!Room[i].occupied)
                    {
                        if (i != 9)
                            cout << "        |      0" << i + 1 << "      |         "
                                 << "-"
                                 << "         |       "
                                 << "-"
                                 << "       |" << endl;
                        else
                            cout << "        |      " << i + 1 << "      |         "
                                 << "-"
                                 << "         |       "
                                 << "-"
                                 << "       |" << endl;
                    }
                    else
                    {
                        // cout << "Room #" << i + 1 << " - GUESTS: " << Room[i].roomCapacity << "; DAYS OF STAY: " << Room[i].GetDaysOfStay() << "; AMOUNT DUE: " << Room[i].GetAmountDue() << " ; HAS PET: " << Room[i].HasPet() << endl;
                        if (i != 9)
                            cout << "        |      0" << i + 1 << "      |         " << Room[i].roomCapacity << "         |       " << Room[i].GetDaysOfStay() << "       |" << endl;
                        else
                            cout << "        |      " << i + 1 << "      |         " << Room[i].roomCapacity << "         |       " << Room[i].GetDaysOfStay() << "       |" << endl;
                    }
                }

                cout << endl
                     << "Press ENTER to close the list.";
                getchar();
                getchar();
            }
        }

        if (menuCommand == 2)
        {
            system("clear");

            menuCommand = 0;

            cout << endl
                 << "------------------------------" << endl
                 << endl
                 << "1. View room info" << endl
                 << "2. Assign room" << endl
                 << "3. Vacate room" << endl
                 << endl
                 << "0. Back" << endl
                 << endl
                 << "------------------------------" << endl
                 << endl
                 << "Input command: ";
            cin >> submenuCommand;

            if (submenuCommand == 1)
            {
                int roomNumber;
                system("clear");
                submenuCommand = 0;
                cout << "Enter room number: ";
                cin >> roomNumber;
                roomNumber--;
                system("clear");
                if (roomNumber <= -1 || roomNumber >= 10)
                {
                    cout << "Room doesn't exist.\n"
                         << endl;
                    sleep(2);
                }
                else
                {
                    cout << endl
                         << "------------------------------" << endl
                         << endl
                         << "Room #" << Room[roomNumber].roomNumber << endl
                         << "   Capacity: " << Room[roomNumber].roomCapacity << endl
                         << "   Occupied: ";
                    if (Room[roomNumber].occupied)
                    {
                        cout << "Yes" << endl
                             << "   Has pet: ";
                        if (Room[roomNumber].HasPet())
                            cout << "Yes" << endl
                                 << "   Days of stay: " << Room[roomNumber].GetDaysOfStay() << endl
                                 << "   Payment amount: " << Room[roomNumber].GetAmountDue() << endl;
                        else
                            cout << "No" << endl
                                 << "   Days of stay: " << Room[roomNumber].GetDaysOfStay() << endl
                                 << "   Payment amount: " << Room[roomNumber].GetAmountDue() << endl;
                    }
                    else
                        cout << "No" << endl;

                    cout << endl
                         << "------------------------------" << endl
                         << endl
                         << "Press ENTER to leave details.";
                    getchar();
                    getchar();
                }
            }

            if (submenuCommand == 2)
            {
                system("clear");
                submenuCommand = 0;
                int roomNumber;
                cout << "Enter room number: ";
                cin >> roomNumber;
                roomNumber--;
                if (roomNumber <= -1 || roomNumber >= 10)
                {
                    cout << "Room doesn't exist.\n"
                         << endl;
                    sleep(2);
                }
                else
                {
                    if (Room[roomNumber].occupied)
                    {
                        cout << "Room not vacant.\n"
                             << endl;
                        sleep(2);
                    }
                    else
                    {
                        int days, pet;
                        cout << "For how many days?: ";
                        cin >> days;
                        cout << "Will there be a pet? (1 for yes, anything else for no): ";
                        cin >> pet;
                        Room[roomNumber].SetDaysOfStay(days);
                        if (pet == 1)
                            Room[roomNumber].SetPet();
                        Room[roomNumber].occupied = true;
                        Room[roomNumber].RefreshAmountDue();
                    }
                }
            }

            if (submenuCommand == 3)
            {
                int roomNumber, confirmAction;

                system("clear");

                submenuCommand = 0;

                cout << "Enter room number: ";
                cin >> roomNumber;

                if (1 <= roomNumber && roomNumber <= 10)
                {
                    if (Room[roomNumber - 1].occupied)
                    {
                        cout << "Are you sure you want to vacate room #" << roomNumber << "?\n   1 - YES\n   2 - NO\nInput: ";
                        cin >> confirmAction;
                        if (confirmAction == 1)
                        {
                            Room[roomNumber - 1].occupied = false;
                        }
                    }
                    else
                    {
                        cout << "Room already vacant.\n"
                             << endl;
                        sleep(2);
                    }
                }
            }
        }

        if (menuCommand == 9)
        {
            return 0;
        }
    }

    return 0;
}
