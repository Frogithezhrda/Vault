#include "Menu.h"



Menu::Menu(Vault& vlt)
{
    m_optionMap = {
        {"add", [this](const std::vector<std::string>& args) { this->add(args); }},
        {"remove", [this](const std::vector<std::string>& args) { this->removeEntry(args); }},
        {"get", [this](const std::vector<std::string>& args) { this->get(args); }},
        {"list", [this](const std::vector<std::string>& args) { this->list(args); }},
        {"help", [this](const std::vector<std::string>& args) { this->help(args); }}
    };
    m_vault = &vlt;
}

void Menu::menu(const std::string& option, const std::vector<std::string>& params)
{
    try
    {
        m_optionMap[option](params);
    }
    catch (const std::exception&)
    {
        std::cout << "Usage: command <args...>";
    }
}

void Menu::add(const std::vector<std::string>& param)
{
    if (param.size() != PARAM_COUNT)
    {
        std::cout << "Usage: add <identifier> <password>\n";
        return;
    }
    std::cout << "Adding Entry..." << std::endl;
    m_vault->addToVault(param.front(), param.back());
}

void Menu::removeEntry(const std::vector<std::string>& param)
{
    if (param.empty()) 
    {
        std::cout << "Usage: remove <name>\n";
        return;
    }
    std::cout << "Removing Entry..." << std::endl;
    m_vault->removeFromVault(param.front());
}

void Menu::get(const std::vector<std::string>& param)
{
    if (param.size() != PARAM_COUNT)
    {
        std::cout << "Usage: get <name> <pass>\n";
        return;
    }
    std::cout << "Getting Entry...\n";
    m_vault->getEntryFromVault(param.front(), param.back());
}

void Menu::help(const std::vector<std::string>& param)
{
    std::cout << "Vault Created By Omer Saban...!\nCommands: \n";
    std::cout << "add - to add a entry, Usage add <identifier> <password>\n";
    std::cout << "remove - to remove a entry, Usage remove <identifier>\n";
    std::cout << "list - to list all entries, Usage list\n";
    std::cout << "get - to get an entry, Usage: get <name>\n";
    std::cout << "help - to get this menu, Usage: help\n";
}

void Menu::list(const std::vector<std::string>& param)
{
    std::cout << "Listing all entries\n";
    m_vault->listVault();
}
