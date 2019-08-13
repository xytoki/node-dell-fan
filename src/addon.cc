#include <v8.h>
#include <napi.h>
#include "bzh_dell_smm_io_codes.h"
#include "bzh_dell_smm_io_drv_fun.h"
#include <iostream>
using namespace std;
using namespace v8;
wchar_t drvpath[32768];

Napi::Value Load(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	string arg0 = info[0].As<Napi::String>().Utf8Value();
	wstring warg0 = wstring(arg0.begin(), arg0.end());
	const wchar_t* wstr0 = warg0.c_str();
	wcscat_s(drvpath,wstr0);
    bool result = BDSID_Initialize(drvpath);
    if (!result){
		BDSID_Shutdown();
		return Napi::Boolean::New(env,false);
    }
	return Napi::Boolean::New(env,true);
}

Napi::Value Unload(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	BDSID_Shutdown();
	return Napi::Boolean::New(env,true);
}
Napi::Value SetFanSpeed(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	uint32_t arg0 = info[0].As<Napi::Number>().Int32Value();
	uint32_t arg1 = info[1].As<Napi::Number>().Int32Value();
	int result = dell_smm_io_set_fan_lv(arg0, arg1);
	if (result == -1){
		return Napi::Boolean::New(env,false);
	}
	return Napi::Boolean::New(env,true);
}
Napi::Value Command(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	uint32_t arg0 = info[0].As<Napi::Number>().Int32Value();
	uint32_t arg1 = info[1].As<Napi::Number>().Int32Value();
	int result = dell_smm_io(arg0,arg1);
	return Napi::Number::New(env,result);
}
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "load"),Napi::Function::New(env, Load));
  exports.Set(Napi::String::New(env, "unload"),Napi::Function::New(env, Unload));
  exports.Set(Napi::String::New(env, "command"),Napi::Function::New(env, Command));
  exports.Set(Napi::String::New(env, "setFanSpeed"),Napi::Function::New(env, SetFanSpeed));
  return exports;
}

NODE_API_MODULE(addon, Init)
