#pragma once

typedef int blockDim;
typedef double dimension;

struct blockCoord
{
	blockDim x;
	blockDim y;
};

struct coord
{
	dimension x;
	dimension y;
};