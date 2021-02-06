#pragma once
#include <string>
#include "cpu.h"
#include "Graphics.h"

class Emulator {

	Cpu cpu;
	Graphics graphics;

	int elapsedFrames = 0;
	int elapsedOpcodes = 0;
	int totalCycles = 0;
	byte LastLY = 0;

	std::string Filename = "mooneye-gb_hwtests/acceptance/timer/rapid_toggle.gb";

public:

	Emulator();
	~Emulator();
	void Update();
	void Loop();

	void saveState();
	void loadState();
};

