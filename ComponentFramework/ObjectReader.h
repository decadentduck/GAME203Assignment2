#ifndef OBJECTREADER_H
#define OBJECTREADER_H
#define NUM_OBJECTS 6
#include "Object.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


class ObjectReader
{
public:
	ObjectReader(std::string filename_);
	~ObjectReader();
	class Object* Objects[NUM_OBJECTS];
	ifstream fin;
	std::string next, name;
	int pX, pY, pZ, rX, rY, rZ, loc_end, loc_name, loc_pX, loc_pY, loc_pZ, loc_rX, loc_rY, loc_rZ;
};
#endif
