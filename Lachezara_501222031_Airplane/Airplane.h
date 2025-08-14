#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
class Airplane {
private:
    string id;
    string className;

public:
    Airplane() = default;
    Airplane(const string &id, const string &className) {
        this->id=id;
        this->className=className;
    }

    string getId() const {
        return id;
         }
    void setId(const string &id) {
         this->id = id;
         }

    string getClassName() const {
        return className;
         }
    void setClassName(const string &className) {
        this->className = className;
         }

    friend ostream &operator<<(ostream &os, const Airplane &airplane) {
        os << "Airplane ID: " << airplane.id << ", Class: " << airplane.className;
        return os;
    }

    static void saveToFile(const vector<Airplane> &airplanes, const string &filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const auto &airplane : airplanes) {
        file << airplane.getId() << "," << airplane.getClassName() << endl;
        }


    file.close();
    cout << "Data saved successfully to file: " << filename << endl;
    }

    static bool loadFromFile(vector<Airplane> &airplanes, const string &filename) {
     ifstream file(filename);
        if (!file) {
            cerr << "Error opening file for reading: " << filename << endl;
            return false;
        }

        airplanes.clear();
        string line;
        while (getline(file, line)) {

            line = line.substr(0, line.find_last_not_of(" \t") + 1);
            stringstream ss(line);
            string id;
            string className;


            getline(ss, id, ',');
            id = id.substr(0, id.find_last_not_of(" \t") + 1);


            ss >> className;

            airplanes.emplace_back(id, className);
        }
        file.close();
        return true;
    }
        void display() const {
            cout << "ID: " << id
             << " class Name " << className<< endl;
    }
};
