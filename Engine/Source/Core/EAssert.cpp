#include "EAssert.h"
#include <iostream>
void CustomAssert(const std::string& experession, const std::string& filename, int line)
{
	std::cerr << "Assertion failed: (" << experession << ") , file: " << filename << ", line: " << line << std::endl;
	std::abort();
}