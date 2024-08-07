#include "json.h"
#include "EFile.h"
#include <rapidjson/istreamwrapper.h>
#include <iostream>

namespace Json {
    bool Load(const std::string& filename, rapidjson::Document& document)
    {
        std::string buffer;
        if (!File::ReadFile(filename, buffer)) {
            return false;
       }
        std::stringstream stream(buffer);
        rapidjson::IStreamWrapper istream(stream);
        document.ParseStream(istream);
        if (!document.IsObject()) {
            std::cerr << "could not parse json: " << filename << std::endl;
            return false;
        }
        return true;
    }
    bool Read(const rapidjson::Value& value, const std::string& name, int& data)
    {
        if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsInt()) {
            std::cerr << "could not read json value: " << name << std::endl;
            return false;
        }
            data = value[name.c_str()].GetInt();
        return true;
    }
    bool Read(const rapidjson::Value& value, const std::string& name, bool& data)
    {
        if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsInt()) {
            std::cerr << "could not read json value: " << name << std::endl;
            return false;
        }
        data = value[name.c_str()].GetBool();
        return true;
    }
    bool Read(const rapidjson::Value& value, const std::string& name, std::string& data)
    {
        if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsInt()) {
            std::cerr << "could not read json value: " << name << std::endl;
            return false;
        }
        data = value[name.c_str()].GetString();
        return true;
    }
}
