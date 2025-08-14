#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Flight {
private:
    string destination;
    double runwayLength;
    double distance;

public:
    Flight() = default;
    Flight(const string &destination, double runwayLength, double distance) {
        this->destination = destination;
        this->runwayLength = runwayLength;
        this->distance = distance;
    }

    string getDestination() const {
        return destination;
    }
    void setDestination(const string &destination) {
        this->destination = destination;
    }

    double getRunwayLength() const {
        return runwayLength;
    }
    void setRunwayLength(double runwayLength) {
        this->runwayLength = runwayLength;
    }

    double getDistance() const {
        return distance;
    }
    void setDistance(double distance) {
        this->distance = distance;
    }

    friend ostream &operator<<(ostream &os, const Flight &flight) {
        os << "Destination: " << flight.destination << ", Runway Length: " << flight.runwayLength
           << ", Distance: " << flight.distance;
        return os;
    }

    bool isCompatibleWithAirplane(const AirplaneClass &airplane, double distance, double runwayLength) const {
        bool compatibleRunway = airplane.getMinRunwayLength() <= runwayLength;
        bool compatibleDistance = airplane.maxFlightRange() >= distance;
        return compatibleRunway && compatibleDistance;
    }

    static void saveToFile(const vector<Flight> &flights, const string &filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error opening file for writing: " << filename << endl;
            return;
        }

        for (const auto &flight : flights) {
            file << flight.getDestination() << ","
                 << flight.getRunwayLength() << ","
                 << flight.getDistance() << endl;
        }

        file.close();
        cout << "Data saved successfully to file: " << filename << endl;
    }

    static bool loadFromFile(vector<Flight> &flights, const string &filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file for reading: " << filename << endl;
            return false;
        }

        flights.clear();
        string line;
        while (getline(file, line)) {

            line = line.substr(0, line.find_last_not_of(" \t") + 1);
            stringstream ss(line);
            string destination;
            double runwayLength, distance;


            getline(ss, destination, ',');
            destination = destination.substr(0, destination.find_last_not_of(" \t") + 1);


            ss >> runwayLength;
            ss.ignore();
            ss >> distance;

            flights.emplace_back(destination, runwayLength, distance);
        }
        file.close();
        return true;
    }
    void display() const {
        cout << "Destination: " << destination
             << ", Runway Length: " << runwayLength
             << " meters, Distance: " << distance << " km" << endl;
    }
};
