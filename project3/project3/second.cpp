#include<stdio.h>
#include<string.h>
#include <stdlib.h>
/*��������*/
int num;
char fuhao[5];
int max;
int kuohao;
int doub;
int fil;
int i=0;
int kh=0;/*��λ�����ŵ�λ��*/
int kh2=0;/*��λ�����ŵ�λ��ǰ*/
int kh1=0;/*��λ�����ŵĸ���*/
int kh3=0;/*��λ�����ŵ�λ�ú�*/
/*��������*/
char YUN(char fuhao[5],int i);
int zs(int max);
double dec(int max);
void KX(int num,char fuhao[5]);
int KHQ(int n,int con,char b[],int kh,int kh1,int kh2,int kh3,FILE *fp);
void KHH(int n,int con,char b[],int kh,int kh1,int kh2,int kh3,FILE *fp);
int main(){
	printf("��������Ŀ������");
	scanf("%d",&num);
	for(;;){
		if(num<=0){ 
			printf("\n��������ȷ��������\n���������룺");
			scanf("%d",&num);
		}else{
			break;
		}
	}
	printf("�����������������+-*/���س���������");
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
		printf("\n�밴��Ҫ�������������");
		scanf("%s",fuhao);
		i=strlen(fuhao);
	}
	printf("���������ֵ������0����������");
	scanf("%d",&max);
	for(;;){
		if(max<1){
			printf("\n�밴��Ҫ���������ֵ��");
			scanf("%d",&max);
		}else{
			break;
		}
	}
	printf("��ѡ���Ƿ������ţ�1 �ǣ�2 �񣩣�");
	scanf("%d",&kuohao);
	for(;;){
		if(kuohao!=1 && kuohao!=2){
			printf("\n��ѡ��1��2:");
			scanf("%d",&kuohao);
		}else{
			break;
		}
	}
	printf("��ѡ���Ƿ���С����1 �ǣ�2�񣩣�");
	scanf("%d",&doub);
	for(;;){
		if(doub!=1 && doub!=2){
			printf("\n��ѡ��1��2:");
			scanf("%d",&doub);
		}else{
			break;
		}
	}
	printf("��ѡ���Ƿ��ļ������1 �ǣ�2�񣩣�");
	scanf("%d",&fil);
	for(;;){
		if(fil!=1 && fil!=2){
			printf("\n��ѡ��1��2:");
			scanf("%d",&fil);
		}else{
			break;
		}
	}
	printf("\n��ĿΪ��\n");
	/*�������ţ�����С������*/
	KX(num,fuhao);	
	return 0;
}
/*������������*/
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
/*�����������*/
int zs(int max){
	int ct;
	ct=rand()%max + 1;
	return ct;

}
/*�������С��*/
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

/*�������ţ�����С������*/
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
			/*�ж��Ƿ���С����a1Ϊ������a2ΪС��*/
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
				/*�ж��Ƿ���С����a1Ϊ������a2ΪС��*/
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
				/*�ж��Ƿ�������*/
				if(kuohao==1){/*����ǰ�벿��*/
					kh=KHQ(n,con,b,kh,kh1,kh2,kh3,fp);
				}
				/*�ж��Ƿ���С����a1Ϊ������a2ΪС��*/
				if(doub==1) fprintf(fp,"%.2lf",a2[n]);
				else fprintf(fp,"%d",a1[n]);
				if(kuohao==1){/*���ź�벿��*/
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
/*�������ǰ�벿��*/
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
/*������ź�벿��*/
void KHH(int n,int con,char b[],int kh,int kh1,int kh2,int kh3,FILE *fp){
	if(con==3){/*��λ���ļӼ��˳�*/
		if(kh==1 && n==1){/*ǰ������������*/
			if(fil==1) fputs(")",fp);
			else printf(")");
			kh=0;
		}
		else if(kh==2 && n==2){/*��������������*/
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