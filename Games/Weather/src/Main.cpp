//============================================================================
// Name        : Weather.cpp
// Author      : Kristiyan
// Version     :
//============================================================================

#include <iostream>
#include <list>
#include <thread>
#include <sstream>
#include <cstdlib>

#include <list>

#include "Particle.h"
#include "ConsoleScreen.h"
#include "Engine.h"

int main() {
	const int width = 30;
	const int height = 30;

	std::list<Particle*> particles;
	auto screen = ConsoleScreen(height, width, ' ');

	bool running = true;
	while (running) {
		generateRandomParticles(particles, width);

		renderParticles(screen, particles);

		std::this_thread::sleep_for(std::chrono::milliseconds(200));

		updateParticles(particles);
	}

	return 0;
}
