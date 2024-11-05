#include <iostream>
#include <string>
#include <json/json.h>

int main() {
    // 解析 JSON 字符串
    std::string jsonString = R"({"name": "John Doe", "age": 30, "is_student": true})";
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(jsonString, root);
    if (!parsingSuccessful) {
        std::cerr << "Failed to parse JSON" << std::endl;
        return 1;
    }

    // 访问 JSON 数据
    std::string name = root["name"].asString();
    int age = root["age"].asInt();
    bool isStudent = root["is_student"].asBool();

    std::cout << "Name: " << name << ", Age: " << age << ", Is Student: " << isStudent << std::endl;

    // 生成 JSON 字符串
    Json::Value newRoot;
    newRoot["name"] = "Jane Doe";
    newRoot["age"] = 25;
    newRoot["is_student"] = false;

    Json::StreamWriterBuilder builder;
    std::string newJsonString = Json::writeString(builder, newRoot);

    std::cout << "New JSON string: " << newJsonString << std::endl;

    return 0;
}
