#include <jni.h>
#include <string>

//
// https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/functions.html#NewObject
//

extern "C" JNIEXPORT jstring JNICALL
Java_com_linhphan_secureapi_APIKeyLibrary_getAppId(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "542ffd081e67f4512b705f89d2a611b2";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jobject JNICALL
Java_com_linhphan_secureapi_APIKeyLibrary_getSSLCerts(
        JNIEnv* env,
        jobject /* this */) {

    // removed stuff
    jclass listClass = env->FindClass("java/util/ArrayList");      //HashMap class in java library
    jclass pairClass = env->FindClass("android/util/Pair");

    jmethodID initList = env->GetMethodID(listClass, "<init>", "(I)V");  //constructor of HashMap class
    jobject list = env->NewObject(listClass, initList, 3);      //creating a new object for that class
    jmethodID add = env->GetMethodID(listClass, "add", "(ILjava/lang/Object;)V");

    //The JNI uses the Java VM’s representation of type signatures.
    //https://docs.oracle.com/javase/1.5.0/docs/guide/jni/spec/types.html#wp276
    jmethodID initPair = env->GetMethodID(pairClass, "<init>", "(Ljava/lang/Object;Ljava/lang/Object;)V");
    jobject pair1 = env->NewObject(pairClass, initPair, env->NewStringUTF("api.openweathermap.org"), env->NewStringUTF("sha256/axmGTWYycVN5oCjh3GJrxWVndLSZjypDO6evrHMwbXg="));
    jobject pair2 = env->NewObject(pairClass, initPair, env->NewStringUTF("api.openweathermap.org"), env->NewStringUTF("sha256/4a6cPehI7OG6cuDZka5NDZ7FR8a60d3auda+sKfg4Ng="));
    jobject pair3 = env->NewObject(pairClass, initPair, env->NewStringUTF("api.openweathermap.org"), env->NewStringUTF("sha256/x4QzPSC810K5/cMjb05Qm4k3Bw5zBn4lTdO/nEW/Td4="));

    env->CallVoidMethod(list, add, 0, pair1);
    env->CallVoidMethod(list, add, 1, pair2);
    env->CallVoidMethod(list, add, 2, pair3);

    return list;
}