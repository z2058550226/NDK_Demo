package com.suikajy.ndk_demo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.GridView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tvOutPut = findViewById(R.id.tv_output);
        tvOutPut.setText(JNI.outPutTest("这是java端输入suika"));
    }
}
