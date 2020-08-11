// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Matl.h"

FVoxChunkMatl FVoxChunkMatl::Read(const void*& data, int64& size)
{
	auto cmatl = FVoxChunkMatl();
	auto id = ReadData<uint32>(data, size);
	if (FVoxChunkMatl::Tag != id) return cmatl;

	cmatl.Content = ReadData<int32>(data, size);
	cmatl.Children = ReadData<int32>(data, size);
	cmatl.Id = ReadData<int32>(data, size);
	cmatl.Properties = ReadDictionary(data, size);
	return cmatl;
}
