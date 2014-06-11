#ifdef LOG_ON
#include "Logger.h"

vector <std::string> Logger::logList;
vector <Severity> Logger::severityList;

ENGINE_SHARED Logger::Logger(void){}
ENGINE_SHARED Logger::~Logger(void){}

ENGINE_SHARED void Logger::StringReplace(string& str, const string& from, const string& to)
{
	size_t pos = 0;
	do 
	{
		pos = str.find(from, pos);
		if( pos != string::npos )
		{
			str.replace( pos, from.length(), to);
			pos += to.length();
		}
	} while (pos != string::npos);
}

ENGINE_SHARED string Logger::Sanitize(string str)
{

	StringReplace( str, "<" , "&lt" );
	StringReplace( str, ">" , "&gt" );

	return str;
}

ENGINE_SHARED void Logger::Log( Severity severity, const char* message, const char * logFile, int logLine)
{
	std::stringstream ss;
	ss << logFile << "(" << logLine << ") - " << Sanitize(message); 
	std::string logEntry;
	logEntry = ss.str();
	
	logList.push_back(logEntry);
	severityList.push_back(severity);
}
ENGINE_SHARED void Logger::shutDown()
{
	WriteFile();
}
ENGINE_SHARED void Logger::WriteFile()
{
	std::ofstream myFile;
	
	myFile.open("log.html");

	myFile << "<!DOCTYPE html>" << std::endl << "<html>" 
		<< std::endl << "<head>" << std::endl << "<title>Log File</title>" << std::endl << "</head>"
		<< std::endl << "<body bgcolor = '#FFFFFF' >" << std::endl << "<h2>Log File</h2>"
		<< std::endl;
	for(unsigned int i = 0; i < logList.size(); i ++)
	{
		switch (severityList[i])
		{
			case Info:
				myFile <<  "<font color=\"#000000\">";
				break;

			case Warning:
				myFile <<  "<font color=\"#CCCC00\">";
				break;

			case Error:
				myFile <<  "<font color=\"#CC0000\">"; 
				break;

			case Severe:
				myFile <<  "<font color=\"#AA0000\">"; 
				break;
		}
		myFile << logList[i].c_str() << "</font><br>";
	}
	myFile << "</body>" << std::endl << "</html>";	
	myFile.close();
}

#endif