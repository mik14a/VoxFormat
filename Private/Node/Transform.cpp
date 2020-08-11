// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "Node/Transform.h"

FVoxNodeTransform* FVoxNodeTransform::Read(const void*& data, int64& size)
{
	auto* ntrn = new FVoxNodeTransform();
	auto id = ReadData<uint32>(data, size);
	if (FVoxNodeTransform::Tag != id) return ntrn;

	ntrn->Content = ReadData<int32>(data, size);
	ntrn->Children = ReadData<int32>(data, size);
	ntrn->Id = ReadData<int32>(data, size);
	auto attribute = ReadDictionary(data, size);
	auto name = attribute.Find("_name");
	ntrn->Name = name ? *name : FString();
	auto hidden = attribute.Find("_hidden");
	ntrn->Hidden = hidden ? FCString::ToBool(**hidden) : false;
	ntrn->Child = ReadData<int32>(data, size);
	ReadData<int32>(data, size);  // reserved
	ntrn->Layer = ReadData<int32>(data, size);
	auto frames = ReadData<int32>(data, size);
	for (auto f = 0; f < frames; ++f) {
		auto dictionary = ReadDictionary(data, size);
		auto frame = FrameT::ElementType();
		auto r = dictionary.Find("_r");
		if (r != nullptr) {
			const auto m = FCString::Atoi(**r);
			const auto first = static_cast<int>((m >> 0) & 0x03);
			const auto second = static_cast<int>((m >> 2) & 0x03);
			const auto third = 0x03 ^ (first | second);
			const int sign[] = {
				static_cast<int>((m >> 4) & 0x01),
				static_cast<int>((m >> 5) & 0x01),
				static_cast<int>((m >> 6) & 0x01),
			};
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					frame.Rotation.M[i][j] = 0;
				}
			}
			frame.Rotation.M[0][first] = sign[0] ? -1 : 1;
			frame.Rotation.M[1][second] = sign[1] ? -1 : 1;
			frame.Rotation.M[2][third] = sign[2] ? -1 : 1;
		}
		auto t = dictionary.Find("_t");
		if (t != nullptr) {
			auto x = **t;
			frame.Translation.X = FCString::Atoi(x);
			auto y = FCString::Strchr(x, TEXT(' ')) + 1;
			frame.Translation.Y = FCString::Atoi(y);
			auto z = FCString::Strchr(y, TEXT(' ')) + 1;
			frame.Translation.Z = FCString::Atoi(z);
		}
		ntrn->Frame.Emplace(MoveTemp(frame));
	}
	return ntrn;
}
