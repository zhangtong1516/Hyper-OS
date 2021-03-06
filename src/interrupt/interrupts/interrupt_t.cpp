/**
 * interrupt/interrupts/interrupt_t.h
 * Interrupt classes
 * Abstract base class interrupt_t
 */

#include "interrupt_t.h"

#include <sstream>

interrupt_t::interrupt_t ( interrupt_id_t id )
	: interrupt_id ( id )
{
}

interrupt_t::~interrupt_t ()
{
}

void interrupt_t::set_interrupt_id ( interrupt_id_t id )
{
	interrupt_id = id;
}

interrupt_id_t interrupt_t::get_interrupt_id () const
{
	return interrupt_id;
}

std::promise < int > & interrupt_t::get_return_promise ()
{
	return return_promise;
}

bool interrupt_t::is_internal_interrupt () const
{
	return false;
}

bool interrupt_t::is_external_interrupt () const
{
	return false;
}

bool interrupt_t::is_lapic_signal () const
{
	return false;
}

bool interrupt_t::is_io_apic_signal () const
{
	return false;
}

std::string interrupt_t::to_string ()
{
	std::stringstream string_buf;
	string_buf << "id : " << static_cast < int > ( get_interrupt_id () );
	return string_buf.str ();
}
