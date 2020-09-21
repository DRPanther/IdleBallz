#ifndef VERSION_H
#define VERSION_H

	//Date Version Types
	static const char DATE[] = "20";
	static const char MONTH[] = "09";
	static const char YEAR[] = "2020";
	static const char UBUNTU_VERSION_STYLE[] =  "20.09";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 6;
	static const long BUILD  = 5;
	static const long REVISION  = 3;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 117;
	#define RC_FILEVERSION 0,6,5,3
	#define RC_FILEVERSION_STRING "0, 6, 5, 3\0"
	static const char FULLVERSION_STRING [] = "0.6.5.3";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 81;
	

#endif //VERSION_H