// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

#include <string>
#include <unordered_map>

/**
 * Scene translation vector
 */
struct translation {
	int32_t x = 0, y = 0, z = 0;
};

/**
 * Scene rotation matrix
 */
struct rotation {
	int8_t m[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
};

/**
 * Transform node chunk
 */
struct FVoxNodeTransform : FVoxNode
{
	struct Frame {
		rotation rotation;
		translation translation;
	};

	static constexpr uint32_t Tag = GenerateId('n', 'T', 'R', 'N');
	using frame_t = std::vector<FVoxNodeTransform::Frame>;

	std::string Name;
	bool Hidden;
	int32_t Child;
	int32_t Layer;
	frame_t Frame;

	FVoxNodeTransform() { FVoxNode::Tag = Tag; }
	static FVoxNodeTransform* Read(const void*& data, size_t& size);
};
