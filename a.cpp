#include <stdio.h>
#include <string.h>
//���ǰ汾21
int *getCharNum(char *filename, int *totalNum);
main(){
    char filename[30];
    char action[10];
    char c[10]="-c";
    char w[10]="-w";
    //totalNum[0]: �ַ���  totalNum[1]: ������
    int totalNum[2] = {0, 0};
	scanf("%s",action);//������� 
	getchar();
    scanf("%s", filename);//�����ļ��� 

    if(getCharNum(filename, totalNum)){
    	
    	if(strcmp(action,c)==0) {
    		printf("�ַ�����  %d\n",totalNum[0]);
		}
        else if(strcmp(action,w)==0){
        	printf("��������  %d\n",totalNum[1]);
		}
    }
	else{
		 printf("Error!\n"); 
	}
    return 0;
}
int *getCharNum(char *filename, int *totalNum){
    FILE *fp;  // ָ���ļ���ָ��
    char buffer[1000];  //���������洢��ȡ����ÿ�е�����
    int bufferLen;  // ��������ʵ�ʴ洢�����ݵĳ���
    int i;  // ��ǰ�����������ĵ�i���ַ�
    char c;  // ��ȡ�����ַ�
    int isLastBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
    int charNum = 0;  // ��ǰ�е��ַ���
    int wordNum = 0; // ��ǰ�еĵ�����

    if( (fp=fopen(filename, "rb")) == NULL ){
        perror(filename);
        return NULL;
    }
    while(fgets(buffer, 1000, fp) != NULL){
        bufferLen = strlen(buffer);
        // ����������������
        for(i=0; i<bufferLen; i++){
            c = buffer[i];
            if( c==' ' || c=='\t'){  // �����ո�
                !isLastBlank && wordNum++;  // ����ϸ��ַ����ǿո���ô��������1
                isLastBlank = 1;
            }else if(c!='\n'&&c!='\r'){  // ���Ի��з�
                charNum++;  // ����Ȳ��ǻ��з�Ҳ���ǿո��ַ�����1
                isLastBlank = 0;
            }
        }

        !isLastBlank && wordNum++;  // ������һ���ַ����ǿո���ô��������1
        isLastBlank = 1;  // ÿ�λ�������Ϊ1

        // һ�н������������ַ������ܵ�����
        totalNum[0] += charNum;  // ���ַ���
        totalNum[1] += wordNum;  // �ܵ�����

        // ���㣬����ͳ����һ��
        charNum = 0;
        wordNum = 0;
    }

    return totalNum;
}
