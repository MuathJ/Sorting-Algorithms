#include "iostream"
#include "time.h"
#include "stdlib.h"
using namespace std ; 

#define ArraySize 2000

//////////////////////////////////////////////////////

void SelectionSort(int *Array)
{
	int t,min;

	for (int i=0 ; i<ArraySize-1 ; i++)
	{	
		min=i;
		for (int j=i+1 ; j<ArraySize ; j++)
		{	if ( Array[j] < Array[min] )
				min=j;
		}
		if (min != i)
		{	t = Array[i];
			Array[i] = Array[min];
			Array[min] = t;
		}
	}
}

//////////////////////////////////////////////////////

void CountingSort(int *Array)
{
	int *C = new int[ArraySize];
	int Q = 0;

	for(int i=0 ; i<ArraySize ; i++)
		C[i] = 0;

	for(int i=0 ; i<ArraySize ; i++)
		C[Array[i]]++;

	for(int i=0 ; i<ArraySize ; i++)
	{
		int count = C[i];
		for(int j=0; j<count; j++)
		{
			Array[Q] = i;
			Q++;
		}
	}
}

//////////////////////////////////////////////////////

void InsertionSort(int *Array) 
{
	int j,t;
	for (int i=1 ; i<ArraySize ; i++) 
	{
		j = i;
		while ( j>0 && Array[j-1]>Array[j] ) 
		{
			t = Array[j];
			Array[j] = Array[j-1];
			Array[j-1] = t;
			j--;
		}
	}
 }

//////////////////////////////////////////////////////

void Merge(int *Array, int s1, int s2) 
{
	int S=s1+s2 , i=0 , j=0;
    int *t=new int[S];
	while (i+j < S)
	{ 
		if ( j < s2 && Array[s1+j] < Array[i] || j < s2 && i >= s1 )
            t[i+j] = Array[s1+j++];
		if ( i < s1 && Array[i] <= Array[s1+j] || i < s1 && j >= s2 )
            t[i+j] = Array[i++];
    }
	for(int i=0 ; i<S ; i++)
		Array[i]=t[i];
}

void MergeSort(int *Array, int Size) 
{
    if (Size == 1) return;
    MergeSort( Array , Size/2 );
    MergeSort( Array+Size/2 , Size-Size/2 );
    Merge( Array , Size/2 ,  Size-Size/2 );
}

//////////////////////////////////////////////////////

void Swap(int &x,int &y)
{
	int t=x; x=y; y=t;	
}

int Partition(int *Array, int l, int r) 
{
	  int i = l+1;
	  int j = r;
      int p = Array[l];

      while(1)
	  {
            while (Array[i] <= p&&i<r)
				i++;

            while (Array[j] >= p&&j>l)
				j--;
            
            if (i >= j) 
			{
                 Swap(Array[j],Array[l]);
				 return j;
            }
			else
				Swap(Array[i],Array[j]);
      } 
}

void QuickSort(int *Array, int l, int r)
{
      if (l<r)
	  {
		 int i = Partition(Array, l, r);
         QuickSort(Array, l, i-1);
         QuickSort(Array, i+1, r);
	  }
}

//////////////////////////////////////////////////////

void MaxHeap(int *Array, int i, int s)
{
    int j,t;
    t = Array[i];
    j = 2*i;
    while (j <= s)
    {
        if (j < s && Array[j+1] > Array[j])
            j = j+1;
        if (t > Array[j])
            break;
        else 
			if (t <= Array[j])
			{
				Array[j/2] = Array[j];
				j = 2*j;
			}
    }
    Array[j/2] = t;
    return;
}

void HeapSort(int *Array)
{
    int i,t;
    for (i=ArraySize-1 ; i>=2 ; i--)
    {
        t = Array[i];
        Array[i] = Array[1];
        Array[1] = t;
        MaxHeap(Array, 1, i-1);
    }
}

void Max(int *Array)
{
    for(int q = ArraySize/2; q >= 1; q--)
        MaxHeap(Array, q, ArraySize);
}

//////////////////////////////////////////////////////

void Fill(int *Array)
{
	srand(time(NULL));
	
	for(int i=0;i<ArraySize;i++)
	{
		int x=rand()%100+1;
		Array[i]=x;
		//cout<<Array[i]<<", ";
	}
	cout<<endl;
}

//////////////////////////////////////////////////////

void main(void)
{
	int Array[ArraySize];
	int Enter=0;

	Fill(Array);

	while(Enter>=0 && Enter<=7)
	{
		cout<<"\n----------------------------"<<endl;
		cout<<"(1) Selection sort"<<endl;
		cout<<"(2) Counting Sort"<<endl;
		cout<<"(3) Insertion Sort"<<endl;
		cout<<"(4) Merge Sort"<<endl;
		cout<<"(5) Quick Sort"<<endl;
		cout<<"(6) Heap Sort"<<endl;
		cout<<"(7) Display Sorted Array"<<endl;
		cout<<"(8) EXIT"<<endl<<endl;

		cout<<"Enter Sorting Method #: ";
		cin>>Enter;

		if(Enter==1)
		{
			Fill(Array);
			clock_t begin = clock();
				SelectionSort(Array);
			clock_t end = clock();

			cout<<"Time= "<<(double)(end-begin)/CLOCKS_PER_SEC<<" Seconds"<<endl<<endl;
		}
		
		else if(Enter == 2)
		{
			Fill(Array);
			clock_t begin = clock();
				CountingSort(Array);
			clock_t end = clock();

			cout<<"Time= "<<(double)(end-begin)/CLOCKS_PER_SEC<<" Seconds"<<endl<<endl;
		}

		else if(Enter == 3)
		{
			Fill(Array);
			clock_t begin = clock();
				InsertionSort(Array);
			clock_t end = clock();

			cout<<"Time= "<<(double)(end-begin)/CLOCKS_PER_SEC<<" Seconds"<<endl<<endl;
		}

		else if(Enter == 4)
		{
			Fill(Array);
			clock_t begin = clock();
				MergeSort(Array , ArraySize);
			clock_t end = clock();

			cout<<"Time= "<<(double)(end-begin)/CLOCKS_PER_SEC<<" Seconds"<<endl<<endl;
		}

		else if(Enter == 5)
		{
			Fill(Array);
			clock_t begin = clock();
				QuickSort(Array,0,ArraySize); 
			clock_t end = clock();

			cout<<"Time= "<<(double)(end-begin)/CLOCKS_PER_SEC<<" Seconds"<<endl<<endl;
		}

		else if(Enter == 6)
		{
			Fill(Array);
			Max(Array);
			clock_t begin = clock();
				HeapSort(Array);
			clock_t end = clock();

			cout<<"Time= "<<(double)(end-begin)/CLOCKS_PER_SEC<<" Seconds"<<endl<<endl;
		}

		else if(Enter==7)
		{
			cout<<endl<<"\nSorted Array Result:"<<endl<<endl;
			for(int  i=1  ; i<ArraySize ; i++ )
				cout<<Array[i]<<" ";
			cout<<endl<<endl;
		}

		else
			exit(0);
	}
}