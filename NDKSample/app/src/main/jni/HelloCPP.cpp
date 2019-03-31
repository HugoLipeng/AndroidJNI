//
// Created by WuXiaolong on 2017/12/26.
//

#include <jni.h>

extern "C"

JNIEXPORT jstring JNICALL Java_com_wuxiaolong_ndksample_HelloLibrary_sayHello(JNIEnv *env, jobject instance) {
    //从 C++ 传字符串到 Java
    return env->NewStringUTF("Hello from C++");
}
