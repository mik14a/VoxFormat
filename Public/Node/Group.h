// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

#include <string>
#include <unordered_map>

/**
 * Group node chunk
 */
struct FVoxNodeGroup : FVoxNode
{
	static constexpr uint32_t Tag = GenerateId('n', 'G', 'R', 'P');

	std::vector<int32_t> Child;

	FVoxNodeGroup() { FVoxNode::Tag = Tag; }
	static FVoxNodeGroup* Read(const void*& data, size_t& size);
};
