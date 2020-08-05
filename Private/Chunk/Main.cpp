// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Main.h"

FVoxChunkMain FVoxChunkMain::Read(const void*& data, size_t& size)
{
	auto cmain = FVoxChunkMain();
	auto id = ReadData<uint32_t>(data, size);
	if (FVoxChunkMain::Tag != id) return cmain;

	cmain.Content = ReadData<int32_t>(data, size);
	cmain.Children = ReadData<int32_t>(data, size);
	return cmain;
}
