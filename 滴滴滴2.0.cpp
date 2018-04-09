#include<stdio.h>
#include<string.h>
#include <cstdlib>
#define Num 16//�ص��� 
#define Maxedge 32767//����ֵ 
typedef struct
{
	char name[10];//���� 
	int number;//��� 
	char introduce[100];//��� 
}vertex;
vertex ver[Num];//������Ϣ 
int edge[Num][Num];//�߳� 
int shortest[Num][Num];//��̾��� 
int path[Num][Num];//ǰ���ڵ� 
void init();//��ʼ�� 
void map();//��ͼ 
void menu();//�˵� 
void shortestpath();
void informatation();
int main()
{
	init();
	map();
	menu();
}
void init()//��ʼ����Ϣ 
{
	char i,j;
	ver[1].number=1;
	strcpy(ver[1].name,"����");
	strcpy(ver[1].introduce,"����\n");
	ver[2].number=2;
	strcpy(ver[2].name,"ͼ���");
	strcpy(ver[2].introduce,"ͼ���");
	ver[3].number=3;
	strcpy(ver[3].name,"�ٳ�");
	strcpy(ver[3].introduce,"��У���ٳ�");
	ver[4].number=4;
	strcpy(ver[4].name,"6������");
	strcpy(ver[4].introduce,"��У������������");
	ver[5].number=5;
	strcpy(ver[5].name,"С����");
	strcpy(ver[5].introduce,"����ľٰ쳡��");
	ver[6].number=6;
	strcpy(ver[6].name,"�³��㳡");
	strcpy(ver[6].introduce,"��У���³����ι㳡");
	ver[7].number=7;
	strcpy(ver[7].name,"ѧԷ����");
	strcpy(ver[7].introduce,"��У������");
	ver[8].number=8;
	strcpy(ver[8].name,"ר�ҹ�Ԣ");
	strcpy(ver[8].introduce,"��̹�Ԣ");
	ver[9].number=9;
	strcpy(ver[9].name,"�̹�3��");
	strcpy(ver[9].introduce,"��ְ��סַ");
	ver[10].number=10;
	strcpy(ver[10].name,"�ɻ���");
	strcpy(ver[10].introduce,"С����");
	ver[11].number=11;
	strcpy(ver[11].name,"9�Ž�ѧ¥");
	strcpy(ver[11].introduce,"�ķ�ѧԺ��ѧ¥");
	ver[12].number=12;
	strcpy(ver[12].name,"12�Ž�ѧ¥");
	strcpy(ver[12].introduce,"����ѧԺ��ѧ¥");
	ver[13].number=13;
	strcpy(ver[13].name,"15�Ž�ѧ¥");
	strcpy(ver[13].introduce,"���ѧԺ��ѧ¥");
	ver[14].number=14;
	strcpy(ver[14].name,"ѧ���㳡");
	strcpy(ver[14].introduce,"��㳡");
	ver[15].number=15;
	strcpy(ver[15].name,"����");
	strcpy(ver[15].introduce,"��У���ٳ�");
	ver[16].number=16;
	strcpy(ver[16].name,"���ϲ���");
	strcpy(ver[16].introduce,"��У������");
	for(i=1;i<=Num;i++)
	{
		for(j=1;j<=Num;j++)
		{
			edge[i][j]=Maxedge;
		}
	}
	for(i=1;i<=Num;i++)//�߳� 
	{
		edge[i][j]=0;
	}
	edge[1][2]=edge[2][1]=60;
	edge[1][3]=edge[3][1]=90;
	edge[1][4]=edge[4][1]=100;
	edge[2][3]=edge[3][2]=20;
	edge[2][4]=edge[4][2]=20;
	edge[2][5]=edge[5][2]=40;
	edge[3][5]=edge[5][3]=65;
	edge[3][9]=edge[9][3]=250;
	edge[4][6]=edge[6][4]=80;
	edge[5][6]=edge[6][5]=55;
	edge[6][7]=edge[7][6]=50;
	edge[6][8]=edge[8][6]=100;
	edge[7][8]=edge[8][7]=130;
	edge[8][9]=edge[9][8]=150;
	edge[9][10]=edge[10][9]=100;
	edge[10][11]=edge[11][10]=40;
	edge[10][12]=edge[12][10]=60;
	edge[11][12]=edge[12][11]=30;
	edge[11][14]=edge[14][11]=75;
	edge[12][13]=edge[13][12]=50;
	edge[12][14]=edge[14][12]=15;
	edge[13][14]=edge[14][13]=45;
	edge[13][15]=edge[15][13]=160;
	edge[14][15]=edge[15][14]=100;
	edge[15][16]=edge[16][15]=120;	
}
void map()
{
	printf("\t\tƽ��ͼ");
	printf("\n\n���ϲ�����16��\n");
	printf("---���򳡣�15��-----ѧ���㳡��14��\n");
	printf("------ 15�Ž�ѧ¥��13��-----12�Ž�ѧ¥��12��----9�Ž�ѧ¥��11��\n");
	printf("--------------------------------------�ɻ��أ�10��\n");
	printf("----------------------------------------�̹�3�壨9��--------------ר�ҹ�Ԣ��8��\n");
	printf("-------------------------------------------------------------------------------�³��㳡��6��----------ѧԷ������7��\n");
	printf("-----------------------------------------------------------------------------------------С���ã�5��\n");
	printf("-----------------------------------------�ٳ���3��---------------ͼ��ݣ�2��--------------------6�����ᣨ4��\n");
	printf("-----------------------------------------------------------------���ţ�1��\n");
}
void menu()
{	
	while(1)
	{
	char i;
	printf("\t\t\t��ӭʹ�õ���ϵͳ\n\n");
	printf("���롰c���Բ�ѯ���·��\n");
	printf("���롰x���Բ�ѯ��Ϣ\n");
	printf("���롰e�����˳�����\n");
	printf("�������Ӧ��Ӣ��Сд��ĸ��лл��\n\t");
    scanf("%s",&i);
		switch(i)
		{
			case'c':shortestpath();break;//��ѯ���·�� 
			case'x':informatation();break;//��Ϣ 
			case'e':printf("\n\n\n\t\t\t ллʹ�ã�\n ");
		    exit(0);break;
			default:printf("�������\n ");break;
		}
	}
	
}
void informatation()//��ѯ��Ϣ 
{
	int i;
	while(1)
	{
		printf("�������ѯ�ص�ı�ţ�\n\t");
		scanf("%d",&i);
		if(i<=Num&&i>=1)
		{
			printf("\n���ƣ�%s\n��飺%s\n\n",ver[i].name,ver[i].introduce);
			return;
		}
		else
		{
			printf("�����������������룡");
		}
	}
}
void floyd()//���������㷨ʵ�� 
{
	int i=1,j=1,k=1;
	for(i=1;i<=Num;i++)
	{
		for(j=1;j<=Num;j++)
		{
			shortest[i][j]=edge[i][j];
			if(shortest[i][j]<Maxedge)
			path[i][j]=i;//�л�����i 
			else 
			path[i][j]=-1;//i,j֮���޻�����j��ǰ����-1 
		}
	}
	for(k=1;k<=Num;k++)
	{                                                                                                                              
		for(i=1;i<=Num;i++)
		{
			for(j=1;j<=Num;j++)
			{
				if(shortest[i][j]>(shortest[i][k]+shortest[k][j]))
				{
					shortest[i][j]=(shortest[i][k]+shortest[k][j]);//�������·�� 
					path[i][j]=path[k][j];
				}
			}
		}
	}
}
void way(int i,int j)//·�� 
{
	int k=0,a=i,b=j;
	if(shortest[i][j]!=Maxedge)
	{
		printf("\n��%s��%s�����·��Ϊ��\n",ver[i].name,ver[j].name);
		printf("%s",ver[i].name);
		while(path[i][j]!=i)
		{
			k=path[i][j];
			while(path[i][k]!=i)//һֱ����ǰ������i�ĵ�һ���½ڵ���� 
			{
				k=path[i][k];
			}
			printf("-��-%s",ver[k].name);
			i=k;//����i,����k,j����ǰ�� 
		}
		printf("-����%s\n",ver[b].name);
		printf("\n��̾���Ϊ��%d�ס�\n",shortest[a][b]);
	}
	else
	{
		printf("��%s���ܵ���%s\n\n",ver[i].name,ver[j].name);
	}
}
void shortestpath()//��̾��� 
{
	int i=0,j=0;
	while(1)
	{
		printf("������Ҫ��ѯ������ı�ţ�");
		scanf("%d%d",&i,&j);
		if(i<=Num&&i>0&&j<=Num&&j>0)
		{
			floyd();
			way(i,j);
			return ;
		}
	}
}
