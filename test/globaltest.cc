#include "napi.h"

using namespace Napi;

Value AddPropertyAndGetFromGlobal(const CallbackInfo& info) {
  auto env = info.Env();
  auto global = env.Global();

  String key = info[0].As<String>();
  Value val = info[1].As<Value>();

  global[key] = val;

  return global.Get(static_cast<napi_value>(key));
}

Value GetGlobalVariableByKey(const CallbackInfo& info) {
  auto global = info.Env().Global();

  String key = info[0].As<String>();

  return global.Get(static_cast<napi_value>(key));
}

Object InitGlobalTest(Env env) {
  Object exports = Object::New(env);

  exports["AddPropertyAndGetFromGlobal"] =
      Function::New(env, AddPropertyAndGetFromGlobal);
  exports["GetGlobalVariableByKey"] =
      Function::New(env, GetGlobalVariableByKey);

  return exports;
}
