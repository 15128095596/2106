#include<stdio.h>
#include<string.h>
#include <stdlib.h>
/*声明变量*/
int num;
char fuhao[5];
int max;
int kuohao;
int doub;
int fil;
int i=0;
int kh=0;/*三位数括号的位置*/
int kh2=0;/*四位数括号的位置前*/
int kh1=0;/*四位数括号的个数*/
int kh3=0;/*四位数括号的位置后*/
/*声明函数*/
char YUN(char fuhao[5],int i);
int zs(int max);
double dec(int max);
void KX(int num,char fuhao[5]);
int KHQ(int n,int con,char b[],int kh,int kh1,int kh2,int kh3,FILE *fp);
void KHH(int n,int con,char b[],int kh,int kh1,int kh2,int kh3,FILE *fp);
int main(){
	printf("请输入题目数量：");
	scanf("%d",&num);
	for(;;){
		if(num<=0){ 
			printf("\n请输入正确的数量！\n请重新输入：");
			scanf("%d",&num);
		}else{
			break;
		}
	}
	printf("请输入运算符（例：+-*/，回车结束）：");
	scanf("%s",fuhao);
	i=strlen(fuhao);
	for(;;){
		int k;
		for(k=0;k<i;k++){
			if(fuhao[k]!='+' && fuhao[k]!='-' && fuhao[k]!='*' && fuhao[k]!='/'){
				break;
			}
		}
		if(k>=i) break;
		printf("\n请按照要求输入运算符：");
		scanf("%s",fuhao);
		i=strlen(fuhao);
	}
	printf("请输入最大值（大于0的整数）：");
	scanf("%d",&max);
	for(;;){
		if(max<1){
			printf("\n请按照要求输入最大值：");
			scanf("%d",&max);
		}else{
			break;
		}
	}
	printf("请选择是否有括号（1 是，2 否）：");
	scanf("%d",&kuohao);
	for(;;){
		if(kuohao!=1 && kuohao!=2){
			printf("\n请选择1或2:");
			scanf("%d",&kuohao);
		}else{
			break;
		}
	}
	printf("请选择是否有小数（1 是，2否）：");
	scanf("%d",&doub);
	for(;;){
		if(doub!=1 && doub!=2){
			printf("\n请选择1或2:");
			scanf("%d",&doub);
		}else{
			break;
		}
	}
	printf("请选择是否文件输出（1 是，2否）：");
	scanf("%d",&fil);
	for(;;){
		if(fil!=1 && fil!=2){
			printf("\n请选择1或2:");
			scanf("%d",&fil);
		}else{
			break;
		}
	}
	printf("\n题目为：\n");
	/*有无括号，有无小数出题*/
	KX(num,fuhao);	
	return 0;
}
/*生成随机运算符*/
char YUN(char fuhao[5],int i){
	char ch;
	int four;
	four=rand() % i;
	switch(four){
		case 0:ch = fuhao[0]; break;
		case 1:ch = fuhao[1]; break;
		case 2:ch = fuhao[2]; break;
		case 3:ch = fuhao[3]; break;
	}
	return ch;
}
/*生成随机整数*/
int zs(int max){
	int ct;
	ct=rand()%max + 1;
	return ct;

}
/*生成随机小数*/
double dec(int max){
	double mal;
	int nt;
	for (;;)
	{
		nt = rand() % 1000 + 1;
		mal = nt * 0.1;
		if (mal < max)
		{
			break;
		}
	}
	return mal;
}

/*有无括号，有无小数出题*/
void KX(int num,char fuhao[5]){
	FILE *fp;
	if(fil==1){
		fp=fopen("ex.txt","a");
	}
	int con,j,k,m,n;
	int a1[5];
	double a2[5];
	char b[5];
	double sum=0;
	for(k=0;k<num;k++){
		con=rand()%3+2;
		for(j=0;j<con;j++){
			/*判断是否有小数，a1为整数，a2为小数*/
			if(doub==1) a2[j]=dec(max);
			else a1[j]=zs(max);
		}
		for(m=0;m<(con-1);m++){
			b[m]=YUN(fuhao,i);
		}
		b[m]='=';
		kh2=rand()%2;
		kh1=rand()%2+1;
		kh3=rand()%2+1;
		if(fil==2){
			for(n=0;n<con;n++){
				if(kuohao==1){
					kh=KHQ(n,con,b,kh,kh1,kh2,kh3,fp);
				}
				/*判断是否有小数，a1为整数，a2为小数*/
				if(doub==1) printf("%.2lf",a2[n]);
				else printf("%d",a1[n]);
				if(kuohao==1){
					KHH(n,con,b,kh,kh1,kh2,kh3,fp);
				}
				printf("%c",b[n]);
			}
			printf("\n");
		}else{
			for(n=0;n<con;n++){
				/*判断是否有括号*/
				if(kuohao==1){/*括号前半部分*/
					kh=KHQ(n,con,b,kh,kh1,kh2,kh3,fp);
				}
				/*判断是否有小数，a1为整数，a2为小数*/
				if(doub==1) fprintf(fp,"%.2lf",a2[n]);
				else fprintf(fp,"%d",a1[n]);
				if(kuohao==1){/*括号后半部分*/
					KHH(n,con,b,kh,kh1,kh2,kh3,fp);
				}
				fprintf(fp,"%c",b[n]);
			}
			fputs("\n",fp);
		}
	}
	if(fil==1){
		fclose(fp);
	}
}
/*输出括号前半部分*/
int KHQ(int n,int con,char b[],int kh,int kh1,int kh2,int kh3,FILE *fp){
	if(con==3){
		if((b[1]=='*' || b[1]=='/') && (b[0]=='+' || b[0]=='-') && n==0){
			if(fil==1) fputs("(",fp);
			else printf("(");
			kh=1;
		}
		else if((b[1]=='+' || b[1]=='-' || b[1]=='*' || b[1]=='/') && n==1 && kh!=1){
			if(fil==1) fputs("(",fp);
			else printf("(");
			kh=2;
		}
	}
	else if(con==4){
		if(n==kh2){
			for(int s=0;s<kh1;s++){
				if(fil==1) fputs("(",fp);
				else printf("(");
			}
		}
	}
	return kh;
}
/*输出括号后半部分*/
void KHH(int n,int con,char b[],int kh,int kh1,int kh2,int kh3,FILE *fp){
	if(con==3){/*三位数的加减乘除*/
		if(kh==1 && n==1){/*前两个数括起来*/
			if(fil==1) fputs(")",fp);
			else printf(")");
			kh=0;
		}
		else if(kh==2 && n==2){/*后两个数括起来*/
			if(fil==1) fputs(")",fp);
			else printf(")");
			kh=0;
		}
	}
	else if(con==4){
		if(kh2==0 && kh1==1 && n==kh3){
			if(fil==1) fputs(")",fp);
			else printf(")");
		} 
		else if(kh2==0 && kh1==2 && (n==1 || n==2)){
			if(fil==1) fputs(")",fp);
			else printf(")");
		}
		else if(kh2==1 && kh1==1 && n==kh3+1){
			if(fil==1) fputs(")",fp);
			else printf(")");
		} 
		else if(kh2==1 && kh1==2 && (n==2 || n==3)){
			if(fil==1) fputs(")",fp);
			else printf(")");
		}
	}
}