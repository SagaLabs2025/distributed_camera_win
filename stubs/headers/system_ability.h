/*
 * SystemAbility Stub for macOS Mock
 *
 * OpenHarmony 系统能力基类的 macOS 兼容层
 */

#ifndef STUBS_SYSTEM_ABILITY_H
#define STUBS_SYSTEM_ABILITY_H

#include <string>
#include <cstdint>
#include <memory>
#include <vector>

#ifdef __cplusplus
namespace OHOS {

// 前向声明
class MessageParcel;
class MessageOption;

/**
 * @brief 系统能力基类
 * 所有 System Ability 的基类
 */
class SystemAbility {
public:
    /**
     * @brief 构造函数
     * @param saId 系统能力 ID
     * @param runOnCreate 是否在创建时运行
     */
    SystemAbility(int32_t saId, bool runOnCreate)
        : saId_(saId), runOnCreate_(runOnCreate)
    {
    }

    virtual ~SystemAbility() = default;

    /**
     * @brief 启动系统能力
     */
    virtual void OnStart()
    {
        // Mock: 空实现
    }

    /**
     * @brief 停止系统能力
     */
    virtual void OnStop()
    {
        // Mock: 空实现
    }

    /**
     * @brief 发布系统能力到 SAMgr
     * @param ability 系统能力指针
     * @return 成功返回 true
     */
    static bool Publish(SystemAbility* ability)
    {
        (void)ability;
        return true;  // Mock: 总是发布成功
    }

    /**
     * @brief Dump 系统能力信息
     * @param fd 文件描述符
     * @param args 参数列表
     * @return 成功返回 0
     */
    virtual int32_t Dump(int32_t fd, const std::vector<std::u16string>& args)
    {
        (void)fd; (void)args;
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 获取 SA ID
     * @return SA ID
     */
    int32_t GetSystemAbilityId() const
    {
        return saId_;
    }

protected:
    int32_t saId_;
    bool runOnCreate_;
};

/**
 * @brief 系统能力注册宏（简化版本）
 * 只声明构造函数，不定义
 */
#define DECLARE_SYSTEM_ABILITY(ClassName) \
public: \
    ClassName(int32_t saId, bool runOnCreate);

#define REGISTER_SYSTEM_ABILITY_BY_ID(ClassName, SaId, RunOnCreate)

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_SYSTEM_ABILITY_H
