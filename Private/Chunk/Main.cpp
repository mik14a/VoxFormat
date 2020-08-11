// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Main.h"

FVoxChunkMain FVoxChunkMain::Read(const void*& data, int64& size)
{
	auto cmain = FVoxChunkMain();
	auto id = ReadData<uint32>(data, size);
	if (FVoxChunkMain::Tag != id) return cmain;

	cmain.Content = ReadData<int32>(data, size);
	cmain.Children = ReadData<int32>(data, size);
	return cmain;
}
