/*
 * Softbus Mock Implementation for macOS
 *
 * OpenHarmony Softbus 软总线 API 的 macOS Mock 实现
 */

#include <cstring>
#include <cstdint>

// NodeBasicInfo 结构体定义（与 softbus_bus_center.h 中的定义一致）
typedef struct {
    char networkId[65];      // 网络ID
    char deviceName[65];     // 设备名称
    uint16_t deviceTypeId;   // 设备类型ID
} NodeBasicInfo;

extern "C" {

/**
 * @brief 获取本地节点设备信息
 * @param pkgName 包名
 * @param info 输出的设备信息
 * @return 成功返回 0，失败返回 -1
 */
int32_t GetLocalNodeDeviceInfo(const char* pkgName, NodeBasicInfo* info)
{
    if (pkgName == nullptr || info == nullptr) {
        return -1;
    }
    
    // Mock 实现：返回模拟的本地设备信息
    strncpy(info->networkId, "mock_network_id_12345", sizeof(info->networkId) - 1);
    info->networkId[sizeof(info->networkId) - 1] = '\0';
    
    strncpy(info->deviceName, "MockMacDevice", sizeof(info->deviceName) - 1);
    info->deviceName[sizeof(info->deviceName) - 1] = '\0';
    
    info->deviceTypeId = 0x08;  // 0x08 通常表示 PC/笔记本
    
    return 0;  // 成功
}

/**
 * @brief 获取所有在线节点信息
 * @param pkgName 包名
 * @param info 输出的节点信息数组
 * @param infoNum 输入输出参数，输入时表示数组大小，输出时表示实际节点数量
 * @return 成功返回 0，失败返回 -1
 */
int32_t GetAllNodeDeviceInfo(const char* pkgName, NodeBasicInfo** info, int32_t* infoNum)
{
    if (pkgName == nullptr || info == nullptr || infoNum == nullptr) {
        return -1;
    }
    
    // Mock 实现：返回空列表（没有其他在线节点）
    *info = nullptr;
    *infoNum = 0;
    
    return 0;  // 成功
}

/**
 * @brief 根据网络ID获取节点设备信息
 * @param pkgName 包名
 * @param networkId 网络ID
 * @param info 输出的设备信息
 * @return 成功返回 0，失败返回 -1
 */
int32_t GetNodeKeyInfo(const char* pkgName, const char* networkId, int key, 
                       uint8_t* info, int32_t infoLen)
{
    if (pkgName == nullptr || networkId == nullptr || info == nullptr) {
        return -1;
    }
    
    // Mock 实现：返回模拟信息
    (void)key;
    (void)infoLen;
    
    return 0;  // 成功
}

/**
 * @brief 加入LNN（Local Network Neighborhood）
 * @param pkgName 包名
 * @param target 目标地址
 * @return 成功返回 0，失败返回 -1
 */
int32_t JoinLNN(const char* pkgName, const char* target)
{
    if (pkgName == nullptr || target == nullptr) {
        return -1;
    }
    
    // Mock 实现：总是返回成功
    return 0;
}

/**
 * @brief 离开LNN
 * @param pkgName 包名
 * @param networkId 网络ID
 * @return 成功返回 0，失败返回 -1
 */
int32_t LeaveLNN(const char* pkgName, const char* networkId)
{
    if (pkgName == nullptr || networkId == nullptr) {
        return -1;
    }
    
    // Mock 实现：总是返回成功
    return 0;
}

} // extern "C"
