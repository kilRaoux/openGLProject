#pragma once
#include <fstream>
#include "renderData.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class ObjLoader
{
public:
	ObjLoader();
	~ObjLoader();
	renderData parse(const char* filepath);
	int splitString(vector<string>& vecteur, string chaine, char separateur);
	
};

