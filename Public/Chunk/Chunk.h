// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tag.h"

#include <cstdint>

template <typename T>
T PeekData(const void* data) {
	return *(T*)data;
}

template <typename T>
T ReadData(const void*& data, size_t& size) {
	T value = PeekData<T>(data);
	data = (T*)data + 1;
	size -= sizeof(T);
	return value;
}

/**
 * Chunk structure
 */
struct FVoxChunk {
	int32_t Content;
	int32_t Children;
};
