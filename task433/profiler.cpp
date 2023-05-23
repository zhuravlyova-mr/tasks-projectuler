#include "profiler.h"

size_t captured_memory = 0;
bool should_capture_memory = false;

std::chrono::high_resolution_clock::time_point start_time;
std::chrono::high_resolution_clock::duration captured_time;

#undef malloc

void* operator new(size_t bytes) {
	if (should_capture_memory)
	{
		captured_memory += bytes;
	}

	return malloc(bytes);
}

void* __malloc(size_t bytes) {
	if (should_capture_memory)
	{
		captured_memory += bytes;
	}

	return malloc(bytes);
}

namespace profile {
	void start_memory_profiling() {
		captured_memory = 0;
		should_capture_memory = true;
	}

	void end_memory_profiling() {
		should_capture_memory = false;
	}

	size_t get_profiled_memory() {
		return captured_memory;
	}

	void start_time_profiling() {
		start_time = std::chrono::high_resolution_clock::now();
	}

	void end_time_profiling() {
		captured_time = std::chrono::high_resolution_clock::now() - start_time;
	}

	std::chrono::microseconds get_profiled_time() {
		return std::chrono::duration_cast<std::chrono::microseconds>(captured_time);
	}
}
