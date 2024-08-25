#pragma once

#include <cassert>

#define GINNER_CONSTEXPR constexpr

#define GINNER_EXPLICIT explicit

#define GINNER_ASSERT_LENGTH(lentgh, max) (assert ((lentgh) >= 0 && (lentgh) < (max)))