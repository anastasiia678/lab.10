#include <iostream>
using namespace std;

void task1();
struct TDate {
    int Day;
    int Month;
    int Year;
};
bool IsLeapYear(int year);
int DaysInMonth(int month, int year);
bool IsValidDate(const TDate& date);
void NextDate(TDate& date);

void task2();
struct Parallelepiped {
    double a;
    double b;
    double c;
    double volume;
    double surface_area;
};
void calculate_properties(Parallelepiped &p);
bool validate_input(Parallelepiped &p);

void task3();
struct Point {
    float x;
    float y;
    bool isInSecondQuadrant;

    Point(float xCoord, float yCoord) : x(xCoord), y(yCoord), isInSecondQuadrant(false) {}
};
void checkIfInSecondQuadrant(Point& point);

int main() {
    int choice = 0;

    while (choice != 4) {
        cout << "Task number (1-3), or 4 to end the program: " << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                task1();
                break;
            }
            case 2: {
                task2();
                break;
            }
            case 3: {
                task3();
                break;
            }
            case 4: {
                cout << "Program is over!" << endl;
                break;
            }
            default: {
                cout << "Wrong choice, try again" << endl;
            }
        }
    }

    return 0;
}

void task1() {
    TDate dates[5] = {
        {28, 2, 2020}, // Leap year, February
        {31, 12, 2021}, // End of the year
        {30, 4, 2022}, // End of a month with 30 days
        {15, 8, 2023}, // Normal day
        {31, 6, 2024} // Invalid date
    };

    for (int i = 0; i < 5; ++i) {
        cout << "Date before NextDate: " << dates[i].Day << "/" << dates[i].Month << "/" << dates[i].Year << endl;
        NextDate(dates[i]);
        cout << "Date after NextDate: " << dates[i].Day << "/" << dates[i].Month << "/" << dates[i].Year << endl;
        cout << endl;
    }

    return;
}

bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int DaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return IsLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

bool IsValidDate(const TDate& date) {
    if (date.Year < 1 || date.Month < 1 || date.Month > 12 || date.Day < 1)
        return false;

    int days = DaysInMonth(date.Month, date.Year);
    return date.Day <= days;
}

void NextDate(TDate& date) {
    if (!IsValidDate(date)) {
        return; // Invalid date does not change
    }

    date.Day++;
    if (date.Day > DaysInMonth(date.Month, date.Year)) {
        date.Day = 1;
        date.Month++;
        if (date.Month > 12) {
            date.Month = 1;
            date.Year++;
        }
    }
}

void task2() {
    cout << "Task 2" << endl;
    Parallelepiped p;

    cout << "Enter the lengths of the edges a, b, c of the parallelepiped: ";
    cin >> p.a >> p.b >> p.c;

    if (validate_input(p)) {
        calculate_properties(p);
        cout << "Volume: " << p.volume << endl;
        cout << "Surface Area: " << p.surface_area << endl;
    } else {
        cout << "Failed to calculate properties due to invalid input." << endl;
    }

    return;
}

void calculate_properties(Parallelepiped &p) {
    p.volume = p.a * p.b * p.c;
    p.surface_area = 2 * (p.a * p.b + p.b * p.c + p.a * p.c);
}

bool validate_input(Parallelepiped &p) {
    if (p.a <= 0 || p.b <= 0 || p.c <= 0) {
        cerr << "Invalid input: Edge lengths must be positive." << endl;
        return false;
    }
    return true;
}

void task3() {
    cout << "Task 3" << endl;
    float x, y;
    cout << "Enter the coordinate x: ";
    cin >> x;
    cout << "Enter the coordinate y: ";
    cin >> y;

    // Initialize point
    Point point(x, y);

    // Check if the point is in the second quadrant
    checkIfInSecondQuadrant(point);

    // Output result
    cout << "Point (" << point.x << ", " << point.y << ") ";
    if (point.isInSecondQuadrant) {
        cout << "is in the second quadrant." << endl;
    } else {
        cout << "is not in the second quadrant." << endl;
    }

    return;
}

void checkIfInSecondQuadrant(Point& point) {
    if (point.x < 0 && point.y > 0) {
        point.isInSecondQuadrant = true;
    } else {
        point.isInSecondQuadrant = false;
    }
}
