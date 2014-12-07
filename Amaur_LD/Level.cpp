#include "StdAfx.h"
#include "Level.h"

#include "BlockMap.h"

#include <cmath>

Level::Level(void)
{
	levelSize.x = 1024;
	levelSize.y = 1024;
	groundMap = new BlockMap(levelSize.x, levelSize.y);
}

Level::Level(const blockCoord &a)
{
	levelSize = a;
	groundMap = new BlockMap(a.x, a.y);
}

Level::~Level(void)
{
	delete groundMap;
}

void 
Level::draw(DrawingSurface &ds, const coord &charPos)
{
	double xdeg = 0.0;
	double ydeg = 0.0;

	xdeg = radPerPix(charPos.x, (const dimension)levelSize.x);
	ydeg = radPerPix(charPos.y, (const dimension)levelSize.y);

	for(unsigned int i=0 ; i!=levelSize.y ; i++)
	{
		double yStart = ydeg*i;

		for(unsigned int j=0 ; j!=levelSize.x ; j++)
		{
			double xStart = xdeg*j;

		}
	}
}

double 
Level::radPerPix(const dimension &i, const dimension &size)
{
	dimension dx1 = i;
	dimension dx2 = size-i;
	dimension greater;
	dimension lesser;

	if(dx1 > dx2)
	{
		greater = dx1;
		lesser = dx2;
	}
	else
	{
		greater = dx2;
		lesser = dx1;
	}

	double scope = PI;

	scope /= 2.0;

	scope *= ((lesser/greater) + 1.0);

	scope /= size;
	return scope;
}

processPixel 
Level::drawPixel(const dimension x, const dimension y)
{
	dimension xSize = 0.0;
	dimension ySize = 0.0;



}