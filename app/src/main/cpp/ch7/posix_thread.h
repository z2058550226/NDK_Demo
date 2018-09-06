//
// Created by suikajy on 2018/9/3.
//

#ifndef NDK_DEMO_POSIX_THREAD_H
#define NDK_DEMO_POSIX_THREAD_H

#include <stdio.h>
#include <unistd.h>

#include <pthread.h>

#include "../PCH.h"

// Native worker thread arguments
struct NativeWorkerArgs
{
    jint id;
    jint iterations;
};

// Method ID can be cached
static jmethodID gOnNativeMessage = NULL;
// Java VM interface pointer
static JavaVM* gVm = NULL;
// Global reference to object
static jobject gObj = NULL;

jint JNI_OnLoad (JavaVM* vm, void* reserved)
{
// Cache the JavaVM interface pointer
    gVm = vm;
    return JNI_VERSION_1_4;
}

#endif //NDK_DEMO_POSIX_THREAD_H
