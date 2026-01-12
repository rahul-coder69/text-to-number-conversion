#include <iostream>
#include <string>
#include <vector>
#include <bitset>  // For binary conversion
#include <iomanip> // For formatting (setw, hex, oct)
#include <limits>  // For numeric limits

using namespace std;

int main()
{
    string text;
    int choice;

    // Initial Input
    cout << "ENTER ANY TEXT: ";
    getline(cin, text);

    while (true)
    {
        // Menu Display
        cout << "\n MENU" << endl;
        cout << "1. CONVERT TO DECIMAL (ASCII)" << endl;
        cout << "2. CONVERT TO BINARY" << endl;
        cout << "3. CONVERT TO OCTAL" << endl;
        cout << "4. CONVERT TO HEXADECIMAL" << endl;
        cout << "5. CONVERT TO ALL" << endl;
        cout << "6. EDIT THE TEXT" << endl;
        cout << "7. EXIT" << endl;

        cout << "ENTER YOUR CHOICE (1-7): ";

        // Input validation to ensure an integer is entered
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();                                         // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            continue;
        }

        // Clear the newline character left in the buffer by cin >> choice
        // This is crucial before using getline again in option 6
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
        {
            cout << "\nCHARACTER : DECIMAL" << endl;
            for (char ch : text)
            {
                // Cast to unsigned char first to avoid negative values for extended ASCII
                cout << ch << " : " << static_cast<int>(static_cast<unsigned char>(ch)) << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "\nCHARACTER : BINARY" << endl;
            for (char ch : text)
            {
                // bitset<8> creates an 8-bit binary representation
                cout << ch << " : " << bitset<8>(ch) << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "\nCHARACTER : OCTAL" << endl;
            for (char ch : text)
            {
                // use std::oct manipulator, reset with std::dec
                cout << ch << " : " << oct << static_cast<int>(static_cast<unsigned char>(ch)) << dec << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "\nCHARACTER : HEXADECIMAL" << endl;
            for (char ch : text)
            {
                // use std::hex manipulator and std::uppercase
                cout << ch << " : " << hex << uppercase << static_cast<int>(static_cast<unsigned char>(ch)) << dec << endl;
            }
        }
        else if (choice == 5)
        {
            // Table Header with formatting
            cout << "\n"
                 << left << setw(10) << "CHARACTER"
                 << left << setw(10) << "DECIMAL"
                 << left << setw(12) << "BINARY"
                 << left << setw(10) << "OCTAL"
                 << left << setw(15) << "HEXADECIMAL" << endl;

            cout << string(57, '-') << endl;

            for (char ch : text)
            {
                unsigned char uch = static_cast<unsigned char>(ch);
                int val = static_cast<int>(uch);

                cout << left << setw(10) << ch
                     << left << setw(10) << val
                     << left << setw(12) << bitset<8>(ch)
                     << left << setw(10) << oct << val
                     << left << setw(15) << hex << uppercase << val << dec << endl;
            }
        }
        else if (choice == 6)
        {
            cout << "\nENTER NEW TEXT: ";
            getline(cin, text);
            cout << "TEXT UPDATED SUCCESSFULLY." << endl;
        }
        else if (choice == 7)
        {
            cout << "EXITING THE PROGRAM. BYE BYE!" << endl;
            break;
        }
        else
        {
            cout << "INVALID CHOICE. PLEASE ENTER BETWEEN (1-7)." << endl;
        }
    }

    return 0;
}