#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

int ft_pars_file(std::ifstream& file, std::map<std::string, float>& myMap, char sep){
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)){
        line.erase(std::remove( line.begin(), line.end(), ' ' ), line.end());
        std::cout << "line: [" << line << "]" << std::endl;
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

int main(int argc, char **argv){
    std::map<std::string, float> fileMap;
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
    if (ft_pars_file(file, fileMap, '|') == 1){
        std::cout << "Error: file incorect" << std::endl;
        return 1;
    }
    // if (ft_pars_file(db, dbMap, ',') == 1){
    //     std::cout << "Error: file incorect" << std::endl;
    //     return 1;
    // }
    {
        std::map<std::string, float>::const_iterator it = fileMap.begin();
        for (; it != fileMap.end(); ++it) {
            std::cout << "Clé : " << it->first << ", Valeur : " << it->second << std::endl;
        }
    }
    // {
    //     std::map<std::string, float>::const_iterator it = dbMap.begin();
    //     for (; it != dbMap.end(); ++it) {
    //         std::cout << "Clé : " << it->first << ", Valeur : " << it->second << std::endl;
    //     }
    // }
    file.close();
    db.close();
    return 0;
}