/*
 * Transport Type Stub for macOS Mock
 *
 * SoftBus 传输类型定义的 macOS 兼容层
 */

#ifndef STUBS_TRANS_TYPE_H
#define STUBS_TRANS_TYPE_H

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_MAC_LEN 18

typedef enum {
    DATA_TYPE_MESSAGE = 1,
    DATA_TYPE_BYTES,
    DATA_TYPE_FILE,
    DATA_TYPE_RAW_STREAM,
    DATA_TYPE_VIDEO_STREAM,
    DATA_TYPE_AUDIO_STREAM,
    DATA_TYPE_SLICE_STREAM,
    DATA_TYPE_BUTT,
} TransDataType;

typedef struct {
    char *name;
    char *peerName;
    char *peerNetworkId;
    char *pkgName;
    TransDataType dataType;
} SocketInfo;

typedef struct {
    char *name;
    char *networkId;
    char *pkgName;
    TransDataType dataType;
} PeerSocketInfo;

typedef enum {
    SHUTDOWN_REASON_UNKNOWN = 0,
    SHUTDOWN_REASON_LOCAL,
    SHUTDOWN_REASON_PEER,
    SHUTDOWN_REASON_LNN_CHANGED,
    SHUTDOWN_REASON_CONN_CHANGED,
    SHUTDOWN_REASON_TIMEOUT,
    SHUTDOWN_REASON_SEND_FILE_ERR,
    SHUTDOWN_REASON_RECV_FILE_ERR,
    SHUTDOWN_REASON_RECV_DATA_ERR,
    SHUTDOWN_REASON_UNEXPECTED,
    SHUTDOWN_REASON_SERVICE_DIED,
    SHUTDOWN_REASON_LNN_OFFLINE,
    SHUTDOWN_REASON_LINK_DOWN,
} ShutdownReason;

typedef enum {
    QOS_RELIABILITY_NONE = 1,
    QOS_RELIABILITY_FULL,
    QOS_RELIABILITY_HALF,
    QOS_RELIABILITY_BUTT,
} QosTransReliability;

typedef enum {
    QOS_TYPE_MIN_BW = 1,
    QOS_TYPE_MAX_LATENCY,
    QOS_TYPE_MIN_LATENCY,
    QOS_TYPE_MAX_WAIT_TIMEOUT,
    QOS_TYPE_MAX_BUFFER,
    QOS_TYPE_FIRST_PACKAGE,
    QOS_TYPE_MAX_IDLE_TIMEOUT,
    QOS_TYPE_TRANS_RELIABILITY,
    QOS_TYPE_BUTT,
} QosType;

typedef struct {
    QosType qos;
    int32_t value;
} QosTV;

typedef enum {
    FILE_EVENT_SEND_PROCESS = 1,
    FILE_EVENT_SEND_FINISH,
    FILE_EVENT_SEND_ERROR,
    FILE_EVENT_RECV_UPDATE_PATH,
    FILE_EVENT_RECV_START,
    FILE_EVENT_RECV_PROCESS,
    FILE_EVENT_RECV_FINISH,
    FILE_EVENT_RECV_ERROR,
    FILE_EVENT_BUTT,
} FileEventType;

typedef struct {
    FileEventType type;
    const char **files;
    uint32_t fileCnt;
    uint64_t bytesProcessed;
    uint64_t bytesTotal;
    const char *(*UpdateRecvPath)(void);
} FileEvent;

typedef struct {
    int32_t type;
    int64_t value;
} TV;

typedef struct {
    int32_t frameType;
    int64_t timeStamp;
    int32_t seqNum;
    int32_t seqSubNum;
    int32_t level;
    int32_t bitMap;
    int32_t tvCount;
    TV *tvList;
} StreamFrameInfo;

typedef struct {
    char *buf;
    int bufLen;
} StreamData;

#ifdef __cplusplus
}
#endif

#endif // STUBS_TRANS_TYPE_H
