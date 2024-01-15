#include <iostream>
#include <fstream>
#include <vector>
#include <string>

static std::vector<std::string> ReadNamesFromFile(const std::string& filename) {
    std::vector<std::string> names;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string name;
        while (std::getline(file, name)) {
            names.push_back(name);
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }

    return names;
}