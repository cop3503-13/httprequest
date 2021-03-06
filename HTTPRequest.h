#include <string>
#include <unordered_map>
#include "include/rapidjson/document.h"

#ifndef HTTPREQUEST_HTTPREQUEST_H
#define HTTPREQUEST_HTTPREQUEST_H


struct HTTPRequest {
    static std::string Get(std::string url);

    static std::string Get(std::string url, std::unordered_map <std::string, std::string> parameters);

    static rapidjson::Document GetJSON(std::string url);

    static rapidjson::Document GetJSON(std::string url, std::unordered_map <std::string, std::string> parameters);

    static size_t readJsonResponseCallback(char *buffer, size_t size, size_t mem, void *up);
};


#endif //HTTPREQUEST_HTTPREQUEST_H

