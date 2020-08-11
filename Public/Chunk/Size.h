// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

/**
 * Size chunk
 */
struct FVoxChunkSize : public FVoxChunk
{
	static constexpr uint32 Tag = GenerateId('S', 'I', 'Z', 'E');

	int32 X, Y, Z;

	static FVoxChunkSize Read(const void*& data, int64& size);
};
