#include "BadLength.h"

const char* BadLength::what() const noexcept
{
	return "ERROR: Invalid Length!";
}