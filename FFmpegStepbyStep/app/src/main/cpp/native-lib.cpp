#include <jni.h>
#include <string>
#include <android/log.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,"testff",__VA_ARGS__)
//  __VA_ARGS__ 代表... 可变参数
#define  LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"JNI",__VA_ARGS__);
#define LOGD(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR,"TestOpenSL",FORMAT,##__VA_ARGS__);

extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavcodec/jni.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
}
#include<iostream>
using namespace std;

static double r2d(AVRational r)
{
    return r.num==0||r.den == 0 ? 0 :(double)r.num/(double)r.den;
}

//当前时间戳 clock
long long GetNowMs()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    int sec = tv.tv_sec%360000;
    long long t = sec*1000+tv.tv_usec/1000;
    return t;
}

extern "C"
JNIEXPORT
jint JNI_OnLoad(JavaVM *vm,void *res)
{
    av_jni_set_java_vm(vm,0);
    return JNI_VERSION_1_4;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_hugo_ffmpegstepbystep_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    hello += avcodec_configuration();
    return env->NewStringUTF(hello.c_str());
}




extern "C"
JNIEXPORT jboolean JNICALL
Java_com_hugo_ffmpegstepbystep_MainActivity_Open(JNIEnv *env, jobject instance, jstring url_,
                                                 jobject handle) {
    const char *url = env->GetStringUTFChars(url_, 0);

    // TODO
    FILE *fp = fopen(url,"rb");
    if(!fp)
    {
        LOGW("File %s open failed!",url);
    }
    else
    {
        LOGW("File %s open succes!",url);
        fclose(fp);
    }

    env->ReleaseStringUTFChars(url_, url);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hugo_ffmpegstepbystep_XPlay_Open(JNIEnv *env, jobject instance, jstring url_,
                                          jobject surface) {
    const char *path = env->GetStringUTFChars(url_, 0);

    // TODO
    //初始化解封装
    av_register_all();
    //初始化网络
    avformat_network_init();

    //打开文件
    AVFormatContext *ic = NULL;
//    char path[] = "/sdcard/1080.mp4";
    //char path[] = "/sdcard/video.flv";
    int re = avformat_open_input(&ic,path,0,0);
    if(re != 0)
    {
        LOGW("avformat_open_input failed!:%s",av_err2str(re));
        return;
    }
    LOGW("avformat_open_input %s success!",path);
    //获取流信息
    re = avformat_find_stream_info(ic,0);
    if(re != 0)
    {
        LOGW("avformat_find_stream_info failed!");
    }
    LOGW("duration = %lld nb_streams = %d",ic->duration,ic->nb_streams);

    int fps = 0;
    int videoStream = 0;
    int audioStream = 1;

    for(int i = 0; i < ic->nb_streams; i++)
    {
        AVStream *as = ic->streams[i];
        if(as->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            LOGW("视频数据");
            videoStream = i;
            fps = r2d(as->avg_frame_rate);

            LOGW("fps = %d,width=%d height=%d codeid=%d pixformat=%d",fps,
                 as->codecpar->width,
                 as->codecpar->height,
                 as->codecpar->codec_id,
                 as->codecpar->format
            );
        }
        else if(as->codecpar->codec_type ==AVMEDIA_TYPE_AUDIO )
        {
            LOGW("音频数据");
            audioStream = i;
            LOGW("sample_rate=%d channels=%d sample_format=%d",
                 as->codecpar->sample_rate,
                 as->codecpar->channels,
                 as->codecpar->format
            );
        }
    }
    //ic->streams[videoStream];
    //获取音频流信息
    audioStream = av_find_best_stream(ic,AVMEDIA_TYPE_AUDIO,-1,-1,NULL,0);
    LOGW("av_find_best_stream audioStream = %d",audioStream);

    //////////////////////////////////////////////////////////
    //打开视频解码器
    //软解码器
    AVCodec *codec = avcodec_find_decoder(ic->streams[videoStream]->codecpar->codec_id);
    //硬解码
    codec = avcodec_find_decoder_by_name("h264_mediacodec");
    if(!codec)
    {
        LOGW("avcodec_find failed!");
        return;
    }
    //解码器初始化
    AVCodecContext *vc = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(vc,ic->streams[videoStream]->codecpar);

    vc->thread_count = 8;
    //打开解码器
    re = avcodec_open2(vc,0,0);
    //vc->time_base = ic->streams[videoStream]->time_base;
    LOGW("vc timebase = %d/ %d",vc->time_base.num,vc->time_base.den);
    if(re != 0)
    {
        LOGW("avcodec_open2 video failed!");
        return;
    }

    //////////////////////////////////////////////////////////
    //打开音频解码器
    //软解码器
    AVCodec *acodec = avcodec_find_decoder(ic->streams[audioStream]->codecpar->codec_id);
    //硬解码
    //codec = avcodec_find_decoder_by_name("h264_mediacodec");
    if(!acodec)
    {
        LOGW("avcodec_find failed!");
        return;
    }
    //解码器初始化
    AVCodecContext *ac = avcodec_alloc_context3(acodec);
    avcodec_parameters_to_context(ac,ic->streams[audioStream]->codecpar);
    ac->thread_count = 8;
    //打开解码器
    re = avcodec_open2(ac,0,0);
    if(re != 0)
    {
        LOGW("avcodec_open2  audio failed!");
        return;
    }
    //读取帧数据
    AVPacket *pkt = av_packet_alloc();
    AVFrame *frame = av_frame_alloc();
    long long start = GetNowMs();
    int frameCount = 0;

    //初始化像素格式转换的上下文
    SwsContext *vctx = NULL;
    int outWidth = 1280;
    int outHeight = 720;
    char *rgb = new char[1920*1080*4];
    char *pcm = new char[48000*4*2];

    //音频重采样上下文初始化
    SwrContext *actx = swr_alloc();
    actx = swr_alloc_set_opts(actx,
                              av_get_default_channel_layout(2),
                              AV_SAMPLE_FMT_S16,ac->sample_rate,
                              av_get_default_channel_layout(ac->channels),
                              ac->sample_fmt,ac->sample_rate,
                              0,0 );
    re = swr_init(actx);
    if(re != 0)
    {
        LOGW("swr_init failed!");
    }
    else
    {
        LOGW("swr_init success!");
    }

    //显示窗口初始化
    ANativeWindow *nwin = ANativeWindow_fromSurface(env,surface);
    ANativeWindow_setBuffersGeometry(nwin,outWidth,outHeight,WINDOW_FORMAT_RGBA_8888);
    ANativeWindow_Buffer wbuf;


    for(;;)
    {
        //超过三秒
        if(GetNowMs() - start >= 3000)
        {
            LOGW("now decode fps is %d",frameCount/3);
            start = GetNowMs();
            frameCount = 0;
        }

        int re = av_read_frame(ic,pkt);
        if(re != 0)
        {

            LOGW("读取到结尾处!");
            int pos = 20 * r2d(ic->streams[videoStream]->time_base);
            av_seek_frame(ic,videoStream,pos,AVSEEK_FLAG_BACKWARD|AVSEEK_FLAG_FRAME );
            continue;
        }
        //只测试视频
        /*if(pkt->stream_index !=videoStream)
        {
            continue;
        }*/
        //LOGW("stream = %d size =%d pts=%lld flag=%d",
        //     pkt->stream_index,pkt->size,pkt->pts,pkt->flags
        //);

        AVCodecContext *cc = vc;
        if(pkt->stream_index == audioStream)
            cc=ac;

        //发送到线程中解码
        re = avcodec_send_packet(cc,pkt);
        //清理
        int p = pkt->pts;
        av_packet_unref(pkt);

        if(re != 0)
        {
            LOGW("avcodec_send_packet failed!");
            continue;
        }
        for(;;)
        {
            re = avcodec_receive_frame(cc,frame);
            if(re !=0)
            {
                //LOGW("avcodec_receive_frame failed!");
                break;
            }
            //LOGW("avcodec_receive_frame %lld",frame->pts);
            //如果是视频帧
            if(cc == vc)
            {
                frameCount++;
                vctx = sws_getCachedContext(vctx,
                                            frame->width,
                                            frame->height,
                                            (AVPixelFormat)frame->format,
                                            outWidth,
                                            outHeight,
                                            AV_PIX_FMT_RGBA,
                                            SWS_FAST_BILINEAR,
                                            0,0,0
                );
                if(!vctx)
                {
                    LOGW("sws_getCachedContext failed!");
                }
                else
                {
                    uint8_t *data[AV_NUM_DATA_POINTERS] = {0};
                    data[0] =(uint8_t *)rgb;
                    int lines[AV_NUM_DATA_POINTERS] = {0};
                    lines[0] = outWidth * 4;
                    int h = sws_scale(vctx,
                                      (const uint8_t **)frame->data,
                                      frame->linesize,0,
                                      frame->height,
                                      data,lines);
                    LOGW("sws_scale = %d",h);
                    if(h > 0)
                    {
                        ANativeWindow_lock(nwin,&wbuf,0);
                        uint8_t *dst = (uint8_t*)wbuf.bits;
                        memcpy(dst,rgb,outWidth*outHeight*4);
                        ANativeWindow_unlockAndPost(nwin);
                    }
                }
            }
            else //音频
            {
                uint8_t *out[2] = {0};
                out[0] = (uint8_t*) pcm;

                //音频重采样
                int len = swr_convert(actx,out,
                                      frame->nb_samples,
                                      (const uint8_t**)frame->data,
                                      frame->nb_samples);
                LOGW("swr_convert = %d",len);
            }

        }

        //////////////////////


    }
    delete[] rgb;
    delete[] pcm;

    // 关闭上下文
    avformat_close_input(&ic);


    env->ReleaseStringUTFChars(url_, path);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_hugo_ffmpegstepbystep_MainActivity_test(JNIEnv *env, jobject instance, jintArray i_,
                                                 jobjectArray j_) {
    // 指向数组首元素地址
    // 第二个参数：指针：指向内存地址
    // 在这个地址存数据
    // true：是拷贝的一个新数据 (新申请内存)
    // false: 就是使用的java的数组 (地址)
    jint *i = env->GetIntArrayElements(i_, NULL);

    //C  调用： (*env)->GetIntArrayElements(env,i_, NULL);
    //获取数组长度
    int32_t length = env->GetArrayLength(i_);
    for (int k = 0; k < length; ++k) {
        LOGE("获取java的参数:%d",*(i+k));
        //修改值
        *(i+k) = 100;
    }
    // 参数3：mode
    // 0:  刷新java数组 并 释放c/c++数组
    // 1 = JNI_COMMIT:
    //      只刷新java数组
    // 2 = JNI_ABORT
    //      只释放
    env->ReleaseIntArrayElements(i_, i, 0);
    //  (*env)->ReleaseIntArrayElements(env,i_, i, 0);


    jint strlength = env->GetArrayLength(j_);
    for (int i = 0; i < strlength; ++i) {
        jstring str = static_cast<jstring>(env->GetObjectArrayElement(j_, i));
        //转成可操作的c/c++字符串
        const char* s = env->GetStringUTFChars(str,0);
        LOGE("获取java的参数:%s",s);
        env->ReleaseStringUTFChars(str,s);
    }
    return 100;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_hugo_ffmpegstepbystep_MainActivity_passObject(JNIEnv *env, jobject instance, jobject bean,
                                                       jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);

    //反射调用java方法
    //1、获取java对应的class对象
    jclass beanCls = env->GetObjectClass(bean);
    //2、找到要调用的方法
    // 参数3： 签名
    //get方法
    jmethodID  getI = env->GetMethodID(beanCls,"getI","()I");
    //3、调用
    jint i = env->CallIntMethod(bean,getI);
    LOGE("C++ 调用Java getI方法:%d",i);

    //set 方法
    jmethodID  setI = env->GetMethodID(beanCls,"setI","(I)V");
    env->CallVoidMethod(bean,setI,200);

    //static 方法
    jmethodID  printInfo = env->GetStaticMethodID(beanCls,"printInfo","(Ljava/lang/String;)V");
    //创建java字符串
    jstring  str2 = env->NewStringUTF("我是Bean类的静态方法，被C++调用");
    env->CallStaticVoidMethod(beanCls,printInfo, str2);
    //释放局部引用
    env->DeleteLocalRef(str2);


    //修改属性值
    jfieldID  fileId = env->GetFieldID(beanCls,"i","I");
    env->SetIntField(bean,fileId,300);


    env->ReleaseStringUTFChars(str_, str);
}

//1 创建引擎
static SLObjectItf  engineSL = NULL;
SLEngineItf CreateSL()
{
    SLresult re;
    SLEngineItf en;
    re = slCreateEngine(&engineSL,0,0,0,0,0);
    if(re != SL_RESULT_SUCCESS) return NULL;
    re = (*engineSL)->Realize(engineSL,SL_BOOLEAN_FALSE);
    if(re != SL_RESULT_SUCCESS) return NULL;
    re = (*engineSL)->GetInterface(engineSL,SL_IID_ENGINE,&en);
    if(re != SL_RESULT_SUCCESS) return NULL;
    return en;
}

void PcmCall(SLAndroidSimpleBufferQueueItf bf,void *contex)
{
    LOGD("PcmCall");
    static FILE *fp = NULL;
    static char *buf = NULL;
    if(!buf)
    {
        buf = new char[1024*1024];
    }
    if(!fp)
    {
        fp = fopen("/sdcard/test.pcm","rb");
    }
    if(!fp)return;
    if(feof(fp) == 0)
    {
        int len = fread(buf,1,1024,fp);
        if(len > 0)
            (*bf)->Enqueue(bf,buf,len);
    }
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_hugo_ffmpegstepbystep_MainActivity_TestOpenSL(JNIEnv *env, jobject instance) {

    std::string hello = "Hello from C++";

    //1 创建引擎
    SLEngineItf eng = CreateSL();
    if(eng){
        LOGD("CreateSL success！ ");
    }else{
        LOGD("CreateSL failed！ ");
    }

    //2 创建混音器
    SLObjectItf mix = NULL;
    SLresult re = 0;
    re = (*eng)->CreateOutputMix(eng,&mix,0,0,0);
    if(re !=SL_RESULT_SUCCESS )
    {
        LOGD("SL_RESULT_SUCCESS failed!");
    }
    re = (*mix)->Realize(mix,SL_BOOLEAN_FALSE);
    if(re !=SL_RESULT_SUCCESS )
    {
        LOGD("(*mix)->Realize failed!");
    }
    SLDataLocator_OutputMix outmix = {SL_DATALOCATOR_OUTPUTMIX,mix};
    SLDataSink audioSink= {&outmix,0};

    //3 配置音频信息
    //缓冲队列
    SLDataLocator_AndroidSimpleBufferQueue que = {SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE,10};
    //音频格式
    SLDataFormat_PCM pcm = {
            SL_DATAFORMAT_PCM,
            2,//    声道数
            SL_SAMPLINGRATE_44_1,
            SL_PCMSAMPLEFORMAT_FIXED_16,
            SL_PCMSAMPLEFORMAT_FIXED_16,
            SL_SPEAKER_FRONT_LEFT|SL_SPEAKER_FRONT_RIGHT,
            SL_BYTEORDER_LITTLEENDIAN //字节序，小端
    };
    SLDataSource ds = {&que,&pcm};


    //4 创建播放器
    SLObjectItf player = NULL;
    SLPlayItf iplayer = NULL;
    SLAndroidSimpleBufferQueueItf pcmQue = NULL;
    const SLInterfaceID ids[] = {SL_IID_BUFFERQUEUE};
    const SLboolean req[] = {SL_BOOLEAN_TRUE};
    re = (*eng)->CreateAudioPlayer(eng,&player,&ds,&audioSink,sizeof(ids)/sizeof(SLInterfaceID),ids,req);
    if(re !=SL_RESULT_SUCCESS )
    {
        LOGD("CreateAudioPlayer failed!");
    } else{
        LOGD("CreateAudioPlayer success!");
    }
    (*player)->Realize(player,SL_BOOLEAN_FALSE);
    //获取player接口
    re = (*player)->GetInterface(player,SL_IID_PLAY,&iplayer);
    if(re !=SL_RESULT_SUCCESS )
    {
        LOGD("GetInterface SL_IID_PLAY failed!");
    }
    re = (*player)->GetInterface(player,SL_IID_BUFFERQUEUE,&pcmQue);
    if(re !=SL_RESULT_SUCCESS )
    {
        LOGD("GetInterface SL_IID_BUFFERQUEUE failed!");
    }

    //设置回调函数，播放队列空调用
    (*pcmQue)->RegisterCallback(pcmQue,PcmCall,0);

    //设置为播放状态
    (*iplayer)->SetPlayState(iplayer,SL_PLAYSTATE_PLAYING);

    //启动队列回调
    (*pcmQue)->Enqueue(pcmQue,"",1);

    return env->NewStringUTF(hello.c_str());
}