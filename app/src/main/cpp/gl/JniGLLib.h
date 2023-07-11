//
// Created by Administrator on 2023/7/11.
//

#ifndef OPGLNDK_JNIGLLIB_H
#define OPGLNDK_JNIGLLIB_H
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <iostream>
#include "../log/JniLog.h"
using namespace std;

class JniGLLib {
public:
    JniGLLib();
private:
    GLfloat *gTriangleVertices;
    GLint program;
    GLint vv;
    string gVertexShader =
            "attribute vec4 vPosition;\n"
            "void main() {\n"
            "  gl_Position = vPosition;\n"
            "}\n";

    string gFragmentShader =
            "precision mediump float;\n"
            "void main() {\n"
            "  gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
            "}\n";
    void printInfo(const char* name,GLenum s);
    GLint createProgram(string gvertexShader, string fragTexShader);
    GLint loadShader(const GLint type, string gvertexShader);
public:
    void create(float width,float height);
    void render();
};


#endif //OPGLNDK_JNIGLLIB_H
