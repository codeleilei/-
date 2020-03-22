/******
	文件说明：堆栈的操作
	
	数据结构：
		1、代表栈类的struct 
		2、真正的栈Stack struct

	操作函数：
		1、初始化栈
		2、出栈函数
		3、进栈函数
		4、读栈顶值
			
		总结： top栈顶指针在空的时候我们默认为-1 这样子就和c语言数组从0 开始就吻合了
				top=0 的时候就正好表示数组的第一个元素 a[0] 的下标0 
				所以我们这里的top 永远指向栈顶元素的位置（这个位置是有值的）

				@author：code_cl
				@data：20/3/20

******/
#include <iostream>
#include <stdio.h>


#define MAXSIZE 100

/**********************************1、Struct Define******************************************************/
typedef struct Stack {
	int *data;
	int top;
}Stack;

typedef struct Stack_De {
	char * name;
	int maxsize;
	Stack stack;
}Stack_De;



/**********************************2、Function Define******************************************************/

int Init_Stack(Stack_De &s, int maxsize);
int Push_Stack(Stack_De &s, int elem);
int Pop_Stack(Stack_De &s);
int Read_Stack(Stack_De s);
void Print(Stack_De s);




/**********************************3、Function Realize******************************************************/
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
		printf("第 %d 位置的值为：%d\n", s.stack.top+1,s.stack.data[s.stack.top]);
		s.stack.top--;
	}

}



int main() {
	Stack_De stack;
	Init_Stack(stack, MAXSIZE);

	/***1、add test***/
	int x,i;
	for (i = 0; i < 2; i++) {
		printf("请输入你要进栈的值：\n");
		std::cin >> x;
		Push_Stack(stack, x);
	}
	Print(stack);


	/**2、Read test */
	printf("栈顶元素为：%d\n",Read_Stack(stack));

	/**3、del test**/
	Pop_Stack(stack);
	Print(stack);
	
	return 0;


}




