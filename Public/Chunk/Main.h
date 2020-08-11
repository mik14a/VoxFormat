// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

/**
 * Main chunk
 */
struct FVoxChunkMain : public FVoxChunk
{
	static constexpr uint32 Tag = GenerateId('M', 'A', 'I', 'N');

	static FVoxChunkMain Read(const void*& data, int64& size);
};
