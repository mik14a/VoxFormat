// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Rgba.h"

FVoxChunkRgba FVoxChunkRgba::Read(const void*& data, size_t& size)
{
	auto crgba = FVoxChunkRgba();
	auto id = ReadData<uint32_t>(data, size);
	if (FVoxChunkRgba::Tag != id) return crgba;

	crgba.Content = ReadData<int32_t>(data, size);
	crgba.Children = ReadData<int32_t>(data, size);
	for (auto n = 0; n < 256; ++n) {
		auto r = ReadData<uint8_t>(data, size);
		auto g = ReadData<uint8_t>(data, size);
		auto b = ReadData<uint8_t>(data, size);
		auto a = ReadData<uint8_t>(data, size);
		crgba.Palettes.emplace_back(r, g, b, a);
	}
	return crgba;
}
