/**
 * message/msg_helper.h
 * Helper functions for message
 */

#include "msg_helper.h"
#include "message.h"
#include "../status/status.h"
#include "../core/core.h"
#include "../../dev/device_list.h"
#include <sstream>

std::string message::get_prefix ( const msg_info_t & info, std::string source )
{
	std::stringstream string_helper;
	string_helper << source;
	while ( string_helper.str ().size () < 20 ) {
		string_helper << " ";
	}
	string_helper << " : ";
	return string_helper.str ();
}

std::string message::get_suffix ( const msg_info_t & info, std::string source )
{
	std::stringstream string_helper;
	return string_helper.str ();
}

void message::output_message ( std::string msg )
{
	if ( OUT != nullptr ) {
		( *OUT ) << msg << std::endl;
	}
	if ( IO_DEVICE ) {
		device_desc::device_screen->write ( "m", msg );
	}
}

std::string message::wrap_core_info ( std::string str )
{
	return wrap_core_info ( str, status.get_core ()->get_core_id () );
}

std::string message::wrap_core_info ( std::string str, int core_id )
{
	std::stringstream string_helper;
	string_helper << str << " (" << core_id << ")";
    return string_helper.str ();
}
