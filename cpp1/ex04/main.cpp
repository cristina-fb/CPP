#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::string str, file_str;
	int pos;

	if (argc != 4)
		std::cout << "Number of arguments incorrect" << std::endl;
	else
	{
		std::string s1=argv[2], s2=argv[3], in=argv[1];
		std::ifstream input_file(argv[1]);
		std::ofstream output_file(in.append(".replace"));
		while (!input_file.eof())
		{
			std::getline(input_file, str);
			file_str.append(str);
			file_str.append("\n");
		}
		input_file.close();
		while((pos = file_str.find(s1)) != -1)
		{
			file_str.erase(pos, s1.length());
			file_str.insert(pos, s2);
		}
		output_file << file_str;
		output_file.close();
	}
	return(0);
}