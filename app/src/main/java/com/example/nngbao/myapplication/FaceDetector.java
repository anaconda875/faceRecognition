package com.example.nngbao.myapplication;

public class FaceDetector {
    static {
        System.loadLibrary("native_lib");
    }
    public static native int[] detectFace(String xmlPath, long rgbaSrc);
}
