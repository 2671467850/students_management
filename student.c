#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu()
{
	printf("                                  |                hello world               |\n");
}



struct student //�ṹ��
{
	char name[20];
	int sno;
	int grade1;
	int grade2;
	int grade3;
}p[3];
struct student t;

//ȫ�ֱ���
int i;
int j;
int n;
int m;
int x;
char b[1];
char *filename;
FILE *fp;

int a1,a2,a3;
int xh;
int sum1,sum2,sum3;
int rs=0;

int main()//main()����
{
	
	//����	
	void luru();
	void xs();
	//void bc();
	void px();
	void xg();
	void tj();
	void save();
	void read();
	
	//char sr_cj[10];
	menu();
	
	while(1)
	{
		printf("                                  |     -------------�����˵�-----------     |\n");
		printf("                                  |     ***********1:�ɼ�¼��***********     |\n");
		printf("                                  |     ***********2:�ɼ���ʾ***********     |\n");
		printf("                                  |     ***********3:�ɼ�����***********     |\n");
		printf("                                  |     ***********4:�ɼ�����***********     |\n");
		printf("                                  |     ***********5:�ɼ��޸�***********     |\n");
		printf("                                  |     ***********6:�ɼ�ͳ��***********     |\n");
		printf("                                  |     ***********0:�˳�����***********     |\n");
		printf("                                  |     --------------------------------     |\n");
		printf("�����ּ�ѡ��Ҫִ�еĲ���:");
		scanf("%d",&x);
		printf("\n");
		//����0����ѭ�����˳�����
		if(x==0)
			break;
		
		switch(x)
		{
		case 1:
			luru();
			
			break;//����1������switch��䣬������һ��ѭ��
		case 2: 
			read(3,"student.txt");/*���ļ��ж�ȡ����*/
			
			break;//����2������switch��䣬������һ��ѭ��
		case 3: 
			//bc();
			save(3,"student.txt");/*�����ݱ��浽�ļ�*/
			
			break;
		case 4:
			px();
			
			break;
		case 5:
			xg();
			
			break;
		case 6:
			tj();
			
			break;
		default://���������������siwtch��䣬������һ��ѭ��
			printf("��������ֲ���ȷ\n");
			break;
		}
	}
	return 0;
}


void luru()//ѧ����Ϣ¼��
{
	system("cls");
	printf("������ѧ������ ѧ�� ���Ƴɼ�:\n");
	for(i=0;i<3;i++)
		scanf("%s%d%d%d%d",&p[i].name,&p[i].sno,&p[i].grade1,&p[i].grade2,&p[i].grade3);
	system("cls");
}


void read(int n,char *filename)//ѧ����Ϣ��ȡ
{
	system("cls");
	
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("cannot open file!\n");
		exit(0);
	}
	printf("����   ѧ��    ����   ���ݽṹ ��� \n");
	for(i=0;i<n;i++)
	{
		fread(&p[i],sizeof(struct student),1,fp);
		printf("%s\t%d\t%d\t%d\t%d\n",p[i].name,p[i].sno,p[i].grade1,p[i].grade2,p[i].grade3);
	}
	fclose(fp);
}


void save(int n,char *filename)//ѧ����Ϣ����
{
	system("cls");
	
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("cannot creat file.\n");
		exit(0);
	}
	for(i=0;i<n;i++)
		if(fwrite(&p[i],sizeof(struct student),1,fp)!=1)
			printf("\n write error!\n");
		fclose(fp);
		printf("ѧ���ɼ��ѱ���\n");
}


void px()//ѧ���ɼ�����
{
	system("cls");
	printf("�����밴��Ŀ������\n");
	scanf("%d",&n);
	printf("\n");
	//���տ�Ŀһ����
	if(n==1)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2-i;++j)
			{
				if(p[j].grade1>p[j+1].grade1)
				{
					t=p[j];
					p[j]=p[j+1];
					p[j+1]=t;
				}
			}
		}
		save(3,"student.txt");/*�����ݱ��浽�ļ�*/
	}
	//���տ�Ŀ������
	if(n==2)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2-i;++j)
			{
				if(p[j].grade2>p[j+1].grade2)
				{
					t=p[j];
					p[j]=p[j+1];
					p[j+1]=t;
				}
			}
		}
		save(3,"student.txt");/*�����ݱ��浽�ļ�*/
	}
	//���տ�Ŀ������
	if(n==3)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2-i;++j)
			{
				if(p[j].grade3>p[j+1].grade3)
				{
					t=p[j];
					p[j]=p[j+1];
					p[j+1]=t;
				}
			}
		}
		save(3,"student.txt");/*�����ݱ��浽�ļ�*/
	}
	//�����������
	read(3,"student.txt");/*���ļ��ж�ȡ����*/
}


void xg()//ѧ����Ϣ�޸�
{
	system("cls");
	printf("ѧ����Ϣ�޸�\n");
	printf("������ѧ��,�Ա��޸�:\n");
	scanf("%d",&xh);
	for(i=0;i<3;i++)
	{
		if(p[i].sno==xh)
			break;
	}
	printf("ȷ���޸�ѧ��: %s ����Ϣ\n",p[i].name);
	printf("������y/n(��ʾ������y�������룬����n��������)��");
	scanf("%s",b);
	while(strcmp(b,"Y")==0||strcmp(b,"y")==0)
	{
		printf("�������һ��ɼ�(�س���������):\n");
		a1=0;
		scanf("%d",&a1);
		if(a1!=0){p[i].grade1=a1;};
		printf("������ڶ���ɼ�(�س���������):\n");
		a2=0;
		scanf("%d",&a2);
		if(a2!=0){p[i].grade2=a2;};
		printf("�����������ɼ�(�س���������):\n");
		a3=0;
		scanf("%d",&a3);
		if(a3!=0){p[i].grade3=a3;};
		printf("�������\n"); 
		printf("�Ƿ����y/n(��ʾ������y�������룬����n��������)��");
		scanf("%s",b);
	}
	save(3,"student.txt");/*�����ݱ��浽�ļ�*/
	system("cls");
}


void tj()//ѧ����Ϣͳ��
{
	system("cls");
	read(3,"student.txt");/*���ļ��ж�ȡ����*/
	printf("ͳ��\n");
	//ÿ�ųɼ���ߵ�ѧ����������Ϣ
	printf("ÿ�ųɼ���ߵ�ѧ����������Ϣ:\n");
	t.grade1=0;
	t.grade2=0;
	t.grade3=0;
	//��һ�ųɼ���ߵ�ѧ����������Ϣ
	printf("��һ�ųɼ���ߵ�ѧ����������Ϣ:\n");
	for(i=0;i<3;i++)
	{
		if(p[i].grade1>t.grade1)
			t=p[i];
	}
	printf("����   ѧ��    ��Ŀ1   ��Ŀ2   ��Ŀ3\n");
	//fread(&p[i],sizeof(struct student),1,fp);
	printf("%s\t%d\t%d\t%d\t%d\n",t.name,t.sno,t.grade1,t.grade2,t.grade3);
	//�ڶ��ųɼ���ߵ�ѧ����������Ϣ
	printf("�ڶ��ųɼ���ߵ�ѧ����������Ϣ:\n");
	for(i=0;i<3;i++)
	{
		if(p[i].grade2>t.grade2)
			t=p[i];
	}
	printf("����   ѧ��    ��Ŀ1   ��Ŀ2   ��Ŀ3\n");
	//fread(&p[i],sizeof(struct student),1,fp);
	printf("%s\t%d\t%d\t%d\t%d\n",t.name,t.sno,t.grade1,t.grade2,t.grade3);
	//�����ųɼ���ߵ�ѧ����������Ϣ
	printf("�����ųɼ���ߵ�ѧ����������Ϣ:\n");
	for(i=0;i<3;i++)
	{
		if(p[i].grade3>t.grade3)
			t=p[i];
	}
	printf("����   ѧ��    ��Ŀ1   ��Ŀ2   ��Ŀ3\n");
	//fread(&p[i],sizeof(struct student),1,fp);
	printf("%s\t%d\t%d\t%d\t%d\n",t.name,t.sno,t.grade1,t.grade2,t.grade3);
	printf("\n");
	printf("\n");
	
	//ÿ�ſγ̵�ƽ���ɼ�
	printf("ÿ�ſγ̵�ƽ���ɼ�:\n");
	//ÿһ�γ̵�ƽ���ɼ�
	printf("��һ�γ̵�ƽ���ɼ�:");
	for(i=0;i<3;i++)
		sum1+=p[i].grade1;
	sum1=sum1/3;
	printf("%d\n",sum1);
	
	//ÿ���γ̵�ƽ���ɼ�
	printf("�ڶ��γ̵�ƽ���ɼ�:");
	for(i=0;i<3;i++)
		sum2+=p[i].grade2;
	sum2=sum2/3;
	printf("%d\n",sum2);
	
	//ÿ���γ̵�ƽ���ɼ�
	printf("�����γ̵�ƽ���ɼ�:");
	for(i=0;i<3;i++)
		sum3+=p[i].grade3;
	sum3=sum3/3;
	printf("%d\n",sum3);
	printf("\n");
	printf("\n");
	
	printf("ѡ��鿴���ſγ�����:");
	//����ĳ�ſγ�ƽ���ɼ���ѧ������
	scanf("%d",&m);
	printf("\n");
	
	if(m==1)//������һ�ſγ�ƽ���ɼ���ѧ������
	{
		printf("������һ�ſγ�ƽ���ɼ���ѧ������:");
		for(i=0;i<3;i++)
		{
			if(p[i].grade1>sum1)
				rs++;
		}
		printf("%d\n",rs);
	}
	
	if(m==2)//�����ڶ��ſγ�ƽ���ɼ���ѧ������
	{
		printf("�����ڶ��ſγ�ƽ���ɼ���ѧ������:");
		for(i=0;i<3;i++)
		{
			if(p[i].grade2>sum2)
				rs++;
		}
		printf("%d\n",rs);
	}
	
	if(m==3)//���������ſγ�ƽ���ɼ���ѧ������
	{
		printf("���������ſγ�ƽ���ɼ���ѧ������:");
		for(i=0;i<3;i++)
		{
			if(p[i].grade3>sum3)
				rs++;
		}
		printf("%d\n",rs);
	}
	sum1=sum2=sum3=0;
	rs=0;
	
}