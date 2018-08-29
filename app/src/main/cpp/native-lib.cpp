#include "PCH.h"
#include "ch3/type_convert.h"

//测试环境用
extern "C"
JNIEXPORT jstring JNICALL
Java_com_suikajy_ndk_1demo_JNI_sayHello(JNIEnv *env, jclass type) {
    return env->NewStringUTF("Hello Suikajy");
}

// 字符串转化操作
extern "C"
JNIEXPORT jstring JNICALL
Java_com_suikajy_ndk_1demo_JNI_outPutTest(JNIEnv *env, jclass type, jstring input_) {
    return jstring2cstring(env, input_);
}

// 数组转化操作
extern "C"
JNIEXPORT jintArray JNICALL
Java_com_suikajy_ndk_1demo_JNI_nativeEncode(JNIEnv *env, jclass type, jintArray array_) {
    jint *array = env->GetIntArrayElements(array_, NULL);

    env->ReleaseIntArrayElements(array_, array, 0);
    jintArray javaArray;
}