// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Node/Group.h"

FVoxNodeGroup* FVoxNodeGroup::Read(const void*& data, size_t& size)
{
	auto* ngrp = new FVoxNodeGroup();
	auto id = ReadData<uint32_t>(data, size);
	if (FVoxNodeGroup::Tag != id) return ngrp;

	ngrp->Content = ReadData<int32_t>(data, size);
	ngrp->Children = ReadData<int32_t>(data, size);
	ngrp->Id = ReadData<int32_t>(data, size);
	auto attribute = ReadDictionary(data, size);
	auto children = ReadData<int32_t>(data, size);
	for (auto i = 0; i < children; ++i) {
		auto child = ReadData<int32_t>(data, size);
		ngrp->Child.push_back(child);
	}
	return ngrp;
}
