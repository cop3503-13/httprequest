#include "HTTPRequest.h"
#include "include/curl/curl.h"
#include <iostream>


//local variable to hold response
std::string resp;

/* static */
size_t HTTPRequest::readJsonResponseCallback(char *buffer, size_t size, size_t nmemb, void *up) {
    size_t totalSize = size * nmemb;
    resp.append(buffer, totalSize);
    return totalSize;
}

/* static */
std::string HTTPRequest::Get(std::string url) {
    CURL *curl;
    CURLcode res;
    resp = "";

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &HTTPRequest::readJsonResponseCallback);


        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    return resp;
}

/* static */
std::string HTTPRequest::Get(std::string url, std::unordered_map <std::string, std::string> parameters) {
    std::string fullUrl = url + "?";
    for (const auto &parameter : parameters)
        fullUrl += parameter.first + "=" + parameter.second + "&";
    //remove the trailing &;
    fullUrl.pop_back();

    return HTTPRequest::Get(fullUrl);
}



