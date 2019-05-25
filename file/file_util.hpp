#pragma once
#include <fstream>
#include <string>

class FileUtil{
public:
  //写文件
  static bool ReadFile(const std::string& file_name, std::string& content){
    content.clear();
    std::ifstream file(file_name.c_str());
    if(!file.is_open()){
      return false;
    }
    std::string line;
    while(std::getline(file, line)){
      content += line + "\n";
    }
    file.close();
    return true;
  }
  //读文件
  static bool WriteFile(const std::string& file_name, const std::string& content){
    std::ofstream file(file_name.c_str());
    if(!file.is_open()){
      return false;
    }
    file.write(content.data(), content.size());
    file.close();
    return true;
  }
  //获取文件长度
  static int64_t FileSize(const std::string& file_name){
    int64_t size = 0;
    std::ifstream in(file_name.c_str());
    in.seekg(0, std::ios::end);
    size = in.tellg();
    in.close();
    return size; //字节
  }
};

