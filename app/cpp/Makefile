build:
	echo "Start building"
	ndk-build

install:
	echo "Start installing"
	echo d | xcopy /y libs\armeabi-v7a ..\src\main\jniLibs\armeabi-v7a

clean:
	rm -r obj
	rm -r libs