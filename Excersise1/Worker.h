#include <iostream>
#include <string>
#include <vector>

class Worker {
private:
    std::string id;
    std::string name;
    int working_years;
    std::string job;
    std::vector<double> salary; // Вектор за заплатите

public:
    Worker();  // Празен конструктор
    Worker(const std::string& position);

    void setId(const std::string& id_num);
    std::string getId() const;
    void setName(const std::string& full_name);
    std::string getName() const;
    void setWorking_years(int working_years);
    int getWorking_years() const;
    void setJob(const std::string& job);
    std::string getJob() const;

    void addSalary(double salary);
    double avgSalary() const;
    double findMinimumSalary() const;

    void showDetailsWorker() const;
};

// Конструктори
Worker::Worker() : id(""), working_years(0), job("") {
    std::cout << "Enter Position: ";
    std::getline(std::cin, job);
}

Worker::Worker(const std::string& pos) : id(""), working_years(0), job(pos) {}

// Методи за задаване и получаване
void Worker::setId(const std::string& id_num) {
    id = id_num;
}

std::string Worker::getId() const {
    return id;
}

void Worker::setName(const std::string& full_name) {
    name = full_name;
}

std::string Worker::getName() const {
    return name;
}

void Worker::setWorking_years(int years) {
    working_years = years;
}

int Worker::getWorking_years() const {
    return working_years;
}

void Worker::setJob(const std::string& job_title) {
    job = job_title;
}

std::string Worker::getJob() const {
    return job;
}

// Методи за работа със заплати
void Worker::addSalary(double salaries) {
    salary.push_back(salaries);
}

double Worker::avgSalary() const {
    if (salary.empty()) {
        return 0.0;
    }
    double sum = 0;
    for (double salaries : salary) {
        sum += salaries;
    }
    return sum / salary.size();
}

double Worker::findMinimumSalary() const {
    if (salary.empty()) {
        return 0.0;
    }
    double min = salary[0];
    for (double salaries : salary) {
        if (min > salaries) {
            min = salaries;
        }
    }
    return min;
}

// Показване на информация за работника
void Worker::showDetailsWorker() const {
    std::cout << "Social Number: " << id << "\n"
              << "Name: " << name << "\n"
              << "Experience Years: " << working_years << "\n"
              << "Position: " << job << "\n"
              << "Average Salary: " << avgSalary() << "\n"
              << "Minimum Salary: " << findMinimumSalary() << "\n";
}
