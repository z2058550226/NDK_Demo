#include "PCH.h"
#include "ch3/type_convert.h"
#include "ch7/posix_thread.h"

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
//    char* buffer;
//    size_t i;
//    buffer = (char*) malloc(1024);
//    for (i = 0; i < 1025; i++)
//    {
//        buffer[i] = 'a';
//    }
//    free(buffer);
//    return env->NewStringUTF("Hello Suikajy");
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

    log_e("desResult : %s", desResult);

    int len = static_cast<int>(strlen(desResult));
    string base64Result = base64->Encode(reinterpret_cast<const unsigned char *>(desResult), len);

    log_e("base64Result : %s", base64Result.c_str());
    result = base64Result.c_str();

    delete des;
    delete base64;

    env->ReleaseStringUTFChars(oriString_, oriString);

    return env->NewStringUTF(result);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_suikajy_ndk_1demo_JNI_posixThread(JNIEnv *env, jclass type, jint a, jint b) {

    // TODO

}

//void Java_com_apress_threads_MainActivity_posixThreads(
//        JNIEnv *env,
//        jobject obj,
//        jint threads,
//        jint iterations) {
//    // Thread handles
//    pthread_t *handles = new pthread_t[threads];
//    // Create a POSIX thread for each worker
//    for (jint i = 0; i < threads; i++) {
//        // Native worker thread arguments
//        NativeWorkerArgs *nativeWorkerArgs = new NativeWorkerArgs();
//        nativeWorkerArgs->id = i;
//        nativeWorkerArgs->iterations = iterations;
//        // Create a new thread
//        int result = pthread_create(
//                &handles[i],
//                NULL,
//                nativeWorkerThread,
//                (void *) nativeWorkerArgs);
//        if (0 != result) {
//            // Get the exception class
//            jclass exceptionClazz = env->FindClass(
//                    "java/lang/RuntimeException");
//            // Throw exception
//            env->ThrowNew(exceptionClazz, "Unable to create thread");
//            goto exit;
//        }
//    }
//    // Wait for threads to terminate
//    for (jint i = 0; i < threads; i++) {
//        void *result = NULL;
//        // Join each thread handle
//        if (0 != pthread_join(handles[i], &result)) {
//            // Get the exception class
//            jclass exceptionClazz = env->FindClass(
//                    "java/lang/RuntimeException");
//            // Throw exception
//            env->ThrowNew(exceptionClazz, "Unable to join thread");
//        } else {
//            // Prepare message
//            char message[26];
//            sprintf(message, "Worker %d returned %d", i, result);
//            // Message from the C string
//            jstring messageString = env->NewStringUTF(message);
//            // Call the on native message method
//            env->CallVoidMethod(obj, gOnNativeMessage, messageString);
//            // Check if an exception occurred
//            if (NULL != env->ExceptionOccurred()) {
//                goto exit;
//            }
//        }
//    }
//    exit:
//    return;
//}