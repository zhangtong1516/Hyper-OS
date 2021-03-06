/**
 * syscall/syscalls/sys_exec_prog.cpp
 * create_proc syscall
 */
#include "sys_exec_prog.h"

sys_exec_prog::sys_exec_prog(int pid, program *prog)
	: syscall_t(syscall_id_t::EXEC_PROGRAM)
{
	this->pid = pid;
	this->prog = prog;
}

int sys_exec_prog::process()
{
	return proc_exec_program(pid, prog);
}
