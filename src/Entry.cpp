/* 
 * Essex Engine
 * 
 * Copyright (C) 2017 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */

#include <EssexEngineJsonCppDriver/JsonCppDriver.h>

using EssexEngine::Context;
using EssexEngine::WeakPointer;

using EssexEngine::Drivers::JsonCpp::JsonCppDriver;
using EssexEngine::Daemons::Json::IJsonDriver;

extern "C" {
    void driver_init(WeakPointer<Context> context) {
        context->RegisterDriver<IJsonDriver>(
            WeakPointer<IJsonDriver>(new JsonCppDriver(context)) 
        );
    }
}
