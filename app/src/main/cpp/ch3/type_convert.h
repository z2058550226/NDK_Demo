//
// Created by 20585 on 2018/8/28.
//

#ifndef NDK_DEMO_TYPECONVERT_H
#define NDK_DEMO_TYPECONVERT_H

#include "../PCH.h"

// java字符串转C字符串
jstring jstring2cstring(JNIEnv *env, jstring javaString) {
    // c风格字符串定义，这里其实也可以写成const jbyte *str; 因为jbyte和char是等价的。
    const char *c_str;
    jboolean isCopy;

    // GetStringUTFChars的作用是将java字符串转换为c的字符串
    // 第一个参数是java的jni字符串对象。
    // 第二个参数是一个以引用方式传递(pass-by-reference)的jboolean对象，它的作用是用来
    // 通知调用者，这个返回的C字符串是一个clone of the jstring还是java虚拟机中固有的字符串对象
    c_str = env->GetStringUTFChars(javaString, &isCopy);

    // 打印测试日志
    string result(c_str);
    __android_log_print(ANDROID_LOG_ERROR, SUIKA_TAG, "The jstring2cstring return is: %s",
                        result.c_str());

    // 用完一定要释放堆空间。
    env->ReleaseStringUTFChars(javaString, c_str);
    if (isCopy) {
        // 小米6 Android 8.0上isCopy为true
        return env->NewStringUTF("C字符串是java字符串的一个内存拷贝");
    } else {
        return env->NewStringUTF("C字符串指针指向真实的java字符串内存");
    }
}

// new一个java数组。
jintArray newArray(JNIEnv *env, int arrayLength) {
    jintArray javaArray;
    javaArray = env->NewIntArray(arrayLength);
    if (javaArray != 0) { // 如果内存溢出就会返回0
        return javaArray;
    } else {
        return NULL;
    }
}

// 获取java数组的C拷贝，经过操作后再设置回javaArray
// 这种方式如果数组过大拷贝一个数组就会产生效率问题
void cloneJavaArray(JNIEnv *env, jintArray javaArray, int arrayLength) {
    jint c_array[arrayLength];
    env->GetIntArrayRegion(javaArray, 0, arrayLength, c_array);

    for (int i = 0; i < arrayLength; i++) {
        c_array[i]++;
    }

    env->SetIntArrayRegion(javaArray, 0, arrayLength, c_array);
}

// 获取java数组直接引用
void getJavaArrayDirectPointer(JNIEnv *env, jintArray javaArray) {
    jint *nativeDirectArray;
    jboolean isCopy;// 不关注是否是拷贝内存还是java直接内存时这个参数可以直接传0

    nativeDirectArray = env->GetIntArrayElements(javaArray, &isCopy);
    if (isCopy) {
        log_e("直接指针指向C数组拷贝");
    } else {
        log_e("直接指针指向Java堆空间");
    }

    env->ReleaseIntArrayElements(javaArray, nativeDirectArray, 0);//将C数组内容复制到java数组，释放本地数组内存。
}


#endif //NDK_DEMO_TYPECONVERT_H
