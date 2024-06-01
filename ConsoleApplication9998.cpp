#include <iostream>
#include <string>

using namespace std;

struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    string transmissionType;

    void setValues(double len, double clr, double engVol, double engPow, double wheelDia, const string& col, const string& transType) {
        length = len;
        clearance = clr;
        engineVolume = engVol;
        enginePower = engPow;
        wheelDiameter = wheelDia;
        color = col;
        transmissionType = transType;
    }

    void displayValues() const {
        cout << "Length: " << length << " meters" << endl;
        cout << "Clearance: " << clearance << " meters" << endl;
        cout << "Engine Volume: " << engineVolume << " liters" << endl;
        cout << "Engine Power: " << enginePower << " horsepower" << endl;
        cout << "Wheel Diameter: " << wheelDiameter << " inches" << endl;
        cout << "Color: " << color << endl;
        cout << "Transmission Type: " << transmissionType << endl;
    }

    bool findCarByColor(const string& searchColor) const {
        return color == searchColor;
    }
};

int main() {
    Car myCar;
    myCar.setValues(4.5, 0.2, 2.0, 250, 18, "Red", "Automatic");

    cout << "Car Details:" << endl;
    myCar.displayValues();

    string searchColor;
    cout << "Enter color to search for: ";
    cin >> searchColor;

    if (myCar.findCarByColor(searchColor)) {
        cout << "Car found with color: " << searchColor << endl;
    }
    else {
        cout << "No car found with color: " << searchColor << endl;
    }

}