#pragma once

#include "Engine/Scripting/Script.h"

API_CLASS() class DLSS_API FSRBackend : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(FSRBackend);

    // [Script]
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;
};
