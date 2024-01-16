
#include <iostream>
#include <map>
#include <string>

int main(){

  std::map<int, std::string> hash_table;

  hash_table.insert(std::pair<int, std::string>(1, "one"));
  hash_table[2] = "two";
  

  // range based iteration
  for(auto element : hash_table){
    std::cout << "key: " << element.first << " value: " << element.second << std::endl;
  }

  // Iterator Based
  std::cout << "__Iterator Based__" << std::endl;
  std::map<int, std::string>::iterator it;

  for(it = hash_table.begin(); it != hash_table.end(); it++){
    std::cout << "key: " << (*it).first << " value: " << it->second << std::endl;
  }

}
