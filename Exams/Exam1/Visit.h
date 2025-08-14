#ifndef VISIT_H
#define VISIT_H

#include <iostream>
#include <string>
#include <vector>
#include "Data.h"
using namespace std;

class Visit {
private:
    string egn;
    string name;
    string problems;
    Data date_visit;
    vector<string> medicine;

public:
    Visit(string e, string n, string p, Data d_v, vector<string> m)
        : egn(e), name(n), problems(p), date_visit(d_v), medicine(m) {
        if (medicine.size() > 5) {
            cout << "Warning: Medicine list should contain 5 or fewer items.\n";
            medicine.resize(5); // Limit medicine to 5 items
        }
    }

    string getProblems() const { return problems; }

    friend ostream& operator<<(ostream& os, const Visit& visit) {
        os << "Patient: " << visit.name
           << " | EGN: " << visit.egn
           << " | Complains: " << visit.problems << " | Date: ";
        visit.date_visit.print();
        os << " | Medicine: ";
        if (visit.medicine.empty()) {
            os << "No drugs";
        } else {
            for (size_t i = 0; i < visit.medicine.size(); ++i) {
                os << visit.medicine[i];
                if (i < visit.medicine.size() - 1) os << ", ";
            }
        }
        os << endl;
        return os;
    }
};
