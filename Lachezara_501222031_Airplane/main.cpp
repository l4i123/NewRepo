#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>

#include "Airplane.h"
#include "AirplaneClass.h"
#include "Flight.h"

bool isPositiveInteger(int &value) {
    if (cin >> value && value > 0) {
        return true;
    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}

bool isPositiveDouble(double &value) {
    if (cin >> value && value > 0) {
        return true;
    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}


bool isNonEmptyString(string &str) {
    cin.ignore();
    getline(cin, str);
    if (!str.empty()) {
        return true;
    } else {
        cin.clear();
        return false;
    }
}
int main() {


    std::vector<Airplane> airplanes;
    std::vector<AirplaneClass> airplaneClasses;
    std::vector<Flight> flights;

    const string airplanesFile = "airplanes.txt";
    const string airplaneClassesFile = "airplane_classes.txt";
    const string flightsFile = "flights.txt";

    Airplane::loadFromFile(airplanes, airplanesFile);
    AirplaneClass::loadFromFile(airplaneClasses, airplaneClassesFile);
    Flight::loadFromFile(flights, flightsFile);

    int choice;
    do {
        std::cout << "Menu:\n"
             << "1. Add Airplane\n"
             << "2. Add Airplane Class\n"
             << "3. Add Flight\n"
             << "4. Display Airplanes\n"
             << "5. Display Airplane Classes\n"
             << "6. Display Flights\n"
             << "7. Search Airplanes by Destination\n"
             << "8. Save files\n"
             << "9. Load Files\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                string id, className;
                std::cout << "Enter Airplane ID: ";
                while (!isNonEmptyString(id)) {
                        std::cout << "Invalid input! Please enter a valid Airplane ID: ";
                }
                std::cout << "Enter Airplane Class Name: ";
                while (!isNonEmptyString(className)) {
                        std::cout << "Invalid input! Please enter a valid Airplane Class Name: ";
                }

                airplanes.emplace_back(id, className);
                std::cout << "Airplane added successfully!\n";
                break;
            }
            case 2: {
                string manufacturer, model;
                int seats;
                double minRunwayLength,tankCapacity, fuelPerKm, avgSpeed;

                std::cout << "Enter Manufacturer: ";
                while (!isNonEmptyString(manufacturer)) {
                        std::cout << "Invalid input! Please enter a valid Manufacturer: ";
                }

                std::cout << "Enter Model: ";
                while (!isNonEmptyString(model)) {
                        std::cout << "Invalid input! Please enter a valid Model: ";
                }

                std::cout << "Enter Seats: ";
                while (!isPositiveInteger(seats)) {
                        std::cout << "Invalid input! Please enter a positive integer for Seats: ";
                }

                std::cout << "Enter Minimum Runway Length: ";
                while (!isPositiveDouble(minRunwayLength)) {
                        std::cout << "Invalid input! Please enter a positive integer for Runway Length: ";
                }

               std::cout << "Enter Tank Capacity: ";
               while (!isPositiveDouble(tankCapacity)) {
                    std::cout << "Invalid input! Please enter a positive number for Tank Capacity: ";
               }

               std::cout << "Enter Fuel Per Km: ";
               while (!isPositiveDouble(fuelPerKm)) {
                    std::cout << "Invalid input! Please enter a positive number for Fuel Per Km: ";
               }

               std::cout << "Enter Average Speed: ";
               while (!isPositiveDouble(avgSpeed)) {
                    std::cout << "Invalid input! Please enter a positive number for Average Speed: ";
               }
               airplaneClasses.emplace_back(manufacturer, model, seats, minRunwayLength, tankCapacity, fuelPerKm, avgSpeed);
               std::cout << "Airplane Class added successfully!\n";
               break;
               }

            case 3: {


               string destination;
               double runwayLength;
               double distance;

               std::cout << "Enter Destination: ";
               while (!isNonEmptyString(destination)) {
                    std::cout << "Invalid input! Please enter a valid Destination: ";
               }

               std::cout << "Enter Runway Length: ";
               while (!isPositiveDouble(runwayLength)) {
                    std::cout << "Invalid input! Please enter a positive integer for Runway Length: ";
               }

               std::cout << "Enter Distance: ";
               while (!isPositiveDouble(distance)) {
                    std::cout << "Invalid input! Please enter a positive number for Distance: ";
               }

               flights.emplace_back(destination, runwayLength, distance);
               std::cout << "Flight added successfully!\n";
               break;
               }

            case 4:
                for (const auto &airplane : airplanes) {
                    std::cout << airplane << "\n";
                }
                break;
            case 5:
                for (const auto &airplaneClass : airplaneClasses) {
                    std::cout << airplaneClass << "\n";
                }
                break;
             case 6:
                for (const auto &flight : flights) {
                    std::cout << flight << "\n";
                }
                break;

            case 7: {
                string destination;
                std::cout << "Enter destination to search for airplanes: ";
                std::cin >> destination;

                double distance;
                double runawayLenght;
                std::cout << "Enter distance to destination: ";
                std::cin >> distance;
                std::cout << "Enter runaway lenght of destination: ";
                std::cin >> runawayLenght;

                bool found = false;
                for (const auto &flight : flights) {
                    for (const auto &airplaneClass : airplaneClasses) {

                         if (flight.isCompatibleWithAirplane(airplaneClass, distance,runawayLenght)) {
                            std::cout << "Airplane can fly to " << destination << ": " << airplaneClass << "\n";
                            found = true;
                            }
                    }
                }
                if (!found) {
                        std::cout << "No airplanes can fly to " << destination << " with the given distance.\n";
                }
            }
            break;
            case 8:
                Airplane::saveToFile(airplanes,airplanesFile);
                Flight::saveToFile(flights, flightsFile);
                AirplaneClass::saveToFile(airplaneClasses, airplaneClassesFile);
                cout << "Data saved successfully. \n";
                break;

            case 9:
                if (!Airplane::loadFromFile(airplanes, airplanesFile)) {
                        cerr << "Failed to load air plane data from file!" << endl;
                 return 1;
                 }
                 if (!AirplaneClass::loadFromFile(airplaneClasses, airplaneClassesFile)) {
                        cerr << "Failed to load air plane classes data from file!" << endl;
                 return 1;
                 }
                 if (!Flight::loadFromFile(flights, flightsFile)) {
                        cerr << "Failed to load flights data from file!" << endl;
                 return 1;
                 }

                 cout << "Displaying airplane loaded from file:\n";
                for (const auto &airplanes : airplanes) {
                        airplanes.display();
                }
                 cout << "Displaying airplane classes loaded from file:\n";
                for (const auto &airplaneClasses : airplaneClasses) {
                        airplaneClasses.display();
                }
                cout << "Displaying flights loaded from file:\n";
                for (const auto &flight : flights) {
                        flight.display();
                }
                break;

            case 0:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
};


