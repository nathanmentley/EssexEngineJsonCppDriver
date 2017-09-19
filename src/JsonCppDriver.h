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

#include <EssexEngineCore/UniquePointer.h>
#include <EssexEngineCore/BaseDriver.h>
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
                if(GetContext()->HasDriver<Core::Logging::ILogDriver>()) {
                    GetContext()->GetDriver<Core::Logging::ILogDriver>()->LogLine(
                        "Loading Driver [%s] [%s]",
                        GetDriverName().c_str(),
                        GetDriverVersion().c_str()
                    );
                }
            }
        
            UniquePointer<Daemons::Json::IJsonDocument> GetJsonDocument(SmartPointer<Daemons::FileSystem::IFileBuffer> data);
            UniquePointer<Daemons::Json::IJsonNode> GetJsonNode(SmartPointer<Daemons::Json::IJsonDocument> doc, std::string key);
            UniquePointer<Daemons::Json::IJsonNode> GetJsonNode(SmartPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            std::list<UniquePointer<Daemons::Json::IJsonNode>> GetJsonNodeArray(SmartPointer<Daemons::Json::IJsonDocument> doc, std::string key);
            std::list<UniquePointer<Daemons::Json::IJsonNode>> GetJsonNodeArray(SmartPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            Nullable<std::string> GetStringFromNode(SmartPointer<Daemons::Json::IJsonDocument> document, std::string key);
            Nullable<int> GetIntFromNode(SmartPointer<Daemons::Json::IJsonDocument> document, std::string key);
            Nullable<bool> GetBoolFromNode(SmartPointer<Daemons::Json::IJsonDocument> document, std::string key);
        
            Nullable<std::string> GetStringFromNode(SmartPointer<Daemons::Json::IJsonNode> node, std::string key);
            Nullable<int> GetIntFromNode(SmartPointer<Daemons::Json::IJsonNode> node, std::string key);
            Nullable<bool> GetBoolFromNode(SmartPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            Nullable<std::string> GetStringFromNode(SmartPointer<Daemons::Json::IJsonNode> node);
            Nullable<int> GetIntFromNode(SmartPointer<Daemons::Json::IJsonNode> node);
            Nullable<bool> GetBoolFromNode(SmartPointer<Daemons::Json::IJsonNode> node);
        
            UniquePointer<Daemons::Json::IJsonNode> CreateNode();
        
            void RemoveNode(SmartPointer<Daemons::Json::IJsonDocument> doc, std::string key);
            void RemoveNode(SmartPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            void AppendNode(SmartPointer<Daemons::Json::IJsonDocument> target, SmartPointer<Daemons::Json::IJsonNode> node, std::string key);
            void AppendNode(SmartPointer<Daemons::Json::IJsonNode> target, SmartPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            void AppendToArray(SmartPointer<Daemons::Json::IJsonDocument> target, SmartPointer<Daemons::Json::IJsonNode> node, std::string key);
            void AppendToArray(SmartPointer<Daemons::Json::IJsonNode> target, SmartPointer<Daemons::Json::IJsonNode> node, std::string key);
        
            void SetNodeToString(SmartPointer<Daemons::Json::IJsonDocument> document, Nullable<std::string> value);
            void SetNodeToInt(SmartPointer<Daemons::Json::IJsonDocument> document, Nullable<int> value);
            void SetNodeToBool(SmartPointer<Daemons::Json::IJsonDocument> document, Nullable<bool> value);
        
            void SetNodeToString(SmartPointer<Daemons::Json::IJsonNode> node, Nullable<std::string> value);
            void SetNodeToInt(SmartPointer<Daemons::Json::IJsonNode> node, Nullable<int> value);
            void SetNodeToBool(SmartPointer<Daemons::Json::IJsonNode> node, Nullable<bool> value);
            void SetNodeToArray(SmartPointer<Daemons::Json::IJsonNode> node);
        
            std::string SerializeDocument(SmartPointer<Daemons::Json::IJsonDocument> doc);
            
            //BaseDriver
            std::string GetDriverName() { return "JsonCpp"; }
            std::string GetDriverVersion() { return ESSEX_ENGINE_VERSION; }
        protected:
            UniquePointer<Daemons::Json::IJsonNode> GetJsonNode(SmartPointer<JsonDocument> doc, std::string key);
            std::list<UniquePointer<Daemons::Json::IJsonNode>> GetJsonNodeArray(SmartPointer<JsonDocument> doc, std::string key);
            Nullable<std::string> GetStringFromNode(SmartPointer<JsonDocument> node, std::string key);
            Nullable<int> GetIntFromNode(SmartPointer<JsonDocument> node, std::string key);
            Nullable<bool> GetBoolFromNode(SmartPointer<JsonDocument> node, std::string key);
            Nullable<std::string> GetStringFromNode(SmartPointer<JsonDocument> node);
            Nullable<int> GetIntFromNode(SmartPointer<JsonDocument> node);
            Nullable<bool> GetBoolFromNode(SmartPointer<JsonDocument> node);

            WeakPointer<JsonDocument> GetJsonDocumentPointer(SmartPointer<Daemons::Json::IJsonDocument> document);
            WeakPointer<JsonDocument> GetJsonDocumentPointer(SmartPointer<Daemons::Json::IJsonNode> node);
        private:
    };
}}};