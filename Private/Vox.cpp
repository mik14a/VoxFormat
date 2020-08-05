// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Vox.h"
#include "Chunk/Layr.h"
#include "Chunk/Main.h"
#include "Chunk/Matl.h"
#include "Chunk/Matt.h"
#include "Chunk/Pack.h"
#include "Chunk/Rgba.h"
#include "Chunk/Size.h"
#include "Chunk/Xyzi.h"
#include "Node/Group.h"
#include "Node/Shape.h"
#include "Node/Transform.h"

#include <iostream>
#include <memory>

FVox FVox::Read(const void*& data, size_t& size)
{
	FVox vox;
	vox.Version = 150;
	auto main = FVoxChunkMain::Read(data, size);
	while (0 < size) {
		auto id = PeekData<uint32_t>(data);
		switch (id) {
		case FVoxChunkPack::Tag: {
			auto pack = FVoxChunkPack::Read(data, size);
		} break;
		case FVoxChunkSize::Tag: {
			vox.Size.push_back(FVoxChunkSize::Read(data, size));
		} break;
		case FVoxChunkXyzi::Tag: {
			vox.Voxel.push_back(FVoxChunkXyzi::Read(data, size));
		} break;
		case FVoxChunkRgba::Tag: {
			vox.Palette = FVoxChunkRgba::Read(data, size);
		} break;
		case FVoxChunkMatl::Tag: {
			auto matl = FVoxChunkMatl::Read(data, size);
			vox.Material.emplace(matl.Id, std::move(matl));
		} break;
		case FVoxChunkLayr::Tag: {
			auto layr = FVoxChunkLayr::Read(data, size);
			vox.Layer.emplace(layr.Id, std::move(layr));
		} break;
		case FVoxNodeTransform::Tag: {
			auto transform = std::shared_ptr<FVoxNodeTransform>(FVoxNodeTransform::Read(data, size));
			vox.Node.emplace(transform->Id, transform);
		} break;
		case FVoxNodeGroup::Tag: {
			auto group = std::shared_ptr<FVoxNodeGroup>(FVoxNodeGroup::Read(data, size));
			vox.Node.emplace(group->Id, group);
		} break;
		case FVoxNodeShape::Tag: {
			auto shape = std::shared_ptr<FVoxNodeShape>(FVoxNodeShape::Read(data, size));
			vox.Node.emplace(shape->Id, shape);
		} break;
		default: {
			id = ReadData<uint32_t>(data, size);
			auto content = ReadData<int32_t>(data, size);
			auto children = ReadData<int32_t>(data, size);
			data = (char*)data + content;
			size -= content;
		} break;
		}
	}
	return vox;
}

const uint32_t FVox::DefaultPalette[256] =
{
  0xffffffff, 0xffffffcc, 0xffffff99, 0xffffff66, 0xffffff33, 0xffffff00, 0xffffccff, 0xffffcccc, 0xffffcc99, 0xffffcc66, 0xffffcc33, 0xffffcc00, 0xffff99ff, 0xffff99cc, 0xffff9999, 0xffff9966,
  0xffff9933, 0xffff9900, 0xffff66ff, 0xffff66cc, 0xffff6699, 0xffff6666, 0xffff6633, 0xffff6600, 0xffff33ff, 0xffff33cc, 0xffff3399, 0xffff3366, 0xffff3333, 0xffff3300, 0xffff00ff, 0xffff00cc,
  0xffff0099, 0xffff0066, 0xffff0033, 0xffff0000, 0xffccffff, 0xffccffcc, 0xffccff99, 0xffccff66, 0xffccff33, 0xffccff00, 0xffccccff, 0xffcccccc, 0xffcccc99, 0xffcccc66, 0xffcccc33, 0xffcccc00,
  0xffcc99ff, 0xffcc99cc, 0xffcc9999, 0xffcc9966, 0xffcc9933, 0xffcc9900, 0xffcc66ff, 0xffcc66cc, 0xffcc6699, 0xffcc6666, 0xffcc6633, 0xffcc6600, 0xffcc33ff, 0xffcc33cc, 0xffcc3399, 0xffcc3366,
  0xffcc3333, 0xffcc3300, 0xffcc00ff, 0xffcc00cc, 0xffcc0099, 0xffcc0066, 0xffcc0033, 0xffcc0000, 0xff99ffff, 0xff99ffcc, 0xff99ff99, 0xff99ff66, 0xff99ff33, 0xff99ff00, 0xff99ccff, 0xff99cccc,
  0xff99cc99, 0xff99cc66, 0xff99cc33, 0xff99cc00, 0xff9999ff, 0xff9999cc, 0xff999999, 0xff999966, 0xff999933, 0xff999900, 0xff9966ff, 0xff9966cc, 0xff996699, 0xff996666, 0xff996633, 0xff996600,
  0xff9933ff, 0xff9933cc, 0xff993399, 0xff993366, 0xff993333, 0xff993300, 0xff9900ff, 0xff9900cc, 0xff990099, 0xff990066, 0xff990033, 0xff990000, 0xff66ffff, 0xff66ffcc, 0xff66ff99, 0xff66ff66,
  0xff66ff33, 0xff66ff00, 0xff66ccff, 0xff66cccc, 0xff66cc99, 0xff66cc66, 0xff66cc33, 0xff66cc00, 0xff6699ff, 0xff6699cc, 0xff669999, 0xff669966, 0xff669933, 0xff669900, 0xff6666ff, 0xff6666cc,
  0xff666699, 0xff666666, 0xff666633, 0xff666600, 0xff6633ff, 0xff6633cc, 0xff663399, 0xff663366, 0xff663333, 0xff663300, 0xff6600ff, 0xff6600cc, 0xff660099, 0xff660066, 0xff660033, 0xff660000,
  0xff33ffff, 0xff33ffcc, 0xff33ff99, 0xff33ff66, 0xff33ff33, 0xff33ff00, 0xff33ccff, 0xff33cccc, 0xff33cc99, 0xff33cc66, 0xff33cc33, 0xff33cc00, 0xff3399ff, 0xff3399cc, 0xff339999, 0xff339966,
  0xff339933, 0xff339900, 0xff3366ff, 0xff3366cc, 0xff336699, 0xff336666, 0xff336633, 0xff336600, 0xff3333ff, 0xff3333cc, 0xff333399, 0xff333366, 0xff333333, 0xff333300, 0xff3300ff, 0xff3300cc,
  0xff330099, 0xff330066, 0xff330033, 0xff330000, 0xff00ffff, 0xff00ffcc, 0xff00ff99, 0xff00ff66, 0xff00ff33, 0xff00ff00, 0xff00ccff, 0xff00cccc, 0xff00cc99, 0xff00cc66, 0xff00cc33, 0xff00cc00,
  0xff0099ff, 0xff0099cc, 0xff009999, 0xff009966, 0xff009933, 0xff009900, 0xff0066ff, 0xff0066cc, 0xff006699, 0xff006666, 0xff006633, 0xff006600, 0xff0033ff, 0xff0033cc, 0xff003399, 0xff003366,
  0xff003333, 0xff003300, 0xff0000ff, 0xff0000cc, 0xff000099, 0xff000066, 0xff000033, 0xffee0000, 0xffdd0000, 0xffbb0000, 0xffaa0000, 0xff880000, 0xff770000, 0xff550000, 0xff440000, 0xff220000,
  0xff110000, 0xff00ee00, 0xff00dd00, 0xff00bb00, 0xff00aa00, 0xff008800, 0xff007700, 0xff005500, 0xff004400, 0xff002200, 0xff001100, 0xff0000ee, 0xff0000dd, 0xff0000bb, 0xff0000aa, 0xff000088,
  0xff000077, 0xff000055, 0xff000044, 0xff000022, 0xff000011, 0xffeeeeee, 0xffdddddd, 0xffbbbbbb, 0xffaaaaaa, 0xff888888, 0xff777777, 0xff555555, 0xff444444, 0xff222222, 0xff111111, 0xff000000
};
