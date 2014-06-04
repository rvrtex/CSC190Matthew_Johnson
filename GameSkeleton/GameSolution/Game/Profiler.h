#ifndef DEBUGPROFILER_H
#define DEBUGPROFILER_H

#include <cassert>
#include <string>
#include <fstream>
#include <iostream>

class Profiler
{
	bool status;
	const char* filename;
	static const unsigned int MAX_FRAME_SAMPLES = 5000;
	static const unsigned int MAX_PROFILE_CATEGORIES = 200;
	int frameIndex;
	unsigned int categoryIndex;
	unsigned int numUsedCategories;
	struct ProfileCatagory
	{
		const char* name;
		float samples[MAX_FRAME_SAMPLES];

	} categories[MAX_PROFILE_CATEGORIES];
	char getDelimiter(unsigned int index) const;
	Profiler(){};
	Profiler(const Profiler&);
	Profiler operator=(const Profiler&); 
	static Profiler theInstance;
	void checkforDuplicateCategory(const char*);
public:
	static Profiler& getInstance();
	void addEntry(const char* categroy, float time);
	void startUp(const char* fileName);
	void shutDown();
	void newFrame();
	void checkIsGood(bool* status) const;
};


//#define profiler Profiler::getInstance();

#endif // !DEBUGPROFILER_H

