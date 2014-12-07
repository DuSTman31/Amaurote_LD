#pragma once

#include "BasicTypes.h"
#include "DrawingPrimitives.h"

class BlockMap;
class DrawingSurface;

class Level
{
public:
	Level(void);
	Level(const blockCoord &a);
	virtual ~Level(void);
	void draw(DrawingSurface &ds, const coord &charPos);
	processPixel drawPixel(const dimension x, const dimension y, const dimension x, const dimension y);
private:
	double radPerPix(const dimension &i, const dimension &size);
	blockCoord levelSize;
	BlockMap *groundMap;
};

