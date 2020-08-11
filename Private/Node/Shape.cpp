// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Node/Shape.h"

FVoxNodeShape* FVoxNodeShape::Read(const void*& data, int64& size)
{
	auto* nshp = new FVoxNodeShape();
	auto id = ReadData<uint32>(data, size);
	if (FVoxNodeShape::Tag != id) return nshp;

	nshp->Content = ReadData<int32>(data, size);
	nshp->Children = ReadData<int32>(data, size);
	nshp->Id = ReadData<int32>(data, size);
	auto attribute = ReadDictionary(data, size);
	auto models = ReadData<int32>(data, size);
	for (auto i = 0; i < models; ++i) {
		auto model = ModelT::ElementType();
		model.Id = ReadData<int32>(data, size);
		model.Attributes = ReadDictionary(data, size);
		nshp->Model.Emplace(MoveTemp(model));
	}
	return nshp;
}
