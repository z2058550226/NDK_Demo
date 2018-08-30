package com.suikajy.ndk_demo;

public class JavaClass {

    static {
        System.loadLibrary("native-lib");
    }

    private String instanceField = "Instance Field";

    private static String staticField = "Static Field";

    private String instanceMethod() {
        return "Instance Method";
    }

    private static String staticMethod() {
        return "Static Method";
    }

    /**
     * Throwing method.
     */
    private void throwingMethod() throws NullPointerException {
        throw new NullPointerException("Null pointer");
    }

    /**
     * Access methods native method.
     */
    private native void accessMethods();
}
