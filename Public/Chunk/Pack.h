// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

/**
 * Pack chunk
 */
struct FVoxChunkPack : public FVoxChunk
{
	static constexpr uint32 Tag = GenerateId('P', 'A', 'C', 'K');

	int32 Models;

	static FVoxChunkPack Read(const void*& data, int64& size);
};
