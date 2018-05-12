/* 
 * Essex Engine
 * 
 * Copyright (C) 2018 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */

#include <EssexEngineJsonCppDriver/JsonDocument.h>

EssexEngine::Drivers::JsonCpp::JsonDocument::JsonDocument(Json::Value _data) {
    data = _data;
}

EssexEngine::Drivers::JsonCpp::JsonDocument::~JsonDocument() { }
