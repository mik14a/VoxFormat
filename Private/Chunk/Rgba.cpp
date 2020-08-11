// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Rgba.h"

FVoxChunkRgba FVoxChunkRgba::Read(const void*& data, int64& size)
{
	auto crgba = FVoxChunkRgba();
	auto id = ReadData<uint32>(data, size);
	if (FVoxChunkRgba::Tag != id) return crgba;

	crgba.Content = ReadData<int32>(data, size);
	crgba.Children = ReadData<int32>(data, size);
	for (auto n = 0; n < 256; ++n) {
		auto r = ReadData<uint8>(data, size);
		auto g = ReadData<uint8>(data, size);
		auto b = ReadData<uint8>(data, size);
		auto a = ReadData<uint8>(data, size);
		crgba.Palettes.Emplace(r, g, b, a);
	}
	return crgba;
}
