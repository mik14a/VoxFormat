// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

constexpr uint32 GenerateId(char a, char b, char c, char d) {
	return (uint32)a | ((uint32)b << 8) | ((uint32)c << 16) |
		((uint32)d << 24);
}
