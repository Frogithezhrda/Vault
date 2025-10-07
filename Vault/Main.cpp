#include "Menu.h"
#include "Vault.h"

int main(int argc, char* argv[])
{
	std::vector<std::string> params;
	if (argc < PARAM_COUNT)
	{
		std::cout << "Usage: Need At Least 2 Arguements\n";
		return 1;
	}
	Vault vlt;
	Menu menu(vlt);
	try
	{
		for (int i = PARAM_COUNT; i < argc; i++)
		{
			if (std::string(argv[i]).find(':') != std::string::npos) throw std::runtime_error("Invalid Character");
			params.push_back(argv[i]);
		}
		menu.menu(argv[1], params);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	return 0;
}