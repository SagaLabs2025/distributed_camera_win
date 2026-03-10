/*
 * DCamera Source DLL Entry Point - macOS Mock
 *
 * 分布式相机源端动态库入口点（仅用于本地测试环境）
 */

#include "distributed_hardware_log.h"

__attribute__((constructor)) static void DCameraSourceLibraryInit()
{
    DHLOGI("libdcamera_source loaded");
}
