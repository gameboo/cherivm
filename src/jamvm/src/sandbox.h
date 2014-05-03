#ifndef __SANDBOX_H__
#define __SANDBOX_H__

#ifdef JNI_CHERI

#include "jni.h"

 #define DEFAULT_SANDBOX_MEM 4*MB

extern void initialiseCheriJNI();
extern char *cherijni_libName(char *name);
extern void *cherijni_lookup(void *handle, char *methodName);
extern void *cherijni_open(char *path);
extern jint cherijni_callOnLoadUnload(void *handle, void *ptr, JavaVM *jvm, void *reserved);
extern uintptr_t *cherijni_callMethod(pMethodBlock mb, pClass class, uintptr_t *ostack);
extern void cherijni_runTests(void *handle, pClass context);

#endif

#endif //__SANDBOX_H__
