// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#include "VoxFormat.h"

#define LOCTEXT_NAMESPACE "FVoxFormatModule"

FVox ReadVox(const void* data, int64 size)
{
	auto id = ReadData<uint32>(data, size);
	if (FVox::Tag == id) {
		auto version = ReadData<int32>(data, size);
		if (150 == version) {
			return FVox::Read(data, size);
		}
	}
	return FVox();
}

void FVoxFormatModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FVoxFormatModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVoxFormatModule, VoxFormat)
