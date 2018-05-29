#pragma once
#include "IRenderObjects.h"
#include <vector>
/*
struture qui stoque les data
*/
struct renderData {
	std::vector<float> vertice;
	std::vector<float> texCoord;
	std::vector<unsigned int> index;
	unsigned int verticeCount, indexCount, texCount;
};

