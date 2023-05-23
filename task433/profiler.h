#pragma once
#include <cstdlib>
#include <chrono>

void* operator new(size_t bytes);

void* __malloc(size_t bytes);
#define malloc __malloc

namespace profile {
	void start_memory_profiling();
	void end_memory_profiling();

	size_t get_profiled_memory();

	void start_time_profiling();
	void end_time_profiling();

	std::chrono::microseconds get_profiled_time();
}
