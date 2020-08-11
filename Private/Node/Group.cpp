// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Node/Group.h"

FVoxNodeGroup* FVoxNodeGroup::Read(const void*& data, int64& size)
{
	auto* ngrp = new FVoxNodeGroup();
	auto id = ReadData<uint32>(data, size);
	if (FVoxNodeGroup::Tag != id) return ngrp;

	ngrp->Content = ReadData<int32>(data, size);
	ngrp->Children = ReadData<int32>(data, size);
	ngrp->Id = ReadData<int32>(data, size);
	auto attribute = ReadDictionary(data, size);
	auto children = ReadData<int32>(data, size);
	for (auto i = 0; i < children; ++i) {
		auto child = ReadData<int32>(data, size);
		ngrp->Child.Emplace(MoveTemp(child));
	}
	return ngrp;
}
