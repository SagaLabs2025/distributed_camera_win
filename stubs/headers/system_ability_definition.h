/*
 * System Ability Definition - OpenHarmony SA Framework - macOS Mock
 *
 * 系统能力框架定义的 macOS 空实现
 */

#ifndef STUBS_SYSTEM_ABILITY_DEFINITION_H
#define STUBS_SYSTEM_ABILITY_DEFINITION_H

#include <memory>
#include <string>

namespace OHOS {
namespace DistributedHardware {

/**
 * @brief 系统能力状态枚举
 */
enum class SystemAbilityState {
    IDLE,           // 空闲
    ACTIVATING,     // 激活中
    ACTIVE,         // 已激活
    DEACTIVATING    // 停用中
};

/**
 * @brief 系统能力基类
 */
class SystemAbility {
public:
    explicit SystemAbility(int32_t saId, bool runOnCreate = false)
        : systemAbilityId_(saId), runOnCreate_(runOnCreate) {}
    virtual ~SystemAbility() = default;

    /**
     * @brief 发布系统能力
     */
    virtual bool Publish(std::shared_ptr<SystemAbility>& ability) {
        (void)ability;
        return true;  // Mock: 返回成功
    }

    /**
     * @brief 卸载系统能力
     */
    virtual int32_t UnloadSystemAbility(int32_t saId) {
        (void)saId;
        return 0;  // Mock: 返回成功
    }

    /**
     * @brief 获取系统能力ID
     */
    int32_t GetSystemAbilityId() const { return systemAbilityId_; }

    /**
     * @brief 是否在创建时运行
     */
    bool GetRunOnCreate() const { return runOnCreate_; }

protected:
    int32_t systemAbilityId_;
    bool runOnCreate_;
};

/**
 * @brief 系统能力管理器客户端
 */
class SystemAbilityManagerClient {
public:
    /**
     * @brief 获取单例实例
     */
    static SystemAbilityManagerClient& GetInstance() {
        static SystemAbilityManagerClient instance;
        return instance;
    }

    /**
     * @brief 获取系统能力管理器
     */
    std::shared_ptr<void> GetSystemAbilityManager() {
        return nullptr;  // Mock: 返回空指针
    }

private:
    SystemAbilityManagerClient() = default;
    ~SystemAbilityManagerClient() = default;
};

/**
 * @brief 注册系统能力宏
 */
#define REGISTER_SYSTEM_ABILITY_BY_ID(className, saId, runOnCreate) \
    int32_t GetSystemAbilityId() const { return saId; }

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_SYSTEM_ABILITY_DEFINITION_H
