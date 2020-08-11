// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

/**
 * Layer chunk
 */
struct FVoxChunkLayr : public FVoxChunk
{
	static constexpr uint32 Tag = GenerateId('L', 'A', 'Y', 'R');

	int32 Id;
	FString Name;
	bool Hidden;

	static FVoxChunkLayr Read(const void*& data, int64& size);
};
