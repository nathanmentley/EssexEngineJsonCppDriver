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

extern "C" {
    void driver_init(EssexEngine::Context* context) {
        EssexEngine::Drivers::JsonCpp::JsonCppDriver* jsonDriver = new EssexEngine::Drivers::JsonCpp::JsonCppDriver(context);

        context->RegisterDriver<EssexEngine::Daemons::Json::IJsonDriver>(jsonDriver);
    }
}