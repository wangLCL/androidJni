//
// Created by Administrator on 2023/7/11.
//

#include "JniGLLib.h"

JniGLLib::JniGLLib(){
    gTriangleVertices = new float [9]{0.0f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f};
};

GLint JniGLLib::loadShader(const GLint type, string gvertexShader){
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

void JniGLLib::printInfo(const char* name,GLenum s){
    const GLubyte* cx = glGetString(s);
    const char *glString = reinterpret_cast<const char *>(cx);
    //std::string *str = new std::string (glString);
    LOGI("%s  %s",name, glString);
}

GLint JniGLLib::createProgram(string gvertexShader, string fragTexShader) {
    GLint vertex = loadShader(GL_VERTEX_SHADER,gvertexShader);
    GLint frag = loadShader(GL_FRAGMENT_SHADER,fragTexShader);
    GLint program = glCreateProgram();
    glAttachShader(program,vertex);
    glAttachShader(program,frag);
    glLinkProgram(program);
    LOGI("program %s:",to_string(program).c_str());
    return program;
}

void JniGLLib::render() {
    glClearColor(1.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    glVertexAttribPointer(vv, 2, GL_FLOAT, GL_FALSE, 0,
                          gTriangleVertices);
    glEnableVertexAttribArray(vv);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void JniGLLib::create(float width,float height) {
    printInfo("Version",GL_VERSION);
    printInfo("Vendor",GL_VENDOR);
    printInfo("Renderer",GL_RENDERBUFFER);
    glViewport(0,0,width,height);
    program = createProgram(gVertexShader, gFragmentShader);
    vv = glGetAttribLocation(program,"vPosition");
}