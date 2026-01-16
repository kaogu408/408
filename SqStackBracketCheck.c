/*
【C语言 栈实现括号匹配】 根节点
├─ 一、核心依赖：栈的特性
│  └─ 先进后出(FILO)，完美契合括号嵌套/并列的匹配规则
├─ 二、括号匹配核心规则（3条）
│  ├─ 遇左括号 → 直接入栈
│  ├─ 遇右括号 → 栈空则失败；栈非空则出栈匹配成对性
│  └─ 遍历结束 → 栈空=成功，栈非空=失败
├─ 三、栈的实现（顺序栈/数组实现，最易理解）
│  ├─ 1. 栈的结构体定义 (struct Stack)
│  │  ├─ char data[] ：存储括号的字符数组
│  │  ├─ int top     ：栈顶指针，初始化=-1（top=-1代表空栈）
│  │  └─ int maxSize ：栈的最大容量
│  ├─ 2. 栈的基础操作函数（6个）
│  │  ├─ initStack()  ：初始化栈，初始化top=-1
│  │  ├─ isEmpty()    ：判断栈是否为空 (top == -1)
│  │  ├─ isFull()     ：判断栈是否为满 (top == maxSize-1)
│  │  ├─ push()       ：入栈操作（判满后入栈，top++）
│  │  ├─ pop()        ：出栈操作（判空后出栈，top--）
│  │  └─ destroyStack()：销毁栈（重置top=-1，释放资源）
├─ 四、括号匹配核心业务函数
│  ├─ isPair() ：辅助函数，判断左右括号是否成对
│  └─ matchBrackets()：主匹配函数，实现完整匹配逻辑
└─ 五、测试模块
    ├─ 定义多个测试用例（匹配/不匹配全覆盖）
    ├─ 调用匹配函数，输出结果
    └─ 销毁栈，释放资源
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 10

typedef struct{
    char data[MAXSIZE];
    int top;
}SqStack;

void initSqStack(SqStack *S){
    S->top = -1; // 栈顶指针置为-1,表示空栈
}

bool isFull(SqStack *S){
    return S->top == MAXSIZE - 1;
}

bool isEmpty(SqStack *S){
    return S->top == -1;
}

bool push(SqStack *S, char e){
    if(isFull(S))// 判断是否满栈
        return false;
    S->data[++S->top] = e;
    return true;
}

bool pop(SqStack *S, char *e){
    if(isEmpty(S))
        return false;
    *e = S->data[S->top--];
    return true;
}

bool matchBrackets(char *str){
    SqStack S;
    int len = strlen(str);
    initSqStack(&S);

    // 遍历字符串
    for(int i = 0; i < len; i++){
        char ch = str[i];
        
        if(ch == '(' || ch == '[' || ch == '{') { // 情况1:左括号，直接入栈
            if(push(&S, ch) == false)
                return false;
        } else if (ch == ')' || ch == ']' || ch == '}') { // 情况2:右括号，进行匹配
            char l_bracket;
            if(pop(&S, &l_bracket) == false)
                return false;
            if(ch == ')' && l_bracket != '(' ||
               ch == ']' && l_bracket != '[' ||
               ch == '}' && l_bracket != '{') {
                return false;
            }
        } else { //情况3 非括号，直接跳过
            continue;
        }
    }
    return isEmpty(&S); // 遍历完成后：栈空=匹配成功，栈非空=有剩余左括号未匹配
}

int main() {
    char test1[] = "()[]{}";    // 正常匹配 - 成功
    char test2[] = "{[()]}";    // 嵌套匹配 - 成功
    char test3[] = "(]";        // 交叉不匹配 - 失败
    char test4[] = "([)]";      // 交叉不匹配 - 失败
    char test5[] = "{";         // 只有左括号 - 失败
    char test6[] = "}";         // 只有右括号 - 失败
    char test7[] = "";          // 空字符串 - 成功
    char test8[] = "{[a+b]*c - d}"; // 含其他字符的匹配 - 成功

    // 调用匹配函数并输出结果
    printf("字符串 \"%s\" 的括号匹配结果：%s\n", test1, matchBrackets(test1) ? "成功" : "失败");
    printf("字符串 \"%s\" 的括号匹配结果：%s\n", test2, matchBrackets(test2) ? "成功" : "失败");
    printf("字符串 \"%s\" 的括号匹配结果：%s\n", test3, matchBrackets(test3) ? "成功" : "失败");
    printf("字符串 \"%s\" 的括号匹配结果：%s\n", test4, matchBrackets(test4) ? "成功" : "失败");
    printf("字符串 \"%s\" 的括号匹配结果：%s\n", test5, matchBrackets(test5) ? "成功" : "失败");
    printf("字符串 \"%s\" 的括号匹配结果：%s\n", test6, matchBrackets(test6) ? "成功" : "失败");
    printf("字符串 \"%s\" 的括号匹配结果：%s\n", test7, matchBrackets(test7) ? "成功" : "失败");
    printf("字符串 \"%s\" 的括号匹配结果：%s\n", test8, matchBrackets(test8) ? "成功" : "失败");

    return 0;
}

