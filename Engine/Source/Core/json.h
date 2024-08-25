#pragma once
#include "Math/Vector2.h"
#include "Renderer/Color.h"
#include<rapidjson/document.h>
#include <string>

#define READ_DATA(value, data) Json::Read(value, #data, data)
#define READ_DATA_REQUIRED(value, data) Json::Read(value, #data, data, true)
#define READ_DATA_NAME(value, name, data) Json::Read(value, name, data)
#define READ_DATA_STRUCT(value, data, _struct) Json::Read(value,#data, _struct.##data)

#define HAS_DATA(value, data) value.HasMember(#data)
#define GET_DATA(value, data) value[#data]

namespace Json {
	bool Load(const std::string& filename, rapidjson::Document& document);
	bool Read(const rapidjson::Value& value, const std::string& name, int& data, bool IsRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, float& data, bool IsRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, bool& data, bool IsRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, std::string& data, bool IsRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, Vector2& data, bool IsRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, Color& data, bool IsRequired = false);
}

using json_t = rapidjson::Value;