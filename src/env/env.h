/**
 * env.h
 * Environment Variables
 */

#pragma once

#include <cstdint>
#include <cstddef>

// CPU Information
extern const int CPU_CORES;   // Number of CPU cores

// Memory information
extern const size_t MEMORY_SIZE;   // The size of the physical memory

// Motherboard information
extern const int MOTHERBOARD_NUM;   // The number of motherboards

// Logging
extern const char *LOG_FILE_NAME;   // File name to write log, NULL if write to stdout

enum LOGGING_LEVEL   // Logging levels
{
	NONE,
	CRITICAL,
	ERROR,
	WARNING,
	INFO,
	DEBUG
};
extern const int LOG_LEVEL;   // Logging level to be used

// Message service
extern const char *MESSAGE_FILE_NAME;   // File name to write messages, write to stdout if is NULL and IO_DEVICE is 0

// Unittest
extern const bool TEST; // test = true <=> run unit test

// I/O Device
extern const int IO_DEVICE;   // I/O Device method

// Tick interval of clock device ( ms )
extern const int CLOCK_INTERVAL;
