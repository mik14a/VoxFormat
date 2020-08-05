// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

#include <iostream>

/**
 * Size chunk
 */
struct FVoxChunkSize : public FVoxChunk
{
	static constexpr uint32_t Tag = GenerateId('S', 'I', 'Z', 'E');

	int32_t X, Y, Z;

	static FVoxChunkSize Read(const void*& data, size_t& size);
};
