// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

/**
 * Pack chunk
 */
struct FVoxChunkPack : public FVoxChunk
{
	static constexpr uint32_t Tag = GenerateId('P', 'A', 'C', 'K');

	int32_t Models;

	static FVoxChunkPack Read(const void*& data, size_t& size);
};
