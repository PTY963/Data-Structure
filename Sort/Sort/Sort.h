#pragma once
#include<stdio.h>
//插入排序
//1、直接插入排序
//时间复杂度 O(N^2) 最坏 - 逆序
//最好： O(N) - 接近顺序排序
void InsertSort(int* a, int n);
//希尔排序
void ShellSort(int* a, int n);
//选择排序
void SelectSort(int* a, int n);
//堆排序
void HeapSort(int* a, int n);

//交换排序
//1、冒泡排序
void BubbleSort(int* a, int n);

void Swap(int* px, int* py);
void Print(int* a, int n);
