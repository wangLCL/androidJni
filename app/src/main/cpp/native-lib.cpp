#include <jni.h>
#include <string>
#include <GLES2/gl2.h>

extern "C" JNIEXPORT jstring JNICALL
Java_kw_learn_opglndk_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_kw_learn_opglndk_NdkLib_create(JNIEnv *env, jclass clazz, jint width, jint height) {
    // TODO: implement create()
    glViewport(0,0,width,height);
}
extern "C"
JNIEXPORT void JNICALL
Java_kw_learn_opglndk_NdkLib_clearView(JNIEnv *env, jclass clazz) {
    // TODO: implement clearView()
    glClearColor(1.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}