// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include <cstdint>

constexpr uint32_t GenerateId(char a, char b, char c, char d) {
	return (uint32_t)a | ((uint32_t)b << 8) | ((uint32_t)c << 16) |
		((uint32_t)d << 24);
}
