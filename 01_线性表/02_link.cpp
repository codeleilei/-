/**
	�ļ�˵��������Ĳ���
	���ݽṹ��
		1��һ�������class�������������õ�����������˼�룩
		2�������node �ṹ��
					--------�������ṹ����������������ļ̳�
	
	����������������Ĳ������ǻ�����ͷ��������
		1����ʼ���ࣨ���������٣�
			1��β�巨����������
			2��ͷ�巨����������
			3�����ٺ���
				�ܽ᣺ ͷ�巨����Ҫ���������ָ������¼��ǰ��λ�ã�β�巨��Ҫ
		2��������
			4������Ų���
			5����ֵ����
				�ܽ᣺ ���Һ������������൱��Ҫ ��Ϊ�����޷�ʵ������Ĵ洢 ��
						���������Ҫע��Ļ�����ŵĹ�ϵ ͳһ����ر���Ҫ һ���ô����Ա�1 ��ʼ���߼�������Ų��ң�
		3��ɾ����Ӳ���
			6��ɾ��Ԫ��
			7�����Ԫ��
				�ܽ᣺
		4������
			8)���
			9���ж��Ƿ�Ϊ��
			10����ӡ
				�ܽ᣺

					@author code_cl
					@data: 20/3/22
**/

#include <iostream>
#include <stdio.h>


/********************************************************** 1��Struct Define*******************************************************/
/*true link node*/
typedef struct List_node {
	int data;
	List_node *next;
}List_node;


/*class define link list*/
typedef struct List_l {
	char *name;
	int length;
	List_node * link;       //head point  ����ע�ص���ָ�� ��ʹ��ָ���ʱ��ע�����ռ�ͻ��գ�
}List_l;





/********************************************************** 2��Function Define*******************************************************/
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




/********************************************************** 3��Function Realize*******************************************************/
int Init_Hlink(List_l &list, const char* name) {
	List_node* s; int x;

	list.length = 0;
	list.name = (char *)name;
	list.link = (List_node*)malloc(sizeof(List_node));
	list.link->next = NULL;

	printf("�����������ֵ   ������-1��ʾ������\n");
	std::cin >> x ;
	//scanf("%d",&x);
	while (x != -1) {
		s = (List_node *)malloc(sizeof(List_node));
		s->data = x;
		s->next = list.link->next;

		list.link->next = s;
		list.length++;

		printf("�����������ֵ   ������-1��ʾ������\n");
		std::cin >> x;
	}

	return 0;
}


int Init_Elink(List_l &list, const char* name) {
	List_node *s,*p;  //s ������ʾ�´����Ľ��  p��ʾ��ǰ�����β
	int x;

	list.length = 0;
	list.name = (char *)name;
	list.link = (List_node*)malloc(sizeof(List_node));
	list.link->next = NULL;
	p = list.link;
	printf("�����������ֵ   ������-1��ʾ������\n");
	std::cin >> x;;
	while (x != -1) {
		s = (List_node *)malloc(sizeof(List_node));
		s->data = x;
		s->next = NULL;

		p->next = s;
		p = s;
		list.length++;

		printf("�����������ֵ   ������-1��ʾ������\n");
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

/*��������ǳ���Ҫ*/
List_node *loc_Seek(List_l list, int loc) {
	List_node *s;
	int i = 1;
	if (loc > list.length || loc < 1)
		return NULL;

	s = list.link->next;
	while (s && i < loc) {      //ע������� i<loc ��Ϊs��������ָ����1 i�Ǽ���ʱ�� s���Ѿ�ָ���˼� 
		s = s->next;
		i++;
	}
	return s;

}



int AddElem(List_l &list, int loc, int elem) {
	List_node *s, *p;   //s ָ�������½ڵ���  pָ��������ǰһ�� 
	int i = 1;

	if (loc > list.length || loc < 1)
		return NULL;

	/* Ŀ�ľ���Ҫ�ҵ���Ӧλ�õĽ�����һ����� �������ǿ���ֱ���ð����Һ���*/
	p = loc_Seek(list, loc - 1);

	s = (List_node *)malloc(sizeof(List_node));
	s->data = elem;
	s->next = p->next;
	p->next = s;

	list.length++;
	return 0;
}


int DelElem(List_l &list, int loc) {
	List_node *s, *p;	// s ָ����Ҫɾ���Ľ��  pָ��������ǰһ��
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
		printf("��%d������ֵΪ��%d\n",i,s->data);
		s = s->next;
		i++;
	}
	return 0;
}


int Getlength(List_l list) {
	return list.length;
}

/********************************************************** 4��Function Main*******************************************************/

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
	printf("����������Ҫ���ҵ�λ��\n");
	std::cin >> x;
	s = loc_Seek(list, x);
	printf("��%dλ�õ�ֵΪ�� %d\n", x,s->data);

	printf("����������Ҫ����Ԫ��\n");
	std::cin >> y;
	printf("ֵΪ��%d�� �� %d λ�õ�\n", y, Elem_Seek(list, 10));


}