// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Pack.h"

FVoxChunkPack FVoxChunkPack::Read(const void*& data, size_t& size)
{
	auto cpack = FVoxChunkPack();
	auto id = ReadData<uint32_t>(data, size);
	if (FVoxChunkPack::Tag != id) return cpack;

	cpack.Content = ReadData<int32_t>(data, size);
	cpack.Children = ReadData<int32_t>(data, size);
	cpack.Models = ReadData<int32_t>(data, size);
	return cpack;
}
