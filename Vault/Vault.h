#pragma once
#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include "RSA.h"

constexpr const unsigned char SIGNATURE[] = { 0x05, 0x04, 0x04, 0x05, 0x056, 0x04C, 0x054, 0x00A };

class Vault
{
public:
	Vault();
	~Vault();;

	void addToVault(const std::string& entry, const std::string& value);
	void listVault();
	void removeFromVault(const std::string& entry);
	void getEntryFromVault(const std::string& entry, const std::string passwd);

private:
	std::string m_fileName;
	std::fstream m_vaultFile;
	std::map<std::string, std::string> m_vault;

	void createVault();
	bool readMagic();
	void readVaultToMem();
};