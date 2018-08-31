package com.suikajy.ndk_demo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.GridView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tvOutPut = findViewById(R.id.tv_output);
        tvOutPut.setText(JNI.outPutTest("这是java端输入suika"));
        TextView tvOutPut1 = findViewById(R.id.tv_output1);
        TextView tvOutPut2 = findViewById(R.id.tv_output2);
        String oriString = "这是一个测试的字符串aldkjfaln192haksd哈哈哈";
        tvOutPut1.setText(CodeUtil.Encode(oriString));
        String jniEncode = JNI.nativeEncode(oriString);
        Log.e("NT","java端接收："+jniEncode);
        Log.e("NT","java端解密："+CodeUtil.Decode(jniEncode));
        tvOutPut2.setText(jniEncode);
    }
}
