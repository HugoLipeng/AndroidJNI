package com.hugo.ffmpegstepbystep;

import androidx.appcompat.app.AppCompatActivity;

import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //去掉标题栏
        supportRequestWindowFeature( Window.FEATURE_NO_TITLE);
        //全屏，隐藏状态
        getWindow().setFlags( WindowManager.LayoutParams.FLAG_FULLSCREEN ,
                WindowManager.LayoutParams.FLAG_FULLSCREEN
        );
        //屏幕为横屏
        setRequestedOrientation( ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE );

        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        String str = "/sdcard/1080.mp4";
        //Open( str,this );
        //tv.setText( stringFromJNI() );

        // 1、传递数组
//        int i[] = {11,22,33,44};
//        String j[] = {"hello","world"};
//        test(i,j);
//        Log.e("Java","int数组："+ Arrays.toString(i));
        //  2、传递引用类型
//        Bean bean = new Bean();
//        passObject(bean,"hugo");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    native int test(int[] i,String[] j);
    //传递java class 给native使用
    native void passObject(Bean bean,String str);
    public native boolean Open(String url,Object handle);
}
