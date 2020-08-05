// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

#include "Node/Node.h"

/**
 * Matl chunk
 */
struct FVoxChunkMatl : public FVoxChunk
{
	static constexpr uint32_t Tag = GenerateId('M', 'A', 'T', 'L');

	int32_t Id;
	dictionary_t Properties;

	static FVoxChunkMatl Read(const void*& data, size_t& size);
};
