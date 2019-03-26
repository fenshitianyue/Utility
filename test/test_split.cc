#include "split.hpp"

void test_strtok_split(){
  char input[] = "world\3n.世界"; 
  char* result[2] = {0};
  ssize_t n = StringSplit::Split_strtok_r(input, "\3", result);
  if(n != 2){
    std::cout << "split faild! n : " << n << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "word = " << result[0] << std::endl;
  std::cout << "explain = " << result[1] << std::endl;
}

void test_cppstd_split(){
  std::string data("world\3n.世界"); 
  std::vector<std::string> result;
  ssize_t n = StringSplit::Split_cppstd(data, result, '\3');
  if(n != 2){
    std::cout << "split faild! n:" << n << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "word = " << result[0] << std::endl;
  std::cout << "explain = " << result[1] << std::endl;
}

void test_boost_split(){
  std::string data("world\3n.世界");
  std::vector<std::string> result;
  std::string word; 
  std::string explain;
  StringSplit::Split_boost(data, &result, "\3");
  word = result[0];
  explain = result[1];
  std::cout << "word = " << word << std::endl;
  std::cout << "explain = " << explain << std::endl;
}

void test_my_split(){
  std::string data("world\3n.世界");
  std::vector<std::string> result;
  StringSplit::Split_my(data, result, '\3');
  std::cout << "word = " << result[0] << std::endl;
  std::cout << "explain = " << result[1] << std::endl;
}


int main(){

  return 0;
}
