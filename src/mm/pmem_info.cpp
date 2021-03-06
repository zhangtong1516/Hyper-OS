/*
 * Memory Infomations
 */

#include "pmem_info.h"
#include "../env/env.h"

const size_t PAGE_SIZE = 1 << 12;
const size_t PAGE_NUM = MEMORY_SIZE / PAGE_SIZE;
const size_t VM_SIZE = 1u << 31;
const size_t VPAGE_NUM = VM_SIZE / PAGE_SIZE;
