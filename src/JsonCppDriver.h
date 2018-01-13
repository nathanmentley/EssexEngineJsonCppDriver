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

#include <EssexEngineCore/WeakPointer.h>
#include <EssexEngineCore/BaseDriver.h>
#include <EssexEngineCore/LogDaemon.h>
#include <EssexEngineCore/Context.h>
#include <EssexEngineJsonDaemon/IJsonDriver.h>

#include <EssexEngineFileSystemDaemon/IFileBuffer.h>

#include <EssexEngineJsonCppDriver/JsonDocument.h>

namespace EssexEngine{
namespace Drivers{
namespace JsonCpp{
    class JsonCppDriver:public Core::Drivers::Base::BaseDriver, public Daemons::Json::IJsonDriver
    {
        public:
            JsonCppDriver(WeakPointer<Context> _context);
            ~JsonCppDriver();
            
            //IDriver
            void Init() {
                if(GetContext()->HasDaemon<Core::Logging::LogDaemon>()) {
                    GetContext()->GetDaemon<Core::Logging::LogDaemon>()->LogLine(
                        "Loading Driver [%s] [%s]",
                        GetDriverName().c_str(),
                        GetDriverVersion().c_str()
                    );
                }
            }
        
            WeakPointer<Daemons::Json::IJsonDocument> GetJsonDocument(std::string data);
            WeakPointer<Daemons::Json::IJsonNode> GetJsonNode(WeakPointer<Daemons::Json::IJsonDocument> doc, std::string key);
            WeakPointer<Daemons::Json::IJsonNode> GetJsonNode(WeakPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            std::list<WeakPointer<Daemons::Json::IJsonNode>> GetJsonNodeArray(WeakPointer<Daemons::Json::IJsonDocument> doc, std::string key);
            std::list<WeakPointer<Daemons::Json::IJsonNode>> GetJsonNodeArray(WeakPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            Nullable<std::string> GetStringFromNode(WeakPointer<Daemons::Json::IJsonDocument> document, std::string key);
            Nullable<int> GetIntFromNode(WeakPointer<Daemons::Json::IJsonDocument> document, std::string key);
            Nullable<bool> GetBoolFromNode(WeakPointer<Daemons::Json::IJsonDocument> document, std::string key);
        
            Nullable<std::string> GetStringFromNode(WeakPointer<Daemons::Json::IJsonNode> node, std::string key);
            Nullable<int> GetIntFromNode(WeakPointer<Daemons::Json::IJsonNode> node, std::string key);
            Nullable<bool> GetBoolFromNode(WeakPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            Nullable<std::string> GetStringFromNode(WeakPointer<Daemons::Json::IJsonNode> node);
            Nullable<int> GetIntFromNode(WeakPointer<Daemons::Json::IJsonNode> node);
            Nullable<bool> GetBoolFromNode(WeakPointer<Daemons::Json::IJsonNode> node);
        
            WeakPointer<Daemons::Json::IJsonNode> CreateNode();
        
            void RemoveNode(WeakPointer<Daemons::Json::IJsonDocument> doc, std::string key);
            void RemoveNode(WeakPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            void AppendNode(WeakPointer<Daemons::Json::IJsonDocument> target, WeakPointer<Daemons::Json::IJsonNode> node, std::string key);
            void AppendNode(WeakPointer<Daemons::Json::IJsonNode> target, WeakPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            void AppendToArray(WeakPointer<Daemons::Json::IJsonDocument> target, WeakPointer<Daemons::Json::IJsonNode> node, std::string key);
            void AppendToArray(WeakPointer<Daemons::Json::IJsonNode> target, WeakPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            void SetNodeToString(WeakPointer<Daemons::Json::IJsonDocument> document, Nullable<std::string> value);
            void SetNodeToInt(WeakPointer<Daemons::Json::IJsonDocument> document, Nullable<int> value);
            void SetNodeToBool(WeakPointer<Daemons::Json::IJsonDocument> document, Nullable<bool> value);
        
            void SetNodeToString(WeakPointer<Daemons::Json::IJsonNode> node, Nullable<std::string> value);
            void SetNodeToInt(WeakPointer<Daemons::Json::IJsonNode> node, Nullable<int> value);
            void SetNodeToBool(WeakPointer<Daemons::Json::IJsonNode> node, Nullable<bool> value);
            void SetNodeToArray(WeakPointer<Daemons::Json::IJsonNode> node);
        
            std::string SerializeDocument(WeakPointer<Daemons::Json::IJsonDocument> doc);
            
            //BaseDriver
            std::string GetDriverName() { return "JsonCpp"; }
            std::string GetDriverVersion() { return ESSEX_ENGINE_VERSION; }
        protected:
            WeakPointer<Daemons::Json::IJsonNode> GetJsonNode(WeakPointer<JsonDocument> doc, std::string key);
            std::list<WeakPointer<Daemons::Json::IJsonNode>> GetJsonNodeArray(WeakPointer<JsonDocument> doc, std::string key);
            Nullable<std::string> GetStringFromNode(WeakPointer<JsonDocument> node, std::string key);
            Nullable<int> GetIntFromNode(WeakPointer<JsonDocument> node, std::string key);
            Nullable<bool> GetBoolFromNode(WeakPointer<JsonDocument> node, std::string key);
            Nullable<std::string> GetStringFromNode(WeakPointer<JsonDocument> node);
            Nullable<int> GetIntFromNode(WeakPointer<JsonDocument> node);
            Nullable<bool> GetBoolFromNode(WeakPointer<JsonDocument> node);

            WeakPointer<JsonDocument> GetJsonDocumentPointer(WeakPointer<Daemons::Json::IJsonDocument> document);
            WeakPointer<JsonDocument> GetJsonDocumentPointer(WeakPointer<Daemons::Json::IJsonNode> node);
        private:
    };
}}};
