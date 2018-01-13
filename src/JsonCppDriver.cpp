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

#include <stdio.h>
#include <string.h>

EssexEngine::Drivers::JsonCpp::JsonCppDriver::JsonCppDriver(WeakPointer<Context> _context): BaseDriver(_context) {}

EssexEngine::Drivers::JsonCpp::JsonCppDriver::~JsonCppDriver() {}

EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetJsonDocument(std::string data) {
    Json::Reader reader;
    Json::Value value;

    reader.parse(data, value);

    return WeakPointer<Daemons::Json::IJsonDocument>((Daemons::Json::IJsonDocument*)new JsonDocument(value));
}

EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetJsonNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> doc, std::string key) {    
    return GetJsonNode(GetJsonDocumentPointer(doc), key);
}


EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetJsonNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, std::string key) {
    return GetJsonNode(GetJsonDocumentPointer(node), key);
}

std::list<EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode>> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetJsonNodeArray(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> doc, std::string key) {
    return GetJsonNodeArray(GetJsonDocumentPointer(doc), key);
}

std::list<EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode>> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetJsonNodeArray(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, std::string key) {
    return GetJsonNodeArray(GetJsonDocumentPointer(node), key);
}

EssexEngine::Nullable<std::string> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetStringFromNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> doc, std::string key) {
    return GetStringFromNode(GetJsonDocumentPointer(doc), key);
}
EssexEngine::Nullable<int> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetIntFromNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> doc, std::string key) {
    return GetIntFromNode(GetJsonDocumentPointer(doc), key);
}
EssexEngine::Nullable<bool> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetBoolFromNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> doc, std::string key) {
    return GetBoolFromNode(GetJsonDocumentPointer(doc), key);
}

EssexEngine::Nullable<std::string> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetStringFromNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, std::string key) {
    return GetStringFromNode(GetJsonDocumentPointer(node), key);
}
EssexEngine::Nullable<int> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetIntFromNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, std::string key) {
    return GetIntFromNode(GetJsonDocumentPointer(node), key);
}
EssexEngine::Nullable<bool> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetBoolFromNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, std::string key) {
    return GetBoolFromNode(GetJsonDocumentPointer(node), key);
}

EssexEngine::Nullable<std::string> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetStringFromNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node) {
    return GetStringFromNode(GetJsonDocumentPointer(node));
}
EssexEngine::Nullable<int> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetIntFromNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node) {
    return GetIntFromNode(GetJsonDocumentPointer(node));
}
EssexEngine::Nullable<bool> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetBoolFromNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node) {
    return GetBoolFromNode(GetJsonDocumentPointer(node));
}

EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> EssexEngine::Drivers::JsonCpp::JsonCppDriver::CreateNode() {
    Json::Value data;
    return WeakPointer<Daemons::Json::IJsonNode>((Daemons::Json::IJsonNode*)new JsonDocument(data));
}

void EssexEngine::Drivers::JsonCpp::JsonCppDriver::RemoveNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> doc, std::string key) {
    JsonDocument* target = (JsonDocument*)(doc.Get());
    target->data.removeMember(key);
}
void EssexEngine::Drivers::JsonCpp::JsonCppDriver::RemoveNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, std::string key) {
    JsonDocument* target = (JsonDocument*)(node.Get());
    target->data.removeMember(key);
}

void EssexEngine::Drivers::JsonCpp::JsonCppDriver::AppendNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> target, EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, std::string key) {

}
void EssexEngine::Drivers::JsonCpp::JsonCppDriver::AppendNode(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> target, EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, std::string key) {

}

void EssexEngine::Drivers::JsonCpp::JsonCppDriver::AppendToArray(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> target, EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, std::string key) {

}
void EssexEngine::Drivers::JsonCpp::JsonCppDriver::AppendToArray(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> target, EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, std::string key) {

}

void EssexEngine::Drivers::JsonCpp::JsonCppDriver::SetNodeToString(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> doc, EssexEngine::Nullable<std::string> value) {

}
void EssexEngine::Drivers::JsonCpp::JsonCppDriver::SetNodeToInt(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> doc, EssexEngine::Nullable<int> value) {

}
void EssexEngine::Drivers::JsonCpp::JsonCppDriver::SetNodeToBool(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> doc, EssexEngine::Nullable<bool> value) {

}
void EssexEngine::Drivers::JsonCpp::JsonCppDriver::SetNodeToString(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, EssexEngine::Nullable<std::string> value) {

}
void EssexEngine::Drivers::JsonCpp::JsonCppDriver::SetNodeToInt(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, EssexEngine::Nullable<int> value) {

}
void EssexEngine::Drivers::JsonCpp::JsonCppDriver::SetNodeToBool(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node, EssexEngine::Nullable<bool> value) {

}
void EssexEngine::Drivers::JsonCpp::JsonCppDriver::SetNodeToArray(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node) {
}

std::string EssexEngine::Drivers::JsonCpp::JsonCppDriver::SerializeDocument(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> doc) {
    Json::FastWriter fastWriter;
    return fastWriter.write(GetJsonDocumentPointer(doc)->data);
}


EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetJsonNode(EssexEngine::WeakPointer<EssexEngine::Drivers::JsonCpp::JsonDocument> doc, std::string key) {
    Json::Value target = doc->data[key];
    
    return WeakPointer<Daemons::Json::IJsonNode>((Daemons::Json::IJsonNode*)new JsonDocument(target));
}

std::list<EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode>> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetJsonNodeArray(EssexEngine::WeakPointer<EssexEngine::Drivers::JsonCpp::JsonDocument> doc, std::string key) {
    Json::Value array = doc->data[key];
    
    std::list<WeakPointer<EssexEngine::Daemons::Json::IJsonNode>> ret = std::list<WeakPointer<EssexEngine::Daemons::Json::IJsonNode>>();
    
    for (int i = 0; i < array.size(); i++) {
        WeakPointer<Daemons::Json::IJsonNode> node = WeakPointer<Daemons::Json::IJsonNode>((Daemons::Json::IJsonNode*)new JsonDocument(array[i]));
        
        ret.push_back(std::move(node));
    }
    
    return ret;
}


EssexEngine::Nullable<std::string> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetStringFromNode(EssexEngine::WeakPointer<EssexEngine::Drivers::JsonCpp::JsonDocument> node, std::string key) {
    return Nullable<std::string>(node->data[key].asString());
}

EssexEngine::Nullable<int> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetIntFromNode(EssexEngine::WeakPointer<EssexEngine::Drivers::JsonCpp::JsonDocument> node, std::string key) {
    return Nullable<int>(node->data[key].asInt());
}

EssexEngine::Nullable<bool> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetBoolFromNode(EssexEngine::WeakPointer<EssexEngine::Drivers::JsonCpp::JsonDocument> node, std::string key) {
    return Nullable<bool>(node->data[key].asBool());
}


EssexEngine::Nullable<std::string> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetStringFromNode(EssexEngine::WeakPointer<EssexEngine::Drivers::JsonCpp::JsonDocument> node) {
    return Nullable<std::string>(node->data.asString());
}

EssexEngine::Nullable<int> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetIntFromNode(EssexEngine::WeakPointer<EssexEngine::Drivers::JsonCpp::JsonDocument> node) {
    return Nullable<int>(node->data.asInt());
}

EssexEngine::Nullable<bool> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetBoolFromNode(EssexEngine::WeakPointer<EssexEngine::Drivers::JsonCpp::JsonDocument> node) {
    return Nullable<bool>(node->data.asBool());
}


EssexEngine::WeakPointer<EssexEngine::Drivers::JsonCpp::JsonDocument> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetJsonDocumentPointer(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonDocument> document) {
    return WeakPointer<JsonDocument>((JsonDocument*)(document.Get()));
}

EssexEngine::WeakPointer<EssexEngine::Drivers::JsonCpp::JsonDocument> EssexEngine::Drivers::JsonCpp::JsonCppDriver::GetJsonDocumentPointer(EssexEngine::WeakPointer<EssexEngine::Daemons::Json::IJsonNode> node) {
    return WeakPointer<JsonDocument>((JsonDocument*)(node.Get()));
}
