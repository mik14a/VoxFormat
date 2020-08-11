// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

/**
 * Group node chunk
 */
struct FVoxNodeGroup : FVoxNode
{
	static constexpr uint32 Tag = GenerateId('n', 'G', 'R', 'P');

	TArray<int32> Child;

	FVoxNodeGroup() { FVoxNode::Tag = Tag; }
	static FVoxNodeGroup* Read(const void*& data, int64& size);
};
