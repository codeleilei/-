/**
	文件说明：链表的操作
	数据结构：
		1、一个链表的class对象（这里对象采用的是面向对象的思想）
		2、链表的node 结构体
					--------这两个结构体就类似于面向对象的继承
	
	操作函数：（这里的操作都是基于有头结点的链表）
		1、初始化类（创建、销毁）
			1）尾插法创建单链表
			2）头插法创建单链表
			3）销毁函数
				总结： 头插法不需要另外的链表指针来记录当前的位置，尾插法需要
		2、查找类
			4）按序号查找
			5）按值查找
				总结： 查找函数对于链表相当重要 因为链表无法实现随机的存储 ，
						查找里边需要注意的还是序号的关系 统一序号特别重要 一般用从线性表1 开始的逻辑（按序号查找）
		3、删除添加操作
			6）删除元素
			7）添加元素
				总结：
		4、其他
			8)求表长
			9）判断是否为空
			10）打印
				总结：

					@author code_cl
					@data: 20/3/22
**/

#include <iostream>
#include <stdio.h>


/********************************************************** 1、Struct Define*******************************************************/
/*true link node*/
typedef struct List_node {
	int data;
	List_node *next;
}List_node;


/*class define link list*/
typedef struct List_l {
	char *name;
	int length;
	List_node * link;       //head point  链表注重的是指针 （使用指针的时候注意分配空间和回收）
}List_l;





/********************************************************** 2、Function Define*******************************************************/
int Init_Hlink(List_l &list, const char* name);
int Init_Elink(List_l &list, const char* name);
void Destroy(List_l &list);

int Elem_Seek(List_l list, int elem);
List_node *loc_Seek(List_l list,int loc);

int AddElem(List_l &list, int loc, int elem);
int DelElem(List_l &list, int loc);

int IsEmpty(List_l list);
int Print(List_l list);
int Getlength(List_l list);




/********************************************************** 3、Function Realize*******************************************************/
int Init_Hlink(List_l &list, const char* name) {
	List_node* s; int x;

	list.length = 0;
	list.name = (char *)name;
	list.link = (List_node*)malloc(sizeof(List_node));
	list.link->next = NULL;

	printf("请输入链表的值   （输入-1表示结束）\n");
	std::cin >> x ;
	//scanf("%d",&x);
	while (x != -1) {
		s = (List_node *)malloc(sizeof(List_node));
		s->data = x;
		s->next = list.link->next;

		list.link->next = s;
		list.length++;

		printf("请输入链表的值   （输入-1表示结束）\n");
		std::cin >> x;
	}

	return 0;
}


int Init_Elink(List_l &list, const char* name) {
	List_node *s,*p;  //s 用来表示新创建的结点  p表示当前链表的尾
	int x;

	list.length = 0;
	list.name = (char *)name;
	list.link = (List_node*)malloc(sizeof(List_node));
	list.link->next = NULL;
	p = list.link;
	printf("请输入链表的值   （输入-1表示结束）\n");
	std::cin >> x;;
	while (x != -1) {
		s = (List_node *)malloc(sizeof(List_node));
		s->data = x;
		s->next = NULL;

		p->next = s;
		p = s;
		list.length++;

		printf("请输入链表的值   （输入-1表示结束）\n");
		std::cin >> x;;
	}

	return 0;

}

int Elem_Seek(List_l list, int elem) {
	List_node *s;
	int j=1;
	s = list.link->next;
	while (s != NULL && s->data != elem) {
		s = s->next;
		j++;

	}
	
	return j;
}

/*这个函数非常重要*/
List_node *loc_Seek(List_l list, int loc) {
	List_node *s;
	int i = 1;
	if (loc > list.length || loc < 1)
		return NULL;

	s = list.link->next;
	while (s && i < loc) {      //注意这里的 i<loc 因为s本来就是指向了1 i是几的时候 s就已经指向了几 
		s = s->next;
		i++;
	}
	return s;

}



int AddElem(List_l &list, int loc, int elem) {
	List_node *s, *p;   //s 指向插入的新节点结点  p指向插入结点的前一个 
	int i = 1;

	if (loc > list.length || loc < 1)
		return NULL;

	/* 目的就是要找到对应位置的结点的上一个结点 所以我们可以直接用按查找函数*/
	p = loc_Seek(list, loc - 1);

	s = (List_node *)malloc(sizeof(List_node));
	s->data = elem;
	s->next = p->next;
	p->next = s;

	list.length++;
	return 0;
}


int DelElem(List_l &list, int loc) {
	List_node *s, *p;	// s 指向需要删除的结点  p指向插入结点的前一个
	p= loc_Seek(list, loc - 1);
	s = p->next;
	p->next = s->next;
	list.length--;
	return 0;
}

int IsEmpty(List_l list) {
	if (list.link->next == NULL)
		return 0;
	return 1;
}


int Print(List_l list) {
	List_node *s;
	int i = 1;
	s = list.link->next;
	while (s){
		printf("第%d个结点的值为：%d\n",i,s->data);
		s = s->next;
		i++;
	}
	return 0;
}


int Getlength(List_l list) {
	return list.length;
}

/********************************************************** 4、Function Main*******************************************************/

int main() {
	List_l list;
	//Init_Hlink(list,"Chenl");
	Init_Elink(list, "Chenl");
	Print(list);

	/*Add test*/
	printf("*************************Add test****************************\n");
	AddElem(list, 3, 10);
	Print(list);

	/*Del test*/
	printf("*************************Del test****************************\n");
	DelElem(list, 2);
	Print(list);

	/*Seek test*/
	printf("*************************Seek test****************************\n");
	int x,y;
	List_node *s;
	printf("请输入您需要查找的位置\n");
	std::cin >> x;
	s = loc_Seek(list, x);
	printf("第%d位置的值为： %d\n", x,s->data);

	printf("请输入您需要查找元素\n");
	std::cin >> y;
	printf("值为：%d在 第 %d 位置的\n", y, Elem_Seek(list, 10));


}