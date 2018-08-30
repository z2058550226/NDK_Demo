//
// Created by 20585 on 2018/8/25.
// The program's common header.
//

#ifndef NDK_DEMO_PCH_H
#define NDK_DEMO_PCH_H

#include <string>
#include <iostream>
#include <jni.h>
#include <android/log.h>
#include <stdarg.h>

#define SUIKA_TAG "SuikaJYJNITag"

using namespace std;

void log_e(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    __android_log_vprint(ANDROID_LOG_ERROR, SUIKA_TAG, fmt, ap);
    va_end(ap);
}

#endif //NDK_DEMO_PCH_H
