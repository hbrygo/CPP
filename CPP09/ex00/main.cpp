#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <string>

int file_to_map(std::ifstream& file, std::map<std::string, float>& myMap, char sep){
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)){
        line.erase(std::remove( line.begin(), line.end(), ' ' ), line.end());
        size_t pos = line.find(sep);
        if (pos != std::string::npos) {
            // Extraire la partie avant le séparateur comme clé (std::string)
            std::string key = line.substr(0, pos);

            // Extraire la partie après le séparateur comme valeur (float)
            std::string valueString = line.substr(pos + 1); // Pour sauter le séparateur
            float value;
            std::istringstream(valueString) >> value;

            // Stocker la paire clé-valeur dans la map
            myMap[key] = value;
        }
    }
    return 0;
}

int verif_map(std::map<std::string, float>& myMap){
    std::map<std::string, float>::const_iterator it = myMap.begin();
    for (; it != myMap.end(); ++it){
        std::string date = it->first;
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 10));
        if (year < 2009)
            return 1;
        if (month < 1 || month > 12)
            return 1;
        if (day < 1 || day > 31)
            return 1;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
            return 1;
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            if (month == 2 && day > 29)
                return 1;
        } else {
            if (month == 2 && day > 28)
                return 1;
        } 
    }
    return 0;
}

void find_input_date(std::ifstream& file, std::map<std::string, float> myMap){
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)){
        bool badInput = 0;
        line.erase(std::remove( line.begin(), line.end(), ' ' ), line.end());
        size_t pos = line.find('|');
        if (pos == std::string::npos)
            return ;
        std::string date = line.substr(0, pos);
        float   value = stof(line.substr(pos + 1));
        int year = stoi(date.substr(0, line.find('-')));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 10));
        if (date.find_first_not_of("0123456789-") != std::string::npos) {
            badInput = 1;
        }
        else if (year < 2009 || (year == 2009 && month == 1 && day == 1)) {
            badInput = 1;
        }
        else if (month < 1 || month > 12) {
            badInput = 1;
        }
        else if (day < 1 || day > 31) {
            badInput = 1;
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
            badInput = 1;
        }
        else if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            if (month == 2 && day > 29) {
                badInput = 1;
            }
        } else {
            if (month == 2 && day > 28) {
                badInput = 1;
            }
        } 
        std::map<std::string, float>::iterator it = myMap.find(date);
        if (badInput == 1){
            std::cout << "Bad input => " << date << std::endl;
        } else if (it != myMap.end()) {
            if (value * it->second < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else if (value * it->second > 1000)
                std::cout << "Error: too large a number." << std::endl;
            else
                std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        } else {
            std::map<std::string, float>::iterator lowerBound = myMap.lower_bound(date);
            if (lowerBound != myMap.begin()) {
                --lowerBound;
                if (value * lowerBound->second < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else if (value * lowerBound->second > 1000)
                    std::cout << "Error: too large a number." << std::endl;
                else
                    std::cout << date << " => " << value << " = " << value * lowerBound->second << std::endl;
            }
        }
    }
}

int main(int argc, char **argv){
    std::map<std::string, float> dbMap;
    if (argc != 2){
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    std::ifstream db("data.csv");
    if (!file.is_open() || !file.good() || !db.is_open() || !db.good()){
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    if (file_to_map(db, dbMap, ',') == 1){
        std::cerr << "Error: file incorect" << std::endl;
        file.close();
        db.close();
        return 1;
    }
    if (verif_map(dbMap) == 1){
        std::cerr << "Error: invalid date" << std::endl;
        file.close();
        db.close();
        return 1;
    }
    find_input_date(file, dbMap);
    file.close();
    db.close();
    return 0;
}