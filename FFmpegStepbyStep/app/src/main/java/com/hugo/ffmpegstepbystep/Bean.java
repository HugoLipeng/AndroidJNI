package com.hugo.ffmpegstepbystep;

import android.util.Log;

public class Bean {
    private static final String TAG = "Bean";
    private int i = 100;

    private int getI() {
        return i;
    }

    public void setI(int i) {
        Log.e(TAG,"有人调用了setI");
        this.i = i;
    }


    public static void printInfo(String msg){
        Log.e(TAG,msg);
    }

}
