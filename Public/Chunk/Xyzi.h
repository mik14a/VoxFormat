// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

/**
 * Xyzi chunk
 */
struct FVoxChunkXyzi : public FVoxChunk
{
	static constexpr uint32 Tag = GenerateId('X', 'Y', 'Z', 'I');
	struct cell {
		uint8 x, y, z, i;
		cell(uint8 x, uint8 y, uint8 z, uint8 i) : x(x), y(y), z(z), i(i) {}
	};

	int32 Num;
	TArray<cell> Voxels;

	static FVoxChunkXyzi Read(const void*& data, int64& size);
};
