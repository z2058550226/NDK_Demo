package com.suikajy.ndk_demo;

import android.util.Base64;
import android.util.Log;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;

/**
 * Created by hui on 2017/6/19.
 */
public class CodeUtil {
    /**
     * 加密的密钥
     */
    public static String KEY = "7C0jQ4M8";

    /**
     * 加密方法
     *
     * @param encryptString 加密的文字
     * @return String 加密后的文字
     * @throws Exception
     */
    public static String Encode(String encryptString) {

        SecretKeySpec key = new SecretKeySpec(KEY.getBytes(), "DES");
        Cipher cipher = null;
        byte[] encryptedData = null;
        try {
            cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
            cipher.init(Cipher.ENCRYPT_MODE, key);
            if (null != encryptString) {
                encryptedData = cipher.doFinal(encryptString.getBytes());
                Log.e("NT",new String(encryptedData));
            } else {
                return "";
            }
        } catch (Exception e) {
            new RuntimeException(" CodeUtil Encode" + e.toString());
            e.printStackTrace();
        }
        return Base64.encodeToString(encryptedData, Base64.NO_WRAP);
        //return Base64.encode(encryptedData);
    }


    /**
     * 解密方法
     *
     * @param decryptString 需要解密的文字
     * @return String 解密后的文字
     * @throws Exception
     */
    public static String Decode(String decryptString) {

        byte[] byteMi = null;
        if (null != decryptString) {
            //byteMi = Base64.decode(decryptString);
            try {
                byteMi = Base64.decode(decryptString, Base64.NO_WRAP);
            } catch (Exception e) {
                return "";
            }
        } else {
            return "";
        }
        //设置加密密钥
        SecretKeySpec key = new SecretKeySpec(KEY.getBytes(), "DES");
        byte[] decryptedData = null;
        try {
            Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
            cipher.init(Cipher.DECRYPT_MODE, key);
            decryptedData = cipher.doFinal(byteMi);
        } catch (Exception e) {
            //new RuntimeException(" CodeUtil Decode"+e.toString());
            //e.printStackTrace();
            return "";
        }
        //对返回的字符串进行截取
        return new String(decryptedData);
    }

    /***
     * encode by base64
     */
    public static String encodeBase64(String input) throws Exception {
        return Base64.encodeToString(input.getBytes(), Base64.DEFAULT);
    }
    /***
     * decode by base64
     */
    public static String decodeBase64(String encodedString) throws Exception {
        return new String(Base64.decode(encodedString, Base64.DEFAULT));
    }

}
