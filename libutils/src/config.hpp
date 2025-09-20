/* 
license:
	All rights reserved to HassanIQ777
	You may:
		Use the code below, edit it or change it however you like, 
		but never republish it under a new name, 
		if so you may do it while crediting me.
		
	@ I made this because I always needed a quick way to save and load INI configs in my projects
Made on 2025 Jan 8
*/

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <map>
#include <fstream>

// Save settings to an INI file
void saveConfig(const std::string &filename, const std::map<std::string, std::string> &settings)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		for (const auto &[key, value] : settings)
		{
			file << key << "=" << value << "\n";
		}
		file.close();
		//std::cout << "Configuration saved to " << filename << "\n";
	}
	else
	{
		std::cerr << "Error: Could not open " << filename << " for writing.\n";
		std::terminate();
	}
}

// Load settings from an INI file
std::map<std::string, std::string> loadConfig(const std::string &filename)
{
	std::map<std::string, std::string> settings;
	std::ifstream file(filename);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			size_t delimiter = line.find('=');
			if (delimiter != std::string::npos)
			{
				std::string key = line.substr(0, delimiter);
				std::string value = line.substr(delimiter + 1);
				settings[key] = value;
			}
		}
		file.close();
		//std::cout << "Configuration loaded from " << filename << "\n";
	}
	else
	{
		std::cerr << "Error: Could not open " << filename << " for reading.\n";
		std::terminate();
	}
	return settings;
}

#endif // config.hpp

/* EXAMPLE:

int main() {
    std::map<std::string, std::string> config = {
        {"username", "Player"},
        {"theme", "light"},
        {"autosave", "true"}
    };

    save_config("config.ini", config);

    auto loaded_config = load_config("config.ini");
    for (const auto& [key, value] : loaded_config) {
        std::cout << key << ": " << value << "\n";
    }

    return 0;
}

// You can also use:
using ConfigMap = std::map<std::string, std::string>;
to make things easier

*/