package kw.learn.opglndk;

import android.content.Context;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * @Auther jian xian si qi
 * @Date 2023/7/10 9:43
 */
public class GLView extends GLSurfaceView {
    public GLView(Context context) {
        super(context);
        setRenderer(new Renderer() {
            @Override
            public void onSurfaceCreated(GL10 gl, EGLConfig config) {

            }

            @Override
            public void onSurfaceChanged(GL10 gl, int width, int height) {
//                gl.glViewport(0,0,width,height);
                NdkLib.create(width,height);
            }

            @Override
            public void onDrawFrame(GL10 gl) {
//                gl.glClearColor(1,1,1,1);
//                gl.glClear(GLES20.GL_COLOR_BUFFER_BIT);
                NdkLib.clearView();
            }
        });
    }
}
