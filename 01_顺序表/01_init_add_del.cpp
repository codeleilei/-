// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>


#define Maxsize 100

typedef struct Line {
	char name[10];
	int age;
	

}Lnode;


/*初始化*/
bool Init_Array(Lnode *&L,int size) {
	bool ret;
	ret = (L = (Lnode*)malloc(sizeof(Lnode)*size)) ? true : false;
	if (!ret)
		return false;

	
	for (int i = 0; i < size; i++) {
		printf("name:");
		std::cin >> L[i].name;

		printf("age:");
		std::cin >> L[i].age;
	}

	return true;

}

/************插入操作**************/
/********重点是从数组末尾找起+++++*/
bool Insert(Lnode *&L, int &length, int palce, Lnode e) {
	if (palce < 1 || palce > length + 1)
		return false;
	if (length >= Maxsize)
		return false;
	for (int j = length; j >= palce; j--)
		L[j] = L[j - 1];
	L[palce - 1] = e;
	length++;
	return true;
}

/*删除操作*/
bool Dele(Lnode *&L, int &length, int palce) {
	if (palce < 1 || palce > length )
		return false;


	for (int j = palce; j < length ; j++)
		L[j-1] = L[j];
	
	length--;
	return true;
}


/*添加一个节点*/
Lnode Add_node(const char* name,int age) {
	Lnode e;
	printf("请输入name:");
	std::cin >> e.name;

	printf("请输入age:");
	std::cin >> e.age;

	return e;

}



/*打印*/
void  Print(Lnode *L,int size) {

	for (int i = 0; i < size; i++) {
		printf("name:%s   age:%d\n",L[i].name, L[i].age);
	
	}

}



int main()
{
	Lnode* L=NULL;
	int length = 3;
	/*初始化*/
	printf("=====================================\n");
	printf("================初始化==============\n");
	printf("=====================================\n");
	Init_Array(L, length);
	Print(L, length);


	/*插入操作*/
	printf("=====================================\n");
	printf("================插入操作==============\n");
	printf("=====================================\n");
	
	Lnode e = Add_node("chen", 18);
	Insert(L, length, 1, e);
	Print(L, length);

	/*删除操作*/
	printf("=====================================\n");
	printf("================删除操作==============\n");
	printf("=====================================\n");

	printf("请输入需要删除的位置(当前长度%d):",length);
	int i;
	std::cin >> i;
	Dele(L, length, i);
	Print(L, length);

	//Print(L, length);
	/*查找*/
	return 0;


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
