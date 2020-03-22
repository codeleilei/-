/**
	文件描述:This cpp is description of sequence list
	数据结构：
		1、一个顺序表的class对象 记录了一个顺序表的基本信息
		2、顺序表 ： 这里用一个数组表示
				----此文件将顺序表作为一个List_s对象（c中用结构体表示）
				----对象中包含： name、length、和 顺序表List 
				-----我们主要做的操作是对对象中的List 
	
	函数操作（对顺序表对象中的顺序表List操作）：
			1、初始化和销毁
			2、查找：按值和按位查找
			3、删除和添加
			4、其他的操作
				1）打印
				2）求表长
				3）判断是否为空

							@author: code_cl  
							@data: 20/3/22
**/


#include <iostream>
#include <stdio.h>
/**********1、struct ****************/
/*这里将一个顺序表作为一个对象 */
typedef struct List_Sq {
	char * name;
	int length;
	int *List;
	int maxsize;
} List_s;

/************2、function declaration ********/
/****init*******/
int Init_List(List_s &list,const char * name,int size);
void Destr0y_List(List_s &list);


/****seek*****/
int LocateElem(List_s list, int i);
int Getelem(List_s list,int elem);

/****delete and addd */
int DelElem(List_s &list, int loc);     //according location to del
int AddElem(List_s &list, int loc, int elem);

/****others*******/
int Getlength(List_s list);
void Print(List_s list);
int IsEmpty(List_s list);



/**********3、function realize****************/
int Init_List(List_s &list, const char * name,int size) {
	list.name =(char *) name;
	list.length = 0;
	list.maxsize = size;
	list.List = (int *)malloc(sizeof(int)*size);
	return 0;
}


void Destr0y_List(List_s &list) {
	free(list.List);
}

/*注意这边传入的 i 用的是顺序表的计数概念（就是从一开始的），而c语言的数组是从0开始的  注意区分*/
int LocateElem(List_s list,int i) {
	int j = 0;
	if (i < 1  || i > list.length)
		return -1;
	for (; j < list.length; j++) {
		if (j == i - 1)
			return list.List[j];
	}
	return -1;
}


int Getelem(List_s list,int elem) {
	int j = 0;
	for(j=1; j < list.length; j++) {
		if (list.List[j] == elem)
			return  j + 1;
	}
	return -1;
}



int DelElem(List_s &list,int loc) {
	int j = 0;
	if (loc < 0 || loc > list.length )
		return -1;
	int e = list.List[loc - 1];  //to  store the del value
	for (j = loc - 1; j < list.length; j++)
		list.List[j] = list.List[j + 1];
	list.length -= 1;
	return 0;
}

int AddElem(List_s &list,int loc ,int elem) {
	int j = 0;
	if (loc < 0 || loc > list.length + 1)
		return -1;
	if (loc > list.maxsize)
		return -1;
	for (j = list.length; j >= loc ; j--)
		list.List[j] = list.List[j-1];
	list.List[loc - 1] = elem;
	list.length ++;
	return 0;
}

int Getlength(List_s list) {
	return list.length;

}


void Print(List_s list) {
	int i = 0;
	for (; i < list.length; i++)
		printf(" List[%d]= %d\n",i,list.List[i]);
}

int IsEmpty(List_s list) {
	if (list.length == 0)
		return 0;
	return -1;
}



int main() {
	List_s list;
	Init_List(list,"Chenl",100);
	if (!IsEmpty(list))
		printf("list is null\n");
	/*add test*/
	AddElem(list, 1, 10);
	AddElem(list, 2, 15);
	Print(list);

	/*del test*/
	DelElem(list, 1);
	Print(list);

	/*location seek test*/
	AddElem(list, 1, 25);
	AddElem(list, 3, 20);
	Getelem(list, 15);
	LocateElem(list, 3);
	printf("值为15 的位置： %d ，  第3个位置的值为： %d\n", Getelem(list, 15), LocateElem(list, 3));

	Print(list);
}


