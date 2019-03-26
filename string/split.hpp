#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp> //boost::split
#include <sstream> //std::stringstream
#include <cstring> //strtok | strtok_r

class StringSplit{
public:
  static void Split_boost(const std::string& input, std::vector<std::string>* output, const std::string& split_char){
    boost::split(*output, input, boost::is_any_of(split_char), boost::token_compress_off);
  }
  static ssize_t Split_strtok(char* input, char* split_char, char* output[]){
    char* tmp = strtok(input, split_char);
    ssize_t output_index = 0;
    while(tmp != NULL){
      output[output_index++] = tmp;
      tmp = strtok(NULL, split_char);
    }
    return output_index;
  }
  static ssize_t Split_strtok_r(char input[], const char* split_char, char* output[]){
    char* buf = NULL;
    ssize_t output_index = 0;
    char* tmp = strtok_r(input, split_char, &buf);
    while(tmp != NULL){
      output[output_index++] = tmp;
      tmp = strtok_r(NULL, split_char, &buf); 
    }
    return output_index;
  }
  static void Split_my(const std::string& input, std::vector<std::string>& output, const char split_char){
    auto pos = input.find_first_of(split_char);
    std::string tmp;
    tmp = input.substr(0, pos);
    output.push_back(tmp);
    tmp = input.substr(pos+1, input.size());
    output.push_back(tmp);
  }
  static ssize_t Split_cppstd(const std::string& input, std::vector<std::string>& output, const char split_char){
    std::stringstream s(input);
    std::string buf;
    ssize_t output_index = 0;
    for(; getline(s, buf, split_char); ++output_index){
      if(buf.empty()) break;
      output.push_back(buf);
    }
    return output_index;
  }
};

