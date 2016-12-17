//
//  main.cpp
//  array
//
//  Created by Filip Peterek on 12/12/2016.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#include <iostream>
#include <vector>
#include "array.hpp"


int main(int argc, const char * argv[]) {
    
    array<int> arr;
    array<int> arr2;
    int x[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int y[] = { 20, 21, 22, 23, 24 };
    
    
    for (int & i : x) {
        arr.emplace_back(i);
    }
    
    for (int & i : y) {
        arr2.emplace_back(i);
    }
    
    std::cout << arr << std::endl;
    
    arr.insert(3, 10);
    
    std::cout << arr << std::endl;
    
    arr.push(0);
    arr.pop();
    arr += arr2;
    arr.remove(6);
    
    std::cout << std::string("Element at arr[1] ") << arr[1] << std::endl;
    
    std::cout << arr << std::endl;
    
    array<int> arr3;
    int z[] = { 100, 200, 300 };
    for (int & i : z) {
        arr3.emplace_back(i);
    }
    
    auto arr4 = arr3 + arr2;
    std::cout << std::string("arr3 + arr2 = \n") << arr4 << arr4.length() << std::endl;
    
    std::cout << (arr4 == (arr3 + arr2)) << std::endl;
    std::cout << (arr == arr2) << std::endl;
    
}
