/*
 * IServiceManager HDI Stub for macOS Mock
 *
 * OpenHarmony 系统能力管理器 HDI 接口的 macOS 兼容层
 */

#ifndef STUBS_ISERVMGR_HDI_H
#define STUBS_ISERVMGR_HDI_H

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

struct HdiServiceSet {
    const char **serviceNames;
    uint32_t count;
};

struct ServiceStatusListener;
struct HDIServiceManager;

typedef struct HdiServiceSet* (*GetService)(struct HDIServiceManager *self, const char *serviceName);

struct HDIServiceManager {
    GetService GetService;
    int32_t (*RegisterServiceStatusListener)(
        struct HDIServiceManager *self,
        struct ServiceStatusListener *listener,
        uint16_t deviceClass);
};

#ifdef __cplusplus
}
#endif

#endif // STUBS_ISERVMGR_HDI_H
