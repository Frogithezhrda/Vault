#include "Vault.h"

Vault::Vault()
{
	m_fileName = "C:/Vault.vlt";

	createVault();

	m_vaultFile.open(m_fileName, std::ios::in | std::ios::out | std::ios::binary);

	if (!m_vaultFile.is_open())
	{
		std::cout << "Couldn't open the vault!" << std::endl;
		return;
	}
	if (!readMagic())
	{
		m_vaultFile.clear();
		m_vaultFile.seekp(0, std::ios::beg);   
		m_vaultFile.write(reinterpret_cast<const char*>(SIGNATURE), sizeof(SIGNATURE));
		m_vaultFile.flush();
	}
	std::cout << "Opened the vault!" << std::endl;
	readVaultToMem();
}

Vault::~Vault()
{
	m_vaultFile.close();
}

void Vault::addToVault(const std::string& entry, const std::string& value)
{
	//still need to encrypt the staff for the vault
	std::string writeValue = entry + ":" + encrypt(value) + "\n";
	if (m_vault.find(entry) == m_vault.end())
	{
		m_vault[entry] = value;
		m_vaultFile.clear();
		m_vaultFile.seekp(0, std::ios::end);
		m_vaultFile.write(writeValue.c_str(), writeValue.size());
		m_vaultFile.flush();
	}
	else
	{
		std::cout << "Entry Already Exists" << std::endl;
	}
}

void Vault::listVault()
{
	for (auto key = m_vault.begin(); key != m_vault.end(); key++)
	{
		std::cout << key->first << std::endl;
	}
}

void Vault::removeFromVault(const std::string& entry)
{
	std::string line;
	//std::string writeValue = entry + ":" + value + "\n";
	if (m_vault.find(entry) != m_vault.end())
	{
		std::ofstream tempVault("C:/tempVault.vlt", std::ios::binary | std::ios::app);
		m_vault.erase(entry);
		m_vaultFile.clear();
		m_vaultFile.seekp(0, std::ios::beg);
		while (std::getline(m_vaultFile, line))
		{
			auto pos = line.find(':');
			if (line.substr(0, pos) != entry)
			{
				line += "\n";
				tempVault.write(line.c_str(), line.size());
			}
		}
		m_vaultFile.close();
		tempVault.close();
		if (std::remove(m_fileName.c_str()) || std::rename("C:/tempVault.vlt", m_fileName.c_str()))
		{
			std::remove("C:/tempVault.vlt");
			std::cout << "Failed To Remove Entry" << std::endl;
			return;
		}
		return;
	}
	std::cout << "No Entry To Delete" << std::endl;
}

void Vault::getEntryFromVault(const std::string& entry)
{
	std::cout << (m_vault[entry].empty() ? "No Entry Found!\n" : m_vault[entry]);
}

void Vault::createVault()
{
	std::ofstream createFile(m_fileName, std::ios::binary | std::ios::app);
	if (!createFile.is_open())
	{
		std::cerr << "Cannot create vault file!" << std::endl;
		return;
	}
	createFile.close();
}

bool Vault::readMagic()
{
	std::string line;
	std::getline(m_vaultFile, line);
	line += "\n";
	if (std::strcmp((const char*)line.c_str(), (const char*)SIGNATURE)) return false;
	return true;
}

void Vault::readVaultToMem()
{
	std::string line;
	while (std::getline(m_vaultFile, line))
	{
		auto pos = line.find(':');
		if (pos != std::string::npos)
		{
			std::string key = line.substr(0, pos);
			std::string value = line.substr(pos + 1);
			m_vault[key] = value;
		}
	}
}
