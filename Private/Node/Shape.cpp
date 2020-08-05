// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Node/Shape.h"

FVoxNodeShape* FVoxNodeShape::Read(const void*& data, size_t& size)
{
	auto* nshp = new FVoxNodeShape();
	auto id = ReadData<uint32_t>(data, size);
	if (FVoxNodeShape::Tag != id) return nshp;

	nshp->Content = ReadData<int32_t>(data, size);
	nshp->Children = ReadData<int32_t>(data, size);
	nshp->Id = ReadData<int32_t>(data, size);
	auto attribute = ReadDictionary(data, size);
	auto models = ReadData<int32_t>(data, size);
	for (auto i = 0; i < models; ++i) {
		auto model = model_t::value_type();
		model.Id = ReadData<int32_t>(data, size);
		model.Attributes = ReadDictionary(data, size);
		nshp->Model.push_back(std::move(model));
	}
	return nshp;
}
