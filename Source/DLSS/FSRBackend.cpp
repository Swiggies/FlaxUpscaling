#include "FSRBackend.h"
#include <ffx_fsr2.h>
#if GRAPHICS_API_DIRECTX12
#include <dx12/ffx_fsr2_dx12.h>
#endif
#include "Engine/Graphics/RenderTask.h"
#include "Engine/Graphics/GPUDevice.h"
#include "Engine/Graphics/GPUContext.h"
#include "Engine/Core/Log.h"

FSRBackend::FSRBackend(const SpawnParams& params)
    : Script(params)
{
    // Enable ticking OnUpdate function
    _tickUpdate = true;
}

FfxFsr2Interface* fsr2Interface;
FfxErrorCode result;

void FSRBackend::OnEnable()
{
    LOG(Warning, "{0}", (int32)GPUDevice::Instance->GetRendererType());
#if GRAPHICS_API_DIRECTX12
    LOG(Error, "Launched with DirectX 12.");
    // Here you can add code that needs to be called when script is enabled (eg. register for events)
    ID3D12Device* gpuDevice = (ID3D12Device*)GPUDevice::Instance->GetNativePtr();
    size_t scratchMemorySize = ffxFsr2GetScratchMemorySizeDX12();
    void* scratchBuffer;
    result = ffxFsr2GetInterfaceDX12(fsr2Interface, gpuDevice, scratchBuffer, scratchMemorySize);

    if (result == FFX_OK) {

    }
    else if (result == FFX_ERROR_INVALID_POINTER) {
        LOG_STR(Error, TEXT("Invalid Pointer."));
    }
#endif
}

void FSRBackend::OnDisable()
{
    // Here you can add code that needs to be called when script is disabled (eg. unregister from events)
}

void FSRBackend::OnUpdate()
{
    // Here you can add code that needs to be called every frame
}
