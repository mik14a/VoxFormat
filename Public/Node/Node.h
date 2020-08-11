// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk/Chunk.h"
#include "Tag.h"

using DictionaryT = TMap<FString, FString>;

inline FString ReadString(const void*& data, int64& size) {
	auto bytes = ReadData<int32>(data, size);
	auto string = FString(bytes, (const char*)data);
	data = (char*)data + bytes;
	size -= bytes;
	return string;
}

inline DictionaryT ReadDictionary(const void*& data, int64& size) {
	DictionaryT dictionary;
	auto num = ReadData<int32>(data, size);
	for (auto i = 0; i < num; ++i) {
		auto key = ReadString(data, size);
		auto value = ReadString(data, size);
		dictionary.Emplace(MoveTemp(key), MoveTemp(value));
	}
	return dictionary;
}

/**
 * Node structure
 */
struct FVoxNode : FVoxChunk
{
	int32 Id;
	uint32 Tag;
};
