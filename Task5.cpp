#include <iostream>
#include <vector>
using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;

class MovieTicketBookingSystem {
private:
    vector<vector<char>> seats;
    double ticketPrice = 800.0;

public:
    MovieTicketBookingSystem() : seats(NUM_ROWS, vector<char>(NUM_COLS, 'O')) {}

    void displaySeats() {
        cout << "\n    ";
        for (int col = 0; col < NUM_COLS; ++col)
            cout << col + 1 << " ";
        cout << "\n";

        for (int row = 0; row < NUM_ROWS; ++row) {
            cout << row + 1 << "   ";
            for (int col = 0; col < NUM_COLS; ++col)
                cout << seats[row][col] << " ";
            cout << "\n";
        }
    }

    bool bookSeat(int row, int col) {
        if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
            cout << "Invalid seat selection. Please try again.\n";
            return false;
        }

        if (seats[row][col] == 'O') {
            seats[row][col] = 'X';
            cout << "Seat booked successfully!\n";
            return true;
        } else {
            cout << "Seat is already booked. Please choose another seat.\n";
            return false;
        }
    }

    double calculateTotalCost(int numSeats) {
        return numSeats * ticketPrice;
    }
};

int main() {
    MovieTicketBookingSystem bookingSystem;
    int numSeats;

    cout << "Welcome to the Movie Ticket Booking System!\n";

    while (true) {
        cout << "\nMenu:\n1. Display Seats\n2. Book Seat\n3. Exit\nEnter choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                bookingSystem.displaySeats();
                break;
            case 2:
                cout << "Enter row and column (e.g. 1 2) for seat booking: ";
                int row, col;
                cin >> row >> col;

                if (bookingSystem.bookSeat(row - 1, col - 1)) {
                    cout << "\nSeat Map:\n";
                    bookingSystem.displaySeats();

                    cout << "\nTotal cost: Rs." << bookingSystem.calculateTotalCost(1) << "\n";
                }
                break;
            case 3:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
