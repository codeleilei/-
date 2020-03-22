/******
	�ļ�˵������ջ�Ĳ���
	
	���ݽṹ��
		1������ջ���struct 
		2��������ջStack struct

	����������
		1����ʼ��ջ
		2����ջ����
		3����ջ����
		4����ջ��ֵ
			
		�ܽ᣺ topջ��ָ���ڿյ�ʱ������Ĭ��Ϊ-1 �����Ӿͺ�c���������0 ��ʼ���Ǻ���
				top=0 ��ʱ������ñ�ʾ����ĵ�һ��Ԫ�� a[0] ���±�0 
				�������������top ��Զָ��ջ��Ԫ�ص�λ�ã����λ������ֵ�ģ�

				@author��code_cl
				@data��20/3/20

******/
#include <iostream>
#include <stdio.h>


#define MAXSIZE 100

/**********************************1��Struct Define******************************************************/
typedef struct Stack {
	int *data;
	int top;
}Stack;

typedef struct Stack_De {
	char * name;
	int maxsize;
	Stack stack;
}Stack_De;



/**********************************2��Function Define******************************************************/

int Init_Stack(Stack_De &s, int maxsize);
int Push_Stack(Stack_De &s, int elem);
int Pop_Stack(Stack_De &s);
int Read_Stack(Stack_De s);
void Print(Stack_De s);




/**********************************3��Function Realize******************************************************/
int Init_Stack(Stack_De &s,int maxsize) {
	s.stack.top = -1;
	s.maxsize = maxsize;
	s.stack.data = (int *)malloc(sizeof(int)*maxsize);
	if (s.stack.data)
		return 0;
	else
		return -1;
}


int Push_Stack(Stack_De &s, int elem) {
	if (s.stack.top >= s.maxsize - 1)
		return -1;
	s.stack.data[++s.stack.top] = elem;
	return 0;
}


int Pop_Stack(Stack_De &s) {
	int temp;
	if (s.stack.top == -1)
		return -1;
	temp = s.stack.data[s.stack.top--];
	return temp;
}

/*just read not have to sub the top point*/
int Read_Stack(Stack_De s) {
	int temp;
	if (s.stack.top == -1)
		return -1;
	temp = s.stack.data[s.stack.top];
	return temp;
}

void Print(Stack_De s) {
	if (s.stack.top == -1)
		printf("Stack is null\n");
	while (s.stack.top != -1) {
		printf("�� %d λ�õ�ֵΪ��%d\n", s.stack.top+1,s.stack.data[s.stack.top]);
		s.stack.top--;
	}

}



int main() {
	Stack_De stack;
	Init_Stack(stack, MAXSIZE);

	/***1��add test***/
	int x,i;
	for (i = 0; i < 2; i++) {
		printf("��������Ҫ��ջ��ֵ��\n");
		std::cin >> x;
		Push_Stack(stack, x);
	}
	Print(stack);


	/**2��Read test */
	printf("ջ��Ԫ��Ϊ��%d\n",Read_Stack(stack));

	/**3��del test**/
	Pop_Stack(stack);
	Print(stack);
	
	return 0;


}




