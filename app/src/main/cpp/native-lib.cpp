#include <jni.h>
#include <string>
#include "gl/JniGLLib.h"

extern "C"
JNIEXPORT jlong JNICALL
Java_kw_learn_opglndk_NdkLib_create(JNIEnv *env, jclass clazz, jint width, jint height) {
    // TODO: implement create()
    JniGLLib *jniGlLib = new JniGLLib();
    jniGlLib->create(width,height);
    return reinterpret_cast<jlong>(jniGlLib);
}
extern "C"
JNIEXPORT void JNICALL
Java_kw_learn_opglndk_NdkLib_clearView(JNIEnv *env, jclass clazz,jlong jlong1) {
    // TODO: implement clearView()
    JniGLLib *jniGlLib = reinterpret_cast<JniGLLib*>(jlong1);
    jniGlLib->render();
}