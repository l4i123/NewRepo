#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class AirplaneClass {
private:
    string manufacturer;
    string model;
    int seats;
    double minRunwayLength;
    double tankCapacity;
    double fuelPerKm;
    double avgSpeed;

public:
    AirplaneClass() = default;
    AirplaneClass(const string &manufacturer, const string &model, int seats, double minRunwayLength, double tankCapacity,
              double fuelPerKm, double avgSpeed) {
    this->manufacturer = manufacturer;
    this->model = model;
    this->seats = seats;
    this->minRunwayLength = minRunwayLength;
    this->tankCapacity = tankCapacity;
    this->fuelPerKm = fuelPerKm;
    this->avgSpeed = avgSpeed;
}

    string getManufacturer() const {
         return manufacturer;
         }
    void setManufacturer(const string &manufacturer){
         this->manufacturer = manufacturer;
         }

    string getModel() const {
         return model;
         }
    void setModel(const string &model) {
         this->model = model;
         }

    int getSeats() const {
         return seats;
         }
    void setSeats(int seats) {
         this->seats = seats;
         }

    double getMinRunwayLength() const {
         return minRunwayLength;
         }
    void setMinRunwayLength(double minRunwayLength) {
         this->minRunwayLength = minRunwayLength;
         }

    double getTankCapacity() const {
         return tankCapacity;
         }
    void setTankCapacity(double tankCapacity) {
         this->tankCapacity = tankCapacity;
         }

    double getFuelPerKm() const {
         return fuelPerKm;
         }
    void setFuelPerKm(double fuelPerKm) {
         this->fuelPerKm = fuelPerKm;
         }

    double getAvgSpeed() const {
         return avgSpeed;
         }
    void setAvgSpeed(double avgSpeed) {
         this->avgSpeed = avgSpeed;
         }



    double maxFlightRange() const {
        return tankCapacity / fuelPerKm;
    }

    double calculateOperationalCost() const {
        return seats * fuelPerKm;
    }
    friend ostream &operator<<(ostream &os, const AirplaneClass &airplaneClass) {
        os   << "Manufacturer: " << airplaneClass.manufacturer
             << ", Model: " << airplaneClass.model
             << " Seats: " << airplaneClass.seats
             << "minimal Runaway Lenght: "<<airplaneClass.minRunwayLength
             << "tank Capacity: "<<airplaneClass.tankCapacity
             <<"average speed: "<<airplaneClass.avgSpeed<<endl;
        return os;
    }

    static void saveToFile(const vector<AirplaneClass> &airplaneClasses, const string &filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const auto &airplaneClass : airplaneClasses) {
        file << airplaneClass.getManufacturer() << "," << airplaneClass.getModel() << ","
             << airplaneClass.getSeats() << "," << airplaneClass.getMinRunwayLength() << ","
             << airplaneClass.getTankCapacity() << "," << airplaneClass.getFuelPerKm() << ","
             << airplaneClass.getAvgSpeed() << endl;
    }
    file.close();
    cout << "Data saved successfully to file: " << filename << endl;
    }

    static bool loadFromFile(vector<AirplaneClass> &airplaneClasses, const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading: " << filename << endl;
        return false;
    }

    airplaneClasses.clear();
    string line;
    while (getline(file, line)) {
        line = line.substr(0, line.find_last_not_of(" \t") + 1);
        stringstream ss(line);
        string manufacturer, model;
        int seats;
        double minRunwayLength, tankCapacity, fuelPerKm, avgSpeed;

        getline(ss, manufacturer, ',');
        getline(ss, model, ',');
        ss >> seats; ss.ignore();
        ss >> minRunwayLength; ss.ignore();
        ss >> tankCapacity; ss.ignore();
        ss >> fuelPerKm; ss.ignore();
        ss >> avgSpeed;

        airplaneClasses.emplace_back(manufacturer, model, seats, minRunwayLength, tankCapacity, fuelPerKm, avgSpeed);
    }

    file.close();
    return true;
}
    void display() const {
        cout << "Manufacturer: " << manufacturer
             << ", Model: " << model
             << " Seats: " << seats
             << "minimal Runaway Lenght: "<<minRunwayLength
             << "tank Capacity: "<<tankCapacity
             <<"average speed: "<<avgSpeed<<endl;
             }
};
