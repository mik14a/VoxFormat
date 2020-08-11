// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

/**
 * Scene translation vector
 */
struct FVoxTranslation {
	int32 X = 0, Y = 0, Z = 0;
};

/**
 * Scene rotation matrix
 */
struct FVoxRotation {
	int8_t M[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
};

/**
 * Transform node chunk
 */
struct FVoxNodeTransform : FVoxNode
{
	struct Frame {
		FVoxRotation Rotation;
		FVoxTranslation Translation;
	};

	static constexpr uint32 Tag = GenerateId('n', 'T', 'R', 'N');
	using FrameT = TArray<FVoxNodeTransform::Frame>;

	FString Name;
	bool Hidden;
	int32 Child;
	int32 Layer;
	FrameT Frame;

	FVoxNodeTransform() { FVoxNode::Tag = Tag; }
	static FVoxNodeTransform* Read(const void*& data, int64& size);
};
