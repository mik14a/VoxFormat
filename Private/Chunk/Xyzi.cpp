// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Xyzi.h"

FVoxChunkXyzi FVoxChunkXyzi::Read(const void*& data, size_t& size)
{
	auto cxyzi = FVoxChunkXyzi();
	auto id = ReadData<uint32_t>(data, size);
	if (FVoxChunkXyzi::Tag != id) return cxyzi;

	cxyzi.Content = ReadData<int32_t>(data, size);
	cxyzi.Children = ReadData<int32_t>(data, size);
	cxyzi.Num = ReadData<int32_t>(data, size);
	for (auto n = 0; n < cxyzi.Num; ++n) {
		auto x = ReadData<uint8_t>(data, size);
		auto y = ReadData<uint8_t>(data, size);
		auto z = ReadData<uint8_t>(data, size);
		auto i = ReadData<uint8_t>(data, size);
		cxyzi.Voxels.emplace_back(x, y, z, i);
	}
	return cxyzi;
}
