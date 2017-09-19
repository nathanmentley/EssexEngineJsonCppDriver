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
#pragma once

#include <EssexEngineJsonCppDriver/json.h>

#include <EssexEngineJsonDaemon/IJsonDocument.h>
#include <EssexEngineJsonDaemon/IJsonNode.h>

namespace EssexEngine{
namespace Drivers{
namespace JsonCpp{
    class JsonDocument: public Daemons::Json::IJsonDocument, public Daemons::Json::IJsonNode {
        public:
            JsonDocument(Json::Value _data);
            ~JsonDocument();
            Json::Value data;
    };
}}};