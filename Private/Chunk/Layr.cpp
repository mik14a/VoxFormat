// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Chunk/Layr.h"
#include "Node/Node.h"

FVoxChunkLayr FVoxChunkLayr::Read(const void*& data, size_t& size)
{
	auto clayr = FVoxChunkLayr();
	auto id = ReadData<uint32_t>(data, size);
	if (FVoxChunkLayr::Tag != id) return clayr;

	clayr.Content = ReadData<int32_t>(data, size);
	clayr.Children = ReadData<int32_t>(data, size);
	clayr.Id = ReadData<int32_t>(data, size);
	auto attribute = ReadDictionary(data, size);
	auto name = attribute.find("_name");
	clayr.Name = name != attribute.end() ? name->second : std::string();
	auto hidden = attribute.find("_hidden");
	clayr.Hidden = hidden != attribute.end() ? (std::stoi(hidden->second) != 0) : false;
	ReadData<int32_t>(data, size);  // reserved
	return clayr;
}
