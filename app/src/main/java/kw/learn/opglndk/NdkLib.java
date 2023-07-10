package kw.learn.opglndk;

/**
 * @Auther jian xian si qi
 * @Date 2023/7/10 9:45
 */
public class NdkLib {
    // Used to load the 'opglndk' library on application startup.
    static {
        System.loadLibrary("opglndk");
    }

    public static native void create(int width, int height);

    public static native void clearView() ;
}
