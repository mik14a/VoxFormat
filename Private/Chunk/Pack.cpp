// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Pack.h"

FVoxChunkPack FVoxChunkPack::Read(const void*& data, int64& size)
{
	auto cpack = FVoxChunkPack();
	auto id = ReadData<uint32>(data, size);
	if (FVoxChunkPack::Tag != id) return cpack;

	cpack.Content = ReadData<int32>(data, size);
	cpack.Children = ReadData<int32>(data, size);
	cpack.Models = ReadData<int32>(data, size);
	return cpack;
}
