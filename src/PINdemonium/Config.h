#pragma once

#include <stdio.h>
#include "WriteInterval.h"
#include "ProcInfo.h"
#include <ctime>
#include <direct.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include "json.h"
namespace W {
	#include <windows.h>
}

//if it is uncommented the result will be saved on file otherwise they'll be printed to stdout
#define LOG_WRITE_TO_FILE 1

class Config
{
public:
	static Config* getInstance();
	FILE* Config::getLogFile();
	FILE* Config::getTestFile();
	//getter
	string getBasePath();
	string getCurrentDumpPath();
	string getWorkingDumpPath();
	string getCurrentReconstructedImportsPath();
	string getNotWorkingDumpPath();
	string getYaraResultPath();
	string getReportPath();
	string getScyllaDumperPath();
	string getScyllaWrapperPath();
	string getScyllaPluginsPath();
	long double getDumpNumber();
	string getFilteredWrites();
	
	
	//utils
	void incrementDumpNumber();
	void Config::closeLogFile();
	void Config::writeOnTimeLog(string s);
	void setWorking (int working);
	void setNewWorkingDirectory(bool isInjection);
	string getWorkingDir();
	string getHeapDir();
	string getInjectionDir();
	string getYaraExePath();
	string getYaraRulesPath();

	//--------------------------Command line Tuning Flags----------------------------
	static const bool  ATTACH_DEBUGGER;
	static const UINT32 MAX_JUMP_INTER_WRITE_SET_ANALYSIS;
	//Tunable from command line
	bool INTER_WRITESET_ANALYSIS_ENABLE; //Trigger the analysis inside a WriteSet in which WxorX is already broken if a Long JMP is encontered (MPress packer)
	UINT32 WRITEINTERVAL_MAX_NUMBER_JMP;
	UINT32 SKIP_DUMP;
	//mode of operation
	bool UNPACKING_MODE;
    bool ANTIEVASION_MODE;
	
	bool ANTIEVASION_MODE_INS_PATCHING;
	bool ANTIEVASION_MODE_SREAD;
	bool ANTIEVASION_MODE_SWRITE;

	bool ADVANCED_IAT_FIX;
	bool POLYMORPHIC_CODE_PATCH;
	bool NULLIFY_UNK_IAT_ENTRY;
	string PLUGIN_FULL_PATH;
	bool CALL_PLUGIN_FLAG;

	//Timing attack configurations
	static const UINT32 TIMEOUT_TIMER_SECONDS;
	static const UINT32 TICK_DIVISOR; //this is used in order to lowe the ticks returnedd from GetTickCount and timeGetTime 
	static const UINT32 CC_DIVISOR; // this is used in order to lower the microseconds returned from the QueryPerformanceCounter 
	static const UINT32 KSYSTEM_TIME_DIVISOR; // this is used to lower the LONG lowpart returned from the timeGetTime in the struct _KSYSTEM_TIME inside kuser_shared_data
	static const UINT32 RDTSC_DIVISOR;
	static const UINT32 INTERRUPT_TIME_DIVISOR;
	static const UINT32 SYSTEM_TIME_DIVISOR;

		

private:
	Config::Config(string config_path);
	static Config* instance;
	FILE *log_file;
	FILE *test_file;
	string working_dir;
	string base_path;
	string not_working_path;
	string working_path;        //Path of the final (IAT fixed) Dump
	string cur_list_path;		 //Path of the list of the detected function
	string heap_dir;
	long double dump_number;
	string getCurDateAndTime();
	int numberOfBadImports;
	void loadJson(string path);
	int working;

	//files and paths
	string dependecies_path;
	string results_path;
	string plugins_path; 
	string log_filename;
	string report_filename;
	string yara_exe_path;
	string yara_rules_path;
	string dep_scylla_dumper_path;
	string dep_scylla_wrapper_path;
	string not_working_directory;
	//command line tuning flags
	string filtered_writes;        //Which write instructions are filtered(possible values: 'stack teb')
	UINT32 timeout;



};

