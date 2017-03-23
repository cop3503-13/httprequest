#include <iostream>
#include <unordered_map>
#include "HTTPRequest.h"

int main() {
    std::string url = "http://api.openweathermap.org/data/2.5/weather";
    std::string zip = "32601";
    std::string countryCode = "us";
    std::string apikey = "GET API KEY";
    std::string out;

    /*******************************************
    / HTTPRequest Get example using full url
    /******************************************/
    std::string fullUrl = url + "?zip=" + zip + "," + countryCode + "&unit=imperial&appid=" + apikey;
    out = HTTPRequest::Get(fullUrl);
    std::cout << "GET with full url: " << std::endl << out << std::endl << std::endl;

    /****************************************
    / HTTPRequest Get with base url and an unordered_map containing the params
    /***************************************/
    std::unordered_map <std::string, std::string> params = {
            {"zip",   "32836,us"},
            {"appid", apikey},
            {"unit",  "imperial"}
    };
    out = HTTPRequest::Get(url, params);
    std::cout << "GET with params: " << std::endl << out << std::endl << std::endl;

    return 0;
}