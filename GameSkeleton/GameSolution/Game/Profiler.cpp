#include "Profiler.h"

Profiler Profiler::theInstance;

Profiler& Profiler::getInstance()
{
	return theInstance;
};

void Profiler::startUp(const char* fileName)
{
	this->filename=fileName;
	status = true;
	frameIndex = -1;
	categoryIndex = 0;
	numUsedCategories = 0;

}

void Profiler::shutDown()
{
	std::ofstream outStream(filename);

	//Write Catergory headers
	for(unsigned int i = 0; i < numUsedCategories; i ++)
	{
		outStream << categories[i].name;
		outStream << getDelimiter(i);

	}

	//Account for last frame if they added entries
	int numActualFrames = frameIndex;
	if(categoryIndex == numUsedCategories)
		numActualFrames++;

	for(int frame = 0; frame < numActualFrames; frame++)
	{
		for(unsigned int cat = 0; cat < numUsedCategories; cat++)
		{
			outStream << categories[cat].samples[frame];
			outStream << getDelimiter(cat);
			
		}
	}
}

void Profiler::newFrame()
{
	assert(status);
	if(frameIndex > 0)
	{
		assert(categoryIndex == numUsedCategories);
	}
	frameIndex++;
	assert(frameIndex < MAX_FRAME_SAMPLES);
	categoryIndex = 0;
}

void Profiler::addEntry(const char* categroyName, float time) 
{

	assert(categoryIndex < MAX_PROFILE_CATEGORIES);
	ProfileCatagory& pc = categories[categoryIndex];
	if(frameIndex == 0)
	{
		pc.name = categroyName;
		numUsedCategories++;
		checkforDuplicateCategory(categroyName);
	}
	else
	{
		assert(pc.name == categroyName && categroyName != NULL);
		assert(categoryIndex < numUsedCategories);

	}
	categoryIndex++;
	pc.samples[frameIndex] = time;

};

char Profiler::getDelimiter(unsigned int index) const
{
	return ((index+1) < numUsedCategories) ?  ',' : '\n';
};

void Profiler::checkIsGood(bool* status) const
{
	*status = this->status;
}

void Profiler::checkforDuplicateCategory(const char* category) 
{
	for(unsigned int i = 0; i < categoryIndex; i++)
	{
		status &= (strcmp(categories[i].name,category) != 0);
	}
}
