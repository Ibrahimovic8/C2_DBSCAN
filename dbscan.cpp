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
	ClusterAnalysis myClusterAnalysis;                        //聚类算法对象声明
	cout<<"loading the file..."<<endl;
	myClusterAnalysis.Init("data\\agg.txt", 0.04,15);        //算法初始化操作，指定半径为15，领域内最小数据点个数为3，（在程序中已指定数据维度为2）
	cout<<"clusting the data..."<<endl;
    CYW_TIMER build_timer;
    build_timer.start_my_timer();
//	start = clock();
	myClusterAnalysis.DoDBSCANRecursive();                    //执行聚类算法
	build_timer.stop_my_timer();
 //   finish = clock();
//    cout << endl << finish - start << "/" << CLOCKS_PER_SEC << "(s)" << endl;
    printf("the running time is %f\n",build_timer.get_my_timer());
	myClusterAnalysis.WriteToFile("data\\result.txt");//写执行后的结果写入文件
	system("pause");    //显示结果
	return 0;            //返回
}
