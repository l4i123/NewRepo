#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct Location {
    std::string name;
    std::string latitude;
    std::string longitude;

    void print() const {
        std::cout << name << "," << latitude << "," << longitude << std::endl;
    }
};

class LocationData {
private:
    std::vector<Location> locations;

public:
    void addLocation(const std::string& name,
        const std::string& lat,
        const std::string& lon) {
        locations.push_back({ name, lat, lon });
    }

    void searchByName(const std::string& name) const {
        for (const auto& loc : locations) {
            if (loc.name == name)
                loc.print();
        }
    }

    void searchByCoordinates(const std::string& lat,
        const std::string& lon) const {
        for (const auto& loc : locations) {
            if (loc.latitude == lat && loc.longitude == lon)
                loc.print();
        }
    }
};

int main() {
    LocationData data;
    std::string line;

    while (true) {
        std::getline(std::cin, line);
        if (line == ".") break;

        std::stringstream ss(line);
        std::string name, lat, lon;
        std::getline(ss, name, ',');
        std::getline(ss, lat, ',');
        std::getline(ss, lon);

        data.addLocation(name, lat, lon);
    }

    while (true) {
        std::getline(std::cin, line);
        if (line == ".") break;

        std::stringstream ss(line);
        std::string lat, lon;
        if (ss >> lat >> lon) {
            data.searchByCoordinates(lat, lon);
        }
        else {
            data.searchByName(line);
        }
    }

    return 0;
}
