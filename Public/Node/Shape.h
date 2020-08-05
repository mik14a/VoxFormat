// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

#include <vector>

/**
 * Shape node chunk
 */
struct FVoxNodeShape : FVoxNode
{
	static constexpr uint32_t Tag = GenerateId('n', 'S', 'H', 'P');
	struct Model {
		int32_t Id;
		dictionary_t Attributes;
	};
	using model_t = std::vector<FVoxNodeShape::Model>;

	model_t Model;

	FVoxNodeShape() { FVoxNode::Tag = Tag; }
	static FVoxNodeShape* Read(const void*& data, size_t& size);
};
