#include "StdAfx.h"
#include "DrawingSurface.h"


DrawingSurface::DrawingSurface(void)
{
	surfaceSize.x = 1024;
	surfaceSize.y = 1024;

	buf = new finPixel[surfaceSize.x * surfaceSize.y ];
}

DrawingSurface::DrawingSurface(const blockCoord &a)
{
	surfaceSize = a;
	buf = new finPixel[surfaceSize.x * surfaceSize.y ];
}

DrawingSurface::~DrawingSurface(void)
{
}

void 
DrawingSurface::setPixel(const finPixel &pix, const unsigned int x, const unsigned int y)
{
	buf[surfaceSize.x*y + x] = pix;
}