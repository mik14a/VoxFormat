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

/**
 * Vox file format
 * @see https://github.com/ephtracy/voxel-model/blob/master/MagicaVoxel-file-format-vox.txt
 * @see https://github.com/ephtracy/voxel-model/blob/master/MagicaVoxel-file-format-vox-extension.txt
 */
struct VOXFORMAT_API FVox
{
	//! VOX format file tag.
	static constexpr uint32 Tag = GenerateId('V', 'O', 'X', ' ');

	using NodeT = TMap<int32, TSharedPtr<FVoxNode>>;
	using MaterialT = TMap<int32, FVoxChunkMatl>;
	using LayerT = TMap<int32, FVoxChunkLayr>;

	int32 Version;					//!< Vox file version.
	TArray<FVoxChunkSize> Size;		//!< Model size.
	TArray<FVoxChunkXyzi> Voxel;	//!< Model voxels.
	FVoxChunkRgba Palette;			//!< Palette.

	NodeT Node;			//!< extension nodes.
	MaterialT Material;	//!< extension materials.
	LayerT Layer;		//!< extension layers.

	//! Default palette.
	static const uint32 DefaultPalette[256];
	//! Create vox format data from memory.
	static FVox Read(const void*& data, int64& size);
};
