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

extern "C"
JNIEXPORT void JNICALL
Java_com_suikajy_ndk_1demo_JavaClass_accessMethods(JNIEnv *env, jobject instance) {

    // TODO
    log_e("调用accessMethods");

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_suikajy_ndk_1demo_JNI_nativeEncode(JNIEnv *env, jclass type, jstring oriString_) {
    const char *oriString = env->GetStringUTFChars(oriString_, 0);

    const char *KEY = "7C0jQ4M8";
    const char *result;

    DES *des = new DES();
    Base64 *base64 = new Base64();

    const char *desResult = des->Encrypt(string(oriString), KEY).c_str();

    log_e("desResult : %s",desResult);

    int len = static_cast<int>(strlen(desResult));
    string base64Result = base64->Encode(reinterpret_cast<const unsigned char *>(desResult), len);

    log_e("base64Result : %s",base64Result.c_str());
    result = base64Result.c_str();

    delete des;
    delete base64;

    env->ReleaseStringUTFChars(oriString_, oriString);

    return env->NewStringUTF(result);
}