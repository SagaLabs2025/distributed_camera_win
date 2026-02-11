/*
 * IFeedableData Stub for macOS Mock
 *
 * OpenHarmony 可馈送数据接口的 macOS 兼容层
 */

#ifndef STUBS_IFEEDABLE_DATA_H
#define STUBS_IFEEDABLE_DATA_H

#include <cstdint>
#include <vector>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

/**
 * @brief 可馈送数据接口
 * 数据接收者可以通过此接口获取数据
 */
class IFeedableData {
public:
    virtual ~IFeedableData() = default;

    /**
     * @brief 馈送数据
     * @param data 数据指针
     * @param size 数据大小
     * @return 成功返回 true
     */
    virtual bool FeedData(const void* data, uint32_t size)
    {
        (void)data; (void)size;
        return true;  // Mock: 总是成功
    }

    /**
     * @brief 馈送数据（向量版本）
     * @param data 数据向量
     * @return 成功返回 true
     */
    virtual bool FeedData(const std::vector<uint8_t>& data)
    {
        (void)data;
        return true;  // Mock: 总是成功
    }

    /**
     * @brief 获取时间戳
     * @return 时间戳值
     */
    virtual int64_t GetTimeStamp()
    {
        return 0;  // Mock: 返回 0
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IFEEDABLE_DATA_H
