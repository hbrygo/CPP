#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int	i = 1;
	while (argv[i])
	{
		int	j = 0;
		while (argv[i][j])
		{
			char c = toupper(argv[i][j]);
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}