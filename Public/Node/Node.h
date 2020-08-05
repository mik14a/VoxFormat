// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chunk/Chunk.h"
#include "Tag.h"

#include <cstdint>
#include <string>
#include <unordered_map>

using dictionary_t = std::unordered_map<std::string, std::string>;

inline std::string ReadString(const void*& data, size_t& size) {
	auto bytes = ReadData<int32_t>(data, size);
	std::string string((const char*)data, bytes);
	data = (char*)data + bytes;
	size -= bytes;
	return string;
}

inline dictionary_t ReadDictionary(const void*& data, size_t& size) {
	dictionary_t dictionary;
	auto num = ReadData<int32_t>(data, size);
	for (auto i = 0; i < num; ++i) {
		auto key = ReadString(data, size);
		auto value = ReadString(data, size);
		dictionary.emplace(std::move(key), std::move(value));
	}
	return dictionary;
}

/**
 * Node structure
 */
struct FVoxNode : FVoxChunk
{
	int32_t Id;
	uint32_t Tag;
};
