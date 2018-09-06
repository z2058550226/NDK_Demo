package com.suikajy.ndk_demo;

public class JNI {

    static {
        System.loadLibrary("native-lib");
    }

    public static native String sayHello();

    // 字符串转换API Demo
    public static native String outPutTest(String input);

    // 数组转换API Demo
    public static native String nativeEncode(String oriString);

    public static native void posixThread(int a, int b);

}
