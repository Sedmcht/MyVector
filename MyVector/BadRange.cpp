#include "BadRange.h"

const char* BadRange::what() const noexcept
{
	return "ERROR: Out of Range!";
}