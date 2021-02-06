#pragma once
#include "SFML/Graphics.hpp"
#include "memory.h"
#include "CommonDefinitions.h"

class Graphics {

public:
	sf::RenderWindow* window;
	sf::RenderWindow* tileMemoryWindow;
	sf::RenderWindow* BGMapWindow;

	word cyclesThisLine = 0;
	bool ColorGameBoyMode = false;

private:
	sf::View* view;
	sf::Image* background;
	sf::Uint8* backgroundPixels;

	sf::View* tileMemoryView;
	sf::Image* tileMemoryBackground;

	sf::View* BGMapView;
	sf::Image* BGMapBackground;
	sf::Uint8* BGMapBackgroundPixels;


	sf::RenderWindow* ColorPaletteWindow;
	sf::View* ColorPaletteView;
	sf::Image* ColorPaletteBackground;

	const short cyclesPerLine = 456;

	byte* backgroundPixelsColorIndex;


	sf::Color BWPalette[4] = { sf::Color(0xFF,0xFF,0xFF),
							sf::Color(0xAA,0xAA,0xAA), 
							sf::Color(0x55,0x55,0x55), 
							sf::Color(0x00,0x00,0x00)};

	sf::Color CGBPalette[4];
	sf::Color CGBSpritePalette[4];

public:

	Memory* memory;

	Graphics();

	void setupTileWindow();
	void updateTileWindow();

	void setupBGMapWindow();
	void updateBGMapWindow();

	void setupColorPaletteWindow();
	void updateColorPaletteWindow();

	void updateWindow();

	void update(word cyclesThisUpdate, int speedMode);
	void drawScanLine();
	void drawBackground();
	byte bitData(byte val, byte bit);
	void drawSprites();

	void DrawBackgroundLine(int startX, int row, int screenY, int screenWidth, sf::Uint8* screen, bool mainScreen = false);
	void DrawWindowLine();

	void SetPixel(sf::Uint8* screen, int x, int y, int screenWidth, sf::Color color);
	byte GetPixelIndex(byte dataLow, byte dataHigh, byte pixelX);
	word GetTileDataAddress(byte LCDC, word address);

	sf::Color* GetBGPalette(byte CGBMapAttributes);
	sf::Color* GetColorSpritePalette(int paletteNumber);
};

