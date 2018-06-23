#include <jni.h>
#include <android/log.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <sstream>

using namespace cv;
using namespace std;
#ifndef _Included_com_example_nngbao_myapplication_FaceDetector
#define _Included_com_example_nngbao_myapplication_FaceDetector
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_com_example_nngbao_myapplication_FaceDetector_stringFromJNI(JNIEnv *env, jobject);

JNIEXPORT jint JNICALL Java_com_example_nngbao_myapplication_FaceDetector_intFromJNI(JNIEnv *env, jobject);

JNIEXPORT jintArray JNICALL Java_com_example_nngbao_myapplication_FaceDetector_detectFace(JNIEnv *env, jobject, jstring, jlong, jobject);
	
#ifdef __cplusplus
}
#endif
#endif