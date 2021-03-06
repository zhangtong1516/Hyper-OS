/**
 * interrupt/interrupts/clock_interrupt.h
 * Interrupt classes
 * Clock interrupt
 */

#include "clock_interrupt.h"
#include "../../status/status.h"
#include "../../core/core.h"
#include "../../logging/logging.h"
#include "../../core/cpus.h"

#include <thread>
#include <chrono>

clock_interrupt::clock_interrupt ()
	: external_interrupt_t ( interrupt_id_t::CLOCK_INTERRUPT )
{
}

void clock_interrupt::process ()
{
	logging::debug << "CPU #" << status.get_core ()->get_core_id () << " received a clock tick" << logging::log_endl;

	size_t id = status.get_core()->get_core_id();
	process_t *current = cores[id].get_current();
	if (current != nullptr) {
		if (current->tick()) {
			current->set_resched(true);
		}
	}
}
