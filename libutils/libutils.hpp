/* 
license:
	All rights reserved to HassanIQ777
	You may:
		Use the code below, edit it or change it however you like, 
		but never republish it under a new name, 
		if so you may do it while crediting me.
		
	@ This is the include file of utilslib
	@ Which is a utils library that i made
	@ do #include "libutils/libutils.hpp" to include everything
	
Made on:	 2024 Nov 20
Last update: 2025 Jan 8
*/

#ifndef LIBUTILS_HPP
#define LIBUTILS_HPP

// use for handling command line arguments
#include "src/CLIParser.hpp"

// use namespace color:: for all the colors you'd ever need!
#include "src/color.hpp"

// has loadConfig() and saveConfig() functions which allow you to save&load configurations in the INI way, example config: name=player
#include "src/config.hpp"

// use for everything related to files/directories, also has hasSequence(), generateUUID() and m_hash() functions
#include "src/file.hpp"

// use namespace "funcs::" for helper functions such as: terminal width, platform, printing functions, str(), clearTerminal(), and getKeyPress() which supports escape sequences such as up arrow!
#include "src/funcs.hpp"

// print info and warnings and errors to console
#include "src/log.hpp"

// Stopwatch class provides the essential stopwatch functions 
#include "src/stopwatch.hpp"

// allows you to make tokens easily and match them together, useful for anything that has options, and usable for hashing and maybe text-based AI
#include "src/tokenizer.hpp"

#endif // libutils.hpp