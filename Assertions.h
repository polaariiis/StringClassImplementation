#pragma once
#include <stdexcept>
#include <sstream>

#define EXPECT_TRUE(x) \
    if (!(x)) throw std::runtime_error("EXPECT_TRUE failed: " #x)

#define EXPECT_EQ(a, b) \
    if (!((a) == (b))) { \
        std::ostringstream oss; \
        oss << "EXPECT_EQ failed: " << #a << " != " << #b; \
        throw std::runtime_error(oss.str()); \
    }