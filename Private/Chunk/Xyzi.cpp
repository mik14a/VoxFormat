// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Xyzi.h"

FVoxChunkXyzi FVoxChunkXyzi::Read(const void*& data, int64& size)
{
	auto cxyzi = FVoxChunkXyzi();
	auto id = ReadData<uint32>(data, size);
	if (FVoxChunkXyzi::Tag != id) return cxyzi;

	cxyzi.Content = ReadData<int32>(data, size);
	cxyzi.Children = ReadData<int32>(data, size);
	cxyzi.Num = ReadData<int32>(data, size);
	for (auto n = 0; n < cxyzi.Num; ++n) {
		auto x = ReadData<uint8>(data, size);
		auto y = ReadData<uint8>(data, size);
		auto z = ReadData<uint8>(data, size);
		auto i = ReadData<uint8>(data, size);
		cxyzi.Voxels.Emplace(x, y, z, i);
	}
	return cxyzi;
}
