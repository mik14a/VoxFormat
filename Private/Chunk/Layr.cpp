// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Layr.h"
#include "Node/Node.h"

FVoxChunkLayr FVoxChunkLayr::Read(const void*& data, int64& size)
{
	auto clayr = FVoxChunkLayr();
	auto id = ReadData<uint32>(data, size);
	if (FVoxChunkLayr::Tag != id) return clayr;

	clayr.Content = ReadData<int32>(data, size);
	clayr.Children = ReadData<int32>(data, size);
	clayr.Id = ReadData<int32>(data, size);
	auto attribute = ReadDictionary(data, size);
	auto name = attribute.Find("_name");
	clayr.Name = name ? *name : FString();
	auto hidden = attribute.Find("_hidden");
	clayr.Hidden = hidden ? FCString::ToBool(**hidden) : false;
	ReadData<int32>(data, size);  // reserved
	return clayr;
}
