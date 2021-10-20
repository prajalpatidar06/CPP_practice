#include<iostream>
#include<string>
#include<fstream>
#include<chrono>
#include<filesystem>
#include<vector>
#include <time.h>
using namespace std;

void bubbleSort(int B[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        int flag = 0;
        for(int j = 0; j<n-1-i; j++)
        {
            if(B[j]>B[j+1])
            {
            swap(B[j],B[j+1]);
            flag = 1;
            }
        }
            if(flag == 0)
            break;
    }
}

int main(){
    ifstream infile;
    infile.open("Sample.txt");
    if(!infile)
        cout<<"File cant be open";

    string path = "Sample.txt";
    int sz= 0;
    clock_t tStart = clock();
    vector<int>A;
    int inp;
    ifstream in("Sample.txt");
    while (!in.eof()){
        in>>inp;
        A.push_back(inp);
        sz++;
    }
    auto begin = std::chrono::high_resolution_clock::now();
    int *a = new int[sz];
    int k = 0;
    for(int i: A)a[k++] = i;
    bubbleSort(a,sz);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.8f seconds.\n", elapsed.count() * 1e-9);

//      for(int i = 0; i <sz; i++)
//    {
//        cout<<a[i] <<" ";
//    }
    return 0;
}