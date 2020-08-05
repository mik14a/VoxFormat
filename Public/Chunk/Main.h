// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

/**
 * Main chunk
 */
struct FVoxChunkMain : public FVoxChunk
{
	static constexpr uint32_t Tag = GenerateId('M', 'A', 'I', 'N');

	static FVoxChunkMain Read(const void*& data, size_t& size);
};
