// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Size.h"

FVoxChunkSize FVoxChunkSize::Read(const void*& data, int64& size)
{
	auto csize = FVoxChunkSize();
	auto id = ReadData<uint32>(data, size);
	if (FVoxChunkSize::Tag != id) return csize;

	csize.Content = ReadData<int32>(data, size);
	csize.Children = ReadData<int32>(data, size);
	csize.X = ReadData<int32>(data, size);
	csize.Y = ReadData<int32>(data, size);
	csize.Z = ReadData<int32>(data, size);
	return csize;
}
