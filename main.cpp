//
// Created by Xiaopi Zhu on 2022/2/25.
//
#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::cout << "Enter rows of matrix A and B" << std::endl;
    int rows;
    std::cin >> rows;
    std::cout << "Enter columns of matrix A and B" << std::endl;
    int columns;
    std::cin >> columns;

    std::vector<std::vector<int>> my_matrix(rows);

    //逐个压入数据
//    my_matrix[0].push_back(10);
//    my_matrix[0].push_back(20);
    for(int i=0; i<rows; i++){
        for(int ii=0; ii<columns; ii++){
            std::cout << "enter matrix elements" << std::endl;
            int elements;
            std::cin >> elements;
            my_matrix[i].push_back(elements);
        }
    }
//    //每一行的的个数是可变的
//    my_matrix[1].push_back(30);
//    my_matrix[1].push_back(40);

    //输出二维矩阵
    std::vector <int>::iterator Iter;  //define iterator

    std::cout << "二维矩阵的元素是：" << std::endl;
    for(int i=0; i<2; i++){
        std::cout << "Total " << my_matrix.size() << " elements" << std::endl;
        for(Iter = my_matrix[i].begin(); Iter != my_matrix[i].end(); Iter++){
            std::cout << *Iter << " ";
        }
        std::cout << std::endl;
    }



    std::cout << "fair enough" << std::endl;
    return 0;
}

