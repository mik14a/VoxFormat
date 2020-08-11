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
	static constexpr uint32 Tag = GenerateId('M', 'A', 'T', 'L');

	int32 Id;
	DictionaryT Properties;

	static FVoxChunkMatl Read(const void*& data, int64& size);
};
