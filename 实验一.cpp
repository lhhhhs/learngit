#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getChar(FILE *fp){
	char ch;
	int number=0;
	while((ch=fgetc(fp))!=EOF){
		if((ch!='\n')&&(ch!=' ')&&(ch!='\t')){
			number++;
		}
	}
	rewind(fp);
	return number;
}
int getWord(FILE *fp){
	int flag=0;
	int number=0;
	char ch;
	while(feof(fp)==0)
    {
        ch = fgetc(fp);
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') 
           ||(ch >= '0' && ch <= '9')){
             flag = 0;
        }
        else if(flag == 0 && (ch != '-' && ch != '/'&& ch != '\''))
        {
            number++;
            flag = 1;
        }
    }
    rewind(fp);
    return number;
}

int main(int argc,char*argv[]){
	FILE *fp;
	int number;
	char string;

    if(argc==3){
		fp = fopen(argv[2],"r");
		if(fp == NULL){
			printf("错误，无法打开%s\n",argv[2]);
			exit(1);
		} 
		    if(!strcmp(argv[1],"-c")){//统计字符数 
		        number = getChar(fp);
		     	printf("字符数为%d\n",number);
		    }
		
		    else if(!strcmp(argv[1],"-w")){//统计单词数 
			    number = getWord(fp);
			    printf("单词数为%d\n",number); 
		   }
	}
	else {
		rintf("字符输入错误\n"); 
	}	
}
