// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Chunk/Layr.h"
#include "Chunk/Matl.h"
#include "Chunk/Rgba.h"
#include "Chunk/Size.h"
#include "Chunk/Xyzi.h"
#include "Node/Group.h"
#include "Node/Shape.h"
#include "Node/Transform.h"

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

/**
 * Vox file format
 * @see https://github.com/ephtracy/voxel-model/blob/master/MagicaVoxel-file-format-vox.txt
 * @see https://github.com/ephtracy/voxel-model/blob/master/MagicaVoxel-file-format-vox-extension.txt
 */
struct VOXFORMAT_API FVox
{
	//! VOX format file tag.
	static constexpr uint32_t Tag = GenerateId('V', 'O', 'X', ' ');

	using node_t = std::unordered_map<int32_t, std::shared_ptr<FVoxNode>>;
	using material_t = std::unordered_map<int32_t, FVoxChunkMatl>;
	using layer_t = std::unordered_map<int32_t, FVoxChunkLayr>;

	int32_t Version;				//!< Vox file version.
	std::vector<FVoxChunkSize> Size;	//!< Model size.
	std::vector<FVoxChunkXyzi> Voxel;	//!< Model voxels.
	FVoxChunkRgba Palette;				//!< Palette.

	node_t Node;			//!< extension nodes.
	material_t Material;	//!< extension materials.
	layer_t Layer;			//!< extension layers.

	//! Default palette.
	static const uint32_t DefaultPalette[256];
	//! Create vox format data from memory.
	static FVox Read(const void*& data, size_t& size);
};
