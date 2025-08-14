#include <iostream>
#include <vector>
#include <string>
#include "Data.h"
#include "Visit.h"
using namespace std;

int main() {
    vector<Visit> visits = {
        Visit("1234567890", "Ivan Ivanov", "headache", Data(25, 1, 2025), {"Aspirin"}),
        Visit("0987654321", "Maria Petrova", "cough", Data(26, 1, 2025), {"Paracetamol", "Syrup", "Vitamin C", "Ibuprofen", "Tamiflu", "Therasal"}),
        Visit("1122334455", "Georgi Georgiev", "headache and high blood pressure", Data(27, 1, 2025), {"Nurofen", "Captopril"})
    };

    string searchComplaint;
    cout << "What are your complaints: ";
    getline(cin, searchComplaint);

    cout << "\nPatients with a complaint (" << searchComplaint << "):\n";
    for (const auto& visit : visits) {
        if (visit.getProblems().find(searchComplaint) != string::npos) {
            cout << visit;
        }
    }

    return 0;
}
