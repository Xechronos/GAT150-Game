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
    bool Read(const rapidjson::Value& value, const std::string& name, int& data, bool IsRequired)
    {
        if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsInt()) {
            if (IsRequired)  std::cerr << "could not read json value: " << name << std::endl;
            return false;
        }
            data = value[name.c_str()].GetInt();
        return true;
    }
    bool Read(const rapidjson::Value& value, const std::string& name, float& data, bool IsRequired)
    {
        if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsNumber()) {
            if (IsRequired)  std::cerr << "could not read json value: " << name << std::endl;
            return false;
        }
        data = value[name.c_str()].GetFloat();
        return true;
    }
    bool Read(const rapidjson::Value& value, const std::string& name, bool& data, bool IsRequired)
    {
        if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsBool()) {
            if (IsRequired) std::cerr << "could not read json value: " << name << std::endl;
            return false;
        }
        data = value[name.c_str()].GetBool();
        return true;
    }
    bool Read(const rapidjson::Value& value, const std::string& name, std::string& data, bool IsRequired)
    {
        if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsString()) {
            if (IsRequired) std::cerr << "could not read json value: " << name << std::endl;
            return false;
        }
        data = value[name.c_str()].GetString();
        return true;
    }
    bool Read(const rapidjson::Value& value, const std::string& name, Vector2& data, bool IsRequired)
    {
        // check if the value has the "<name>" and is an array with 2 elements
        if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsArray() || value[name.c_str()].Size() != 2)
        {
            if (IsRequired) std::cerr << "Could not read Json value: " << name << std::endl;
            return false;
        }

        // get json array object
        auto& array = value[name.c_str()];
        // get array values
        for (rapidjson::SizeType i = 0; i < array.Size(); i++)
        {
            if (!array[i].IsNumber())
            {
                if (IsRequired) std::cerr << "Could not read Json value: " << name << std::endl;
                return false;
            }

            // get the data
            data[i] = array[i].GetFloat();
        }

        return true;
    }
    bool Read(const rapidjson::Value& value, const std::string& name, Color& data, bool IsRequired)
    {
        // check if the value has the "<name>" and is an array with 2 elements
        if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsArray() || value[name.c_str()].Size() != 2)
        {
           if (IsRequired) std::cerr << "Could not read Json value: " << name << std::endl;
            return false;
        }

        // get json array object
        auto& array = value[name.c_str()];
        // get array values
        for (rapidjson::SizeType i = 0; i < array.Size(); i++)
        {
            if (!array[i].IsNumber())
            {
                if (IsRequired) std::cerr << "Could not read Json value: " << name << std::endl;
                return false;
            }

            // get the data
            data[i] = array[i].GetFloat();
        }

        return true;
    }
}
