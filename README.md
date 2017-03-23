# HTTPRequest
_HTTPRequest class with static methods encapsulating cURL GET_

## Prerequisites
I have included the curl header files in `include/curl/`, but this still requires cURL, `sudo apt-get install curl`.

## Compiling
Because this uses a local library, you need to link using the `-lcurl` flag:
```bash
g++ -std=c++11 *.cpp -lcurl
```
## Usage of HTTPRequest
The class implements two static functions, one that accepts one full URL argument, and another that accepts a base URL, and an `unordered_map` of parameter keys/values.

The main.cpp has working examples, provided you have your own API KEY from [openweather.org](https://home.openweathermap.org/users/sign_up)

### Basic usage follows...
#### _with a fully constructed url argument_
```cpp
std::string url = "http://www.example.com?name=chris&cool=yes";

std::string output = HTTPRequest::Get(fullUrl);
```
#### _with a base url argument and an unordered_map of parameters_
```cpp
std::string url = "http://www.example.com"
std::unordered_map<std::string, std::string> parameters = {
  {"key", "value"},
  {"cool", "yes"}
};

std::string output = HTTPRequest::Get(url, parameters);
