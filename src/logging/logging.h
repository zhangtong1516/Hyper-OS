/**
 * logging/logging.h
 * Logging module
 */

#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <mutex>

namespace logging
{
	extern thread_local std::stringstream BUF;
	extern std::ostream *OUT;
	extern std::mutex output_lock;

	/**
	* class log_endl_t
	* identifier to end a logger line
	*/
	class log_endl_t
	{

	};

	/**
	* class logger
	* can bu used to write logs
	*/
	class logger
	{
	public:
		logger ();
		logger ( bool _visible );
		~logger ();

		template < typename T >
		friend logger & operator << ( logger &buf, T a )
		{
			if ( buf.visible ) {
				BUF << a;
			}
			return buf;
		}

		friend logger & operator << ( logger &buf, log_endl_t a )
		{
			if ( buf.visible ) {
				{
					std::lock_guard < std::mutex > lock ( output_lock );

					( *OUT ) << BUF.str () << std::endl;
				}
				BUF.clear ();
				BUF.str ( "" );
			}
			return buf;
		}

	private:
		bool visible;
	};

	extern logger critical;
	extern logger error;
	extern logger warning;
	extern logger info;
	extern logger debug;

	extern log_endl_t log_endl;
}

void init_logger ();
