/**
 * core/cpus.cpp
 * CPU Cores
 */

#include "cpus.h"
#include "../logging/logging.h"
#include "../env/env.h"

CPU_core *cores;   // List of CPU cores

void init_cpus ( int n )
{
	logging::info << "Initialize " << n << " CPU(s)" << logging::log_endl;
	cores = new CPU_core[CPU_CORES];
	for ( int i = 0; i < CPU_CORES; ++i ){
		logging::debug << "Initialize CPU #" << i << logging::log_endl;
		cores[i].enable ();
		cores[i].enable_interrupt ();
	}
}

void destory_cpus ()
{
	logging::debug << "Destory CPUs" << logging::log_endl;

	delete[] cores;
}
