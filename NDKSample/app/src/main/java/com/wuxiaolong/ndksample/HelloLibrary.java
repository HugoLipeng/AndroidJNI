package com.wuxiaolong.ndksample;

/**
 * Created by WuXiaolong on 2017/12/27.
 * 个人博客：http：//wuxiaolong.me
 */

public class HelloLibrary {
    static {
        //加载动态库，这里对应 Android.mk 里的 LOCAL_MODULE := NDKSample
        System.loadLibrary("NDKSample");
    }

    //使用 native 关键字指示以原生代码形式实现的方法
    public native String sayHello();


}
