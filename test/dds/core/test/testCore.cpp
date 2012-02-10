#include "testCore.hpp"

#include <dds/core/Query.hpp>

int dds::core::test::testCore() {
	Query query("x < 100 AND y < 200");
	return 0;
}
