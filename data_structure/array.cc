#include <vector>
#include <iostream>

int main(){
  int array[8] = {0}; // static array
  std::vector<int> vec = {0}; // dynamic array
  /*
   * It's important to note that reserve() 
   * does not change the size of the vector; 
   * it only affects the capacity. The actual number of elements 
   * stored in the vector (vec.size()) remains unchanged after reserve(). 
   * However, the reserve() function can prevent reallocation and copying of 
   * elements when adding more elements to the vector if the 
   * current capacity is less than the reserved amount.
    */
  vec.reserve(10); // memory of at leaset 10 is reserve

  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);

  std::cout << "Reserved Vec size: "<< vec.size() << std::endl;
}
