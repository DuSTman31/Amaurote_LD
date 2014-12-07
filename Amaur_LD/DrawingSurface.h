#pragma once

#include "BasicTypes.h"
#include "DrawingPrimitives.h"

class DrawingSurface
{
public:
	DrawingSurface(void);
	DrawingSurface(const blockCoord &dimension);
	virtual ~DrawingSurface(void);
	void setPixel(const finPixel &pix, const unsigned int x, const unsigned int y);
private:
	finPixel *buf;
	blockCoord surfaceSize;
};

