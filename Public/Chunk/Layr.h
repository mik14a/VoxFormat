// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

#include <unordered_map>

/**
 * Layer chunk
 */
struct FVoxChunkLayr : public FVoxChunk
{
	static constexpr uint32_t Tag = GenerateId('L', 'A', 'Y', 'R');

	int32_t Id;
	std::string Name;
	bool Hidden;

	static FVoxChunkLayr Read(const void*& data, size_t& size);
};
