// Copyright 2018-2020 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Vox.h"

/**
 * @brief Read vox format
 * @param data Source data address
 * @param size Size of data
 * @return Vox format data
*/
VOXFORMAT_API FVox ReadVox(const void* data, size_t size);

class FVoxFormatModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;
};
