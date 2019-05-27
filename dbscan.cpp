/*
 *
 * Copyright (C) 2017-  Yewang Chen<ywchen@hqu.edu.cn;nalandoo@gmail.com;1611414017@hqu.edu.cn>
 * License: GPL v1
 * This software may be modified and distributed under the terms
 * of license.
 *
 */
#include "ClusterAnalysis.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "cyw_timer.h"

using namespace std;

int main()
{
//	clock_t start, finish;
	ClusterAnalysis myClusterAnalysis;                        //�����㷨��������
	cout<<"loading the file..."<<endl;
	myClusterAnalysis.Init("data\\agg.txt", 0.04,15);        //�㷨��ʼ��������ָ���뾶Ϊ15����������С���ݵ����Ϊ3�����ڳ�������ָ������ά��Ϊ2��
	cout<<"clusting the data..."<<endl;
    CYW_TIMER build_timer;
    build_timer.start_my_timer();
//	start = clock();
	myClusterAnalysis.DoDBSCANRecursive();                    //ִ�о����㷨
	build_timer.stop_my_timer();
 //   finish = clock();
//    cout << endl << finish - start << "/" << CLOCKS_PER_SEC << "(s)" << endl;
    printf("the running time is %f\n",build_timer.get_my_timer());
	myClusterAnalysis.WriteToFile("data\\result.txt");//дִ�к�Ľ��д���ļ�
	system("pause");    //��ʾ���
	return 0;            //����
}
