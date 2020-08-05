// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Size.h"

FVoxChunkSize FVoxChunkSize::Read(const void*& data, size_t& size)
{
	auto csize = FVoxChunkSize();
	auto id = ReadData<uint32_t>(data, size);
	if (FVoxChunkSize::Tag != id) return csize;

	csize.Content = ReadData<int32_t>(data, size);
	csize.Children = ReadData<int32_t>(data, size);
	csize.X = ReadData<int32_t>(data, size);
	csize.Y = ReadData<int32_t>(data, size);
	csize.Z = ReadData<int32_t>(data, size);
	return csize;
}
