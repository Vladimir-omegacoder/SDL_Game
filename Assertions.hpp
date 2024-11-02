#pragma once
#ifndef GAME_ASSERTIONS
#define GAME_ASSERTIONS

#include <iostream>
#include <cstdlib>
#include <cassert>

#define GAME_ASSERT assert

#define GAME_ERROR(msg) \
	std::cerr << "Error: " msg << '\n'; \
	std::abort();

#endif


