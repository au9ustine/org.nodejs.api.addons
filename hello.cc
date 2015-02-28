// -*- coding: utf-8 -*-

// hello.cc
#include <node.h>

using namespace v8;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "世界"));
}

void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "hello", Method);
}

NODE_MODULE(addon, init)

// [au9ustine]: at least node addons could provide another way to build
//              c++ modules apart from python/c++ interop and JNI, and 
//              it's quite easy :D
