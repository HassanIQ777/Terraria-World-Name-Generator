#include "libutils/src/random.hpp"
#include "libutils/src/file.hpp"
#include "libutils/src/color.hpp"
#include "libutils/src/log.hpp"

std::string randomWorldName(const std::vector<std::string> &v_adjectives,
							const std::vector<std::string> &v_locations,
							const std::vector<std::string> &v_nouns)
{
	std::string world_name;
	const std::string adjective = color::TXT_BLUE + Random::m_getFrom(v_adjectives) + color::_RESET;
	const std::string location = color::TXT_GREEN + Random::m_getFrom(v_locations) + color::_RESET;
	const std::string noun = color::TXT_RED + Random::m_getFrom(v_nouns) + color::_RESET;

	uint8_t type = Random::m_int(0, 5);

	switch (type)
	{
	case 0:
		world_name = "The " + adjective + " " + location + " of " + noun;
		break;

	case 1:
		world_name = adjective + " " + location + " of " + noun;
		break;

	case 2:
		world_name = "The " + adjective + " " + location;
		break;

	case 3:
		world_name = adjective + " " + location;
		break;

	case 4:
		world_name = "The " + location + " of " + noun;
		break;

	case 5:
		world_name = location + " of " + noun;
		break;

	default:
		Log::m_error("An unexpected error occurred.", true);
	}

	return world_name;
} // most of the time the world will come in RGB order (or Adjective -> Location -> Noun)

int main(int argc, char *argv[])
{
	Random::m_seed(0);

	const std::vector<std::string> v_adjectives = File::m_readfile("adjective.txt");
	const std::vector<std::string> v_locations = File::m_readfile("location.txt");
	const std::vector<std::string> v_nouns = File::m_readfile("noun.txt");

	std::string random_world_name = randomWorldName(v_adjectives, v_locations, v_nouns);

	std::cout << random_world_name << "\n";
}
/*  Types

0:	The [adjective] [location] of [noun]
	
1:	[adjective] [location] of [noun]
	
2:	The [adjective] [location]
	
3:	[adjective] [location]
	
4:	The [location] of [noun]
	
5:	[location] of [noun]

*/