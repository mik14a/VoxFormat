// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

/**
 * Shape node chunk
 */
struct FVoxNodeShape : FVoxNode
{
	static constexpr uint32 Tag = GenerateId('n', 'S', 'H', 'P');
	struct Model {
		int32 Id;
		DictionaryT Attributes;
	};
	using ModelT = TArray<FVoxNodeShape::Model>;

	ModelT Model;

	FVoxNodeShape() { FVoxNode::Tag = Tag; }
	static FVoxNodeShape* Read(const void*& data, int64& size);
};
