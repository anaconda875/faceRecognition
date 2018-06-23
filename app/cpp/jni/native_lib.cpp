#include <native_lib.h>

JNIEXPORT jstring JNICALL Java_com_example_nngbao_myapplication_FaceDetector_stringFromJNI(JNIEnv *env, jobject) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jint JNICALL Java_com_example_nngbao_myapplication_FaceDetector_intFromJNI(JNIEnv *env, jobject) {
	return (jint)1;
}

JNIEXPORT jintArray JNICALL Java_com_example_nngbao_myapplication_FaceDetector_detectFace(JNIEnv *env, jobject, jstring xmlPath, jlong rgbaSrc, jobject) {
	Mat &frame = *(Mat*) rgbaSrc;
	const char *nativeString = env->GetStringUTFChars(xmlPath, JNI_FALSE);
	String str(nativeString);
	cout << str << endl;
	
	/*int hsize[] = {16,16,16};
    float hranges[] = { 0,180 };
	const float* phranges[] = {hranges,hranges,hranges};
	Rect r(25, 90, 30, 12);  
    Rect track_window = r;
    Mat roi = frame(r);
    Mat hsv_roi,hsv,dst;
    cvtColor(roi,hsv_roi,CV_BGR2HSV);
    Mat maskroi;
    inRange(hsv_roi, Scalar(0., 60., 32.), Scalar(180., 255., 255.),maskroi);
    Mat roi_hist;
    int ch[] = { 0, 1,2 };
    calcHist(&roi, 1, ch, maskroi, roi_hist, 1, hsize, phranges);
    normalize(roi_hist, roi_hist, 0, 255, NORM_MINMAX);*/
	
	CascadeClassifier faceDetector;
	if(!faceDetector.load(str)) return NULL;
		//return env->NewStringUTF(((std::string)"ERROR").c_str());
	
	vector<Rect> faces;
	Mat gray;
	cvtColor(frame, gray, CV_BGR2GRAY);
	equalizeHist(gray, gray);
	faceDetector.detectMultiScale(gray, faces, 1.2, 3, 0|CV_HAAR_SCALE_IMAGE, Size(150, 150), Size(360, 360));
	stringstream ss;
	ss << faces.size();
	__android_log_write(ANDROID_LOG_INFO, "onCameraFrame: ", ss.str().c_str());
	
	for(size_t i = 0; i < faces.size(); i++) {
		if(faces[i].width < 150 || faces[i].height > 360)
			continue;
		//Mat faceROI = frame_gray( faces[i] );
		int x = faces[i].x;
		int y = faces[i].y;
		int h = y+faces[i].height;
		int w = x+faces[i].width;
		rectangle(frame, Point(x,y), Point(w,h), Scalar(255,0,255), 2, 8, 0);
		
		int size = 4;
		jintArray result;
		result = env->NewIntArray(size);
		if (result == NULL) {
			return NULL; /* out of memory error thrown */
		}
		// fill a temp structure to use to populate the java int array
		jint fill[] = {x, y, w, h};
		// move from the temp structure to the java structure
		env->SetIntArrayRegion(result, 0, size, fill);
		
		Rect r(x, y, w - x, h - y);  
		//Rect track_window = r;
		Mat roi = frame(r);
		//cvtColor(roi, roi, CV_BGR2RGB);
		imwrite("/sdcard/c.jpg", roi);
		return result;
		
		//return true;
	}
	return NULL;
}
