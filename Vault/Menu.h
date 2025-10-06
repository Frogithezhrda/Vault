#pragma once
#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
#include "Vault.h"

constexpr const int PARAM_COUNT = 2;
constexpr const int MIN_ARGS_COUNT = 3;

class Menu
{
public:
	Menu(Vault& vlt);
	void menu(const std::string& option, const std::vector<std::string>& params);


private:
	std::map<std::string, std::function<void(const std::vector<std::string>&)>> m_optionMap;
	Vault* m_vault;
	void add(const std::vector<std::string>& param);
	void removeEntry(const std::vector<std::string>& param);
	void get(const std::vector<std::string>& param);
	void list(const std::vector<std::string>& param);
};
