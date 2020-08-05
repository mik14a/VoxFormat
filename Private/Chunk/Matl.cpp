// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Matl.h"

FVoxChunkMatl FVoxChunkMatl::Read(const void*& data, size_t& size)
{
	auto cmatl = FVoxChunkMatl();
	auto id = ReadData<uint32_t>(data, size);
	if (FVoxChunkMatl::Tag != id) return cmatl;

	cmatl.Content = ReadData<int32_t>(data, size);
	cmatl.Children = ReadData<int32_t>(data, size);
	cmatl.Id = ReadData<int32_t>(data, size);
	cmatl.Properties = ReadDictionary(data, size);
	return cmatl;
}
