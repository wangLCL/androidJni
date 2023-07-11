//
// Created by Administrator on 2023/7/11.
//
#include <android/log.h>
#ifndef OPGLNDK_JNILOG_H
#define OPGLNDK_JNILOG_H

#define LOG_TAG "libESV2jni"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__);

#endif //OPGLNDK_JNILOG_H
