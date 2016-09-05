
#include "methodarea.h"
#include "classviewer.h" // talvez retirar isso e colocar a getFormattedConstant() na Util.

#include "classloader.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "vmstack.h"
#include "executionengine.h"

MethodArea::MethodArea() {
    
}

MethodArea::~MethodArea() {
    
}

ClassRuntime* MethodArea::loadClassNamed(const string &className) {
    // se a classe já tiver sido carregada, retorna-la
    if (_classes.count(className) > 0) {
        return getClassNamed(className);
    }
    
    string classNameStr(className);
    string classLocation("");
    string classFormat(".class");
    
    if (classNameStr.size() < classFormat.size() || classNameStr.compare(classNameStr.size() - classFormat.size(), classFormat.size(), classFormat) != 0) {
        classNameStr = classLocation + classNameStr + classFormat; // concatena com ".class"
    }

    FILE *fp = fopen(classNameStr.c_str(), "rb");
    if (fp == NULL) {
        cerr << "NoClassDefFoundError: " << classNameStr << endl;
        exit(1);
    }
    
    ClassLoader &classLoader = ClassLoader::getInstance();
    ClassFile *classFile = classLoader.readClassFile(fp);
    ClassRuntime *classRuntime = new ClassRuntime(classFile);
    addClass(classRuntime);
    fclose(fp);
    
    // adicionando <clinit> da classe (se existir) na stack frame.
    ExecutionEngine &executionEngine = ExecutionEngine::getInstance();
    bool existsClinit = executionEngine.doesMethodExist(classRuntime, "<clinit>", "()V");
    if (existsClinit) {
        VMStack &stackFrame = VMStack::getInstance();
        Frame *newFrame = new Frame(classRuntime, "<clinit>", "()V");
        stackFrame.addFrame(newFrame);
    }
    
    return classRuntime;
}

ClassRuntime* MethodArea::getClassNamed(const string &className) {
    map<string, ClassRuntime*>::iterator it = _classes.find(className);
    
    if (it == _classes.end()) {
        return NULL;
    }
    
    return it->second;
}

bool MethodArea::addClass(ClassRuntime *classRuntime) {
    ClassFile *classFile = classRuntime->getClassFile();
    
    const char *key = getFormattedConstant(classFile->constant_pool, classFile->this_class);
    
    if (_classes.count(key) > 0) {
        return false;
    }
    
    _classes[key] = classRuntime;
    return true;
}
