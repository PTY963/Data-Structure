#pragma once
#include<stdio.h>
//��������
//1��ֱ�Ӳ�������
//ʱ�临�Ӷ� O(N^2) � - ����
//��ã� O(N) - �ӽ�˳������
void InsertSort(int* a, int n);
//ϣ������
void ShellSort(int* a, int n);
//ѡ������
void SelectSort(int* a, int n);
//������
void HeapSort(int* a, int n);

//��������
//1��ð������
void BubbleSort(int* a, int n);

void Swap(int* px, int* py);
void Print(int* a, int n);
