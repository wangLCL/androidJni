#include <jni.h>
#include <string>
#include <GLES2/gl2.h>
#include <android/log.h>
#include <GLES2/gl2ext.h>

#define LOG_TAG "libESV2jni"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__);
using namespace std;
auto gVertexShader =
        "attribute vec4 vPosition;\n"
        "void main() {\n"
        "  gl_Position = vPosition;\n"
        "}\n";

auto gFragmentShader =
        "precision mediump float;\n"
        "void main() {\n"
        "  gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
        "}\n";
const GLfloat gTriangleVertices[] = {0.0f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f};


void printInfo(const char* name,GLenum s){
    const GLubyte* cx = glGetString(s);
    const char *glString = reinterpret_cast<const char *>(cx);
    //std::string *str = new std::string (glString);
    LOGI("%s  %s",name, glString);
}

GLint loadShader(const GLint type, string gvertexShader){
    GLint shader = glCreateShader(type);
    LOGI("shader: %s", to_string(shader).c_str());
    if (shader){
        const GLchar* ss = gvertexShader.c_str();
        const GLchar* const* stringPtr = &ss;
        glShaderSource(shader, 1,
                       &ss, NULL);
        glCompileShader(shader);
    }
    return shader;
}

GLint program;
GLint vv;

GLint createProgram(string gvertexShader, string fragTexShader) {
    GLint vertex = loadShader(GL_VERTEX_SHADER,gvertexShader);
    GLint frag = loadShader(GL_FRAGMENT_SHADER,fragTexShader);
    GLint program = glCreateProgram();

    glAttachShader(program,vertex);
    glAttachShader(program,frag);
    glLinkProgram(program);
    LOGI("program %s:",to_string(program).c_str());
    return program;
}

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
    printInfo("Version",GL_VERSION);
    printInfo("Vendor",GL_VENDOR);
    printInfo("Renderer",GL_RENDERBUFFER);
    glViewport(0,0,width,height);
    program = createProgram(gVertexShader, gFragmentShader);
    vv = glGetAttribLocation(program,"vPosition");
}
extern "C"
JNIEXPORT void JNICALL
Java_kw_learn_opglndk_NdkLib_clearView(JNIEnv *env, jclass clazz) {
    // TODO: implement clearView()
    glClearColor(1.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    glVertexAttribPointer(vv, 2, GL_FLOAT, GL_FALSE, 0,
                          gTriangleVertices);
    glEnableVertexAttribArray(vv);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}