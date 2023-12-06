#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "incorect input. try with: ./replace <file name> <string 1> <string 2>" << std::endl;
		return (1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream file(argv[1]);
	if (file.is_open())
	{
		std::string buf;
		std::string copy;
		while (std::getline(file, buf))
		{
			copy += buf;
			copy += "\n";
		}
		std::string fileName = argv[1];
		std::ofstream newFile(fileName + ".replace");
		std::string final;
		while (1)
		{
			size_t pos = copy.find(s1);
			if (pos == std::string::npos)
			{
				final += copy;
				break;
			}
			else
			{
				for (size_t i = 0; i < pos; i++)
					final += copy[i];
				final += s2;
				copy.erase(0, pos + s1.size());
			}
		}
		newFile << final;
		file.close();
		newFile.close();
	}
	else
		std::cout << "Error: cannot open the file" << std::endl;
	return (0);
}