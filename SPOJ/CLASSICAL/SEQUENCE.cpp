#include <iostream>
#include <cstring>
using namespace std;

struct node
{
	char seq[6];
	int freq;
	node* next;
};

node* head=NULL;

int n,pos,end;
int seqlen;
char seq[6];
char text[200000];
int c=0;

bool isSeq(char s[]) 
{
	int i;
	if(strlen(seq)<seqlen)
		return false;
	for(i=0;i<seqlen;i++)
		if(!isalpha(s[i]))
			return false;
	return true;
}

void genSeq()
{
	int i;
	if(strlen(seq)==0)
	{
		for(i=0;i<seqlen && pos!=n;i++)
			seq[i]=text[pos++];
		seq[i]='\0';
	}
	else
	{
		for(i=0;i<seqlen;i++)
			seq[i]=seq[i+1];
		seq[seqlen-1]=text[pos++];
	}
	if(pos==n)
		end=1;
}

void insert()
{
	if(head==NULL)
	{
		node* ptr=new node;
		ptr->freq=1;
		strcpy(ptr->seq,seq);
		ptr->next=NULL;
		head=ptr;
	}
	else
	{
		node* temp=head;
		node* prev=head;
		int found=0;
		int res;
		for(; temp!=NULL && !found; temp=temp->next)
		{
			res=strcmp(temp->seq,seq);
			if(res>0)
			{	
				node* ptr=new node;
				strcpy(ptr->seq,seq);
				ptr->freq=1;
				ptr->next=temp;
				if(temp==head)
					head=ptr;	
				else
					prev->next=ptr;
				found=1;
			}
			else if(res==0)
			{
				temp->freq++;
				found=1;
			}
			prev=temp;
		}	
		if(!found)
		{
			node* ptr=new node;
			strcpy(ptr->seq,seq);
			ptr->freq=1;
			ptr->next=NULL;
			prev->next=ptr;
		}
	}
}

void find()
{
	while(!end)
	{
		genSeq();
		if(isSeq(seq))
		{
			c++;
			insert();
		}
	}
}

void dispDelMax()
{
	int i;
	printf("Analysis for Letter Sequences of Length %d\n",seqlen);
	printf("-----------------------------------------\n");
	for(i=0;i<5 && head!=NULL;i++)
	{
		node* temp=head;
		int max;
		if(temp)
		{
			max=temp->freq;
			temp=temp->next;
		}
		for(;temp!=NULL;temp=temp->next)
		{
			if(temp->freq>max)
				max=temp->freq;
		}
		printf("Frequency = %d, Sequence(s) = (",max);
		int e=0;
		node* prev=head;
		for(temp=head;temp!=NULL;)
		{
			if(temp->freq==max)
			{
				if(e)
					printf(",");
				e++;
				printf("%s",temp->seq);

				if(temp==head)
				{
					head=head->next;
					delete temp;
					prev=temp=head;
				}
				else
				{
					prev->next=temp->next;
					delete temp;
					temp=prev->next;
				}				
			}
			else
			{
				prev=temp;
				temp=temp->next;
			}
		}
		printf(")\n");
	}
	node* t=head;
	for(;head!=NULL;t=head)
	{
		head=head->next;
		delete t;
	}
}

main()
{
	int i;
	char ch;
	n=0;

	while(EOF!=scanf("%c",&ch))
	{
		text[n]=toupper(ch);
		n++;
	}

	for(i=1;i<=5;i++)
	{
		seq[0]='\0';
		pos=0;
		seqlen=i;
		end=0;
		find();
		dispDelMax();
		printf("\n");
	}
	
	return 0;
}
