#pragma once

class BlockMap
{
public:
	BlockMap(void);
	BlockMap(const unsigned int x_, const unsigned int y_);
	virtual ~BlockMap(void);
	void setCoord(const unsigned int x_, const unsigned int y_, const bool val);
	bool getCoord(const unsigned int x_, const unsigned int y_);
private:
	unsigned int getByteOffset(const unsigned int x_, const unsigned int y_);
	unsigned int getBitOffset(const unsigned int x_, const unsigned int y_);
	char *buf;
	unsigned int x;
	unsigned int y;
};

