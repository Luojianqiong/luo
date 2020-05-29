#include <stdio.h>
#include <string.h>
//这是版本21
int *getCharNum(char *filename, int *totalNum);
main(){
    char filename[30];
    char action[10];
    char c[10]="-c";
    char w[10]="-w";
    //totalNum[0]: 字符数  totalNum[1]: 单词数
    int totalNum[2] = {0, 0};
	scanf("%s",action);//输入操作 
	getchar();
    scanf("%s", filename);//输入文件名 

    if(getCharNum(filename, totalNum)){
    	
    	if(strcmp(action,c)==0) {
    		printf("字符数：  %d\n",totalNum[0]);
		}
        else if(strcmp(action,w)==0){
        	printf("单词数：  %d\n",totalNum[1]);
		}
    }
	else{
		 printf("Error!\n"); 
	}
    return 0;
}
int *getCharNum(char *filename, int *totalNum){
    FILE *fp;  // 指向文件的指针
    char buffer[1000];  //缓冲区，存储读取到的每行的内容
    int bufferLen;  // 缓冲区中实际存储的内容的长度
    int i;  // 当前读到缓冲区的第i个字符
    char c;  // 读取到的字符
    int isLastBlank = 0;  // 上个字符是否是空格
    int charNum = 0;  // 当前行的字符数
    int wordNum = 0; // 当前行的单词数

    if( (fp=fopen(filename, "rb")) == NULL ){
        perror(filename);
        return NULL;
    }
    while(fgets(buffer, 1000, fp) != NULL){
        bufferLen = strlen(buffer);
        // 遍历缓冲区的内容
        for(i=0; i<bufferLen; i++){
            c = buffer[i];
            if( c==' ' || c=='\t'){  // 遇到空格
                !isLastBlank && wordNum++;  // 如果上个字符不是空格，那么单词数加1
                isLastBlank = 1;
            }else if(c!='\n'&&c!='\r'){  // 忽略换行符
                charNum++;  // 如果既不是换行符也不是空格，字符数加1
                isLastBlank = 0;
            }
        }

        !isLastBlank && wordNum++;  // 如果最后一个字符不是空格，那么单词数加1
        isLastBlank = 1;  // 每次换行重置为1

        // 一行结束，计算总字符数、总单词数
        totalNum[0] += charNum;  // 总字符数
        totalNum[1] += wordNum;  // 总单词数

        // 置零，重新统计下一行
        charNum = 0;
        wordNum = 0;
    }

    return totalNum;
}
