#include "ObjectReader.h"



ObjectReader::ObjectReader(std::string filename_)
{
	fin.open(filename_);
	if (fin.fail) { cout << "Opening File failed. \n"; }
	
	int i = 0;

	while (getline(fin, next)) 
	{
		do 
		{
			loc_name = next.find("<name>");
			loc_pX = next.find("<posX>");
		    loc_pY = next.find("<posY>");
		    loc_pZ = next.find("<posZ>");
			loc_rX = next.find("<rotX>");
			loc_rY = next.find("<rotY>"); 
			loc_rZ = next.find("<rotZ>");
			loc_end = next.find("</object>");

			if ((loc_name >= 0) && (loc_name < next.length())) { name = next.substr(0, 5);}
			if ((loc_pX >= 0) && (loc_pX < next.length())) { /*pX = nextInt;*/ }
			if ((loc_pY >= 0) && (loc_pY < next.length())) { /*pY = nextInt;*/ }
			if ((loc_pZ >= 0) && (loc_pZ < next.length())) { /*pZ = nextInt;*/ }
			if ((loc_rX >= 0) && (loc_rX < next.length())) { /*rX = nextInt;*/ }
			if ((loc_rY >= 0) && (loc_rY < next.length())) { /*rY = nextInt;*/ }
			if ((loc_rZ >= 0) && (loc_rZ < next.length())) { /*rZ = nextInt;*/ }
		} 
		while (((loc_end < 0) || (loc_end >= next.length())) && (getline(fin, next)));

		Objects[i] = new Object(name, pX, pY, pZ, rX, rY, rZ);

		name.erase(0, name.length());
		pX = NULL;
		pY = NULL;
		pZ = NULL;
		rX = NULL;
		rY = NULL;
		rZ = NULL;
		i++;
	}
}


ObjectReader::~ObjectReader()
{
}
