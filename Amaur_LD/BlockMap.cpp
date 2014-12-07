#include "StdAfx.h"
#include "BlockMap.h"


BlockMap::BlockMap(void)
{
	x = 1024;
	y = 1024;

	buf = new char[x*y/8];
}

BlockMap::BlockMap(const unsigned int x_, const unsigned int y_)
{
	x = x_;
	y = y_;
	buf = new char[x*y/8];
}


BlockMap::~BlockMap(void)
{
	delete[] buf;
}

void 
BlockMap::setCoord(const unsigned int x_, const unsigned int y_, const bool val)
{
	char mask = 255;
	char aVal = 0;
	char bc = 0;
	unsigned int bitOffset = 0;
	unsigned int byteOffset = 0;
	if(val)
	{
		bc = 1;
	}
	bitOffset = getBitOffset(x_, y_);
	byteOffset = getByteOffset(x_, y_);
	aVal = buf[byteOffset];
	bc <<= bitOffset;
	aVal &= (mask ^ (1 << bitOffset));
	aVal |= (bc << getBitOffset(x_, y_));
}

bool 
BlockMap::getCoord(const unsigned int x_, const unsigned int y_)
{
	char bc = buf[getByteOffset(x_, y_)];
	return ((bc >> getBitOffset(x_, y_)) & 1);
}

unsigned int 
BlockMap::getByteOffset(const unsigned int x_, const unsigned int y_)
{
	unsigned int off = 0;
	off += y_*x;
	off += x_;
	off /= 8;
	return off;
}

unsigned int 
BlockMap::getBitOffset(const unsigned int x_, const unsigned int y_)
{
	unsigned int off = 0;
	off += y_*x;
	off += x_;
	off %= 8;
	return off;	
}