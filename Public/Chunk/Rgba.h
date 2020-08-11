// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

/**
 * Rgba chunk
 */
struct FVoxChunkRgba : public FVoxChunk
{
	static constexpr uint32 Tag = GenerateId('R', 'G', 'B', 'A');
	struct Color {
		uint8 R, G, B, A;
		Color(uint8 r, uint8 g, uint8 b, uint8 a)
			: R(r), G(g), B(b), A(a) {}
	};

	TArray<Color> Palettes;

	static FVoxChunkRgba Read(const void*& data, int64& size);
};
