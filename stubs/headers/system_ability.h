/*
 * System Ability - OpenHarmony SA Framework - macOS Mock
 *
 * 系统能力框架的 macOS 空实现
 */

#ifndef STUBS_SYSTEM_ABILITY_H
#define STUBS_SYSTEM_ABILITY_H

// DECLARE_SYSTEM_ABILITY 宏定义 - macOS Mock（空实现）
// 注意：只添加 SA ID 和类型标记，不添加构造/析构函数声明
#ifndef DECLARE_SYSTEM_ABILITY

#define DECLARE_SYSTEM_ABILITY(className)                         \
public:                                                         \
    static constexpr int32_t SYSTEM_ABILITY_ID = 0;             \
    static bool IsSystemAbility() { return false; }             \
    int32_t GetSystemAbilityId() const { return 0; }            \

#endif // DECLARE_SYSTEM_ABILITY

// 空实现宏 - 用于需要 SA 框架但不实际使用的情况
#define DECLARE_EMPTY_SYSTEM_ABILITY(className) \
    DECLARE_SYSTEM_ABILITY(className)

#endif // STUBS_SYSTEM_ABILITY_H
