// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

#include <vector>

/**
 * Xyzi chunk
 */
struct FVoxChunkXyzi : public FVoxChunk
{
	static constexpr uint32_t Tag = GenerateId('X', 'Y', 'Z', 'I');
	struct cell {
		uint8_t x, y, z, i;
		cell(uint8_t x, uint8_t y, uint8_t z, uint8_t i) : x(x), y(y), z(z), i(i) {}
	};

	int32_t Num;
	std::vector<cell> Voxels;

	static FVoxChunkXyzi Read(const void*& data, size_t& size);
};
