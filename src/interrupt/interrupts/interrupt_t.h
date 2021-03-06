/**
 * interrupt/interrupts/interrupt_t.h
 * Interrupt classes
 * Abstract base class interrupt_t
 */

#pragma once

#include "../interrupt_id.h"
#include <string>
#include <future>

class interrupt_t
{
public:
	interrupt_t ( interrupt_id_t id );
	virtual ~interrupt_t ();

	void set_interrupt_id ( interrupt_id_t id );
	interrupt_id_t get_interrupt_id () const;

	std::promise < int > & get_return_promise ();

	virtual bool is_internal_interrupt () const;   // check whether the interrupt is an internal CPU exception
	virtual bool is_external_interrupt () const;   // check whether the interrupt is an external CPU exception
	virtual bool is_lapic_signal () const;         // check whether the interrupt is a signal to Local APIC
	virtual bool is_io_apic_signal () const;       // check whether the interrupt is a signal to I/O APIC

	virtual void process () = 0;

	virtual std::string to_string ();

private:
	interrupt_id_t interrupt_id;

	std::promise < int > return_promise;
};
