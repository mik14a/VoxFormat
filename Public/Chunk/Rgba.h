// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"

#include <vector>

/**
 * Rgba chunk
 */
struct FVoxChunkRgba : public FVoxChunk
{
	static constexpr uint32_t Tag = GenerateId('R', 'G', 'B', 'A');
	struct color {
		uint8_t r, g, b, a;
		color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
			: r(r), g(g), b(b), a(a) {}
	};

	std::vector<color> Palettes;

	static FVoxChunkRgba Read(const void*& data, size_t& size);
};
