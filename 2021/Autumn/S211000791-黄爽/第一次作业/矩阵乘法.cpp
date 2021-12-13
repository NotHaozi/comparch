#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <time.h>   // ����ʱ������ĺ��� 
using namespace std;
 
void matrix_multiply_ijk(int **a, int **b, int **c, int n);
void matrix_multiply_ikj(int **a, int **b, int **c, int n);
void matrix_multiply_kij(int **a, int **b, int **c, int n);
void matrix_multiply_jki(int **a, int **b, int **c, int n);
void matrix_multiply_kji(int **a, int **b, int **c, int n);
void matrix_multiply_jik(int **a, int **b, int **c, int n);
void matrix_print(int **a, int n);
 
int main(int argc, char *argv[])
{
	// �������飺
	srand(time(0));
	int matrix_n = 5000;     // �޸ľ���Ľ���Ϊ��ͬ��ֵ 
	int numberOfRows = matrix_n;
	int numberOfCols = matrix_n;
	int** mat1 = new int* [numberOfRows];  // a���������
	int** mat2 = new int* [numberOfRows]; 
	int** mat3 = new int* [numberOfRows]; 
	for(int i=0; i<numberOfRows; i++)
	{
		mat1[i] = new int[numberOfCols];
		mat2[i] = new int[numberOfCols];
		mat3[i] = new int[numberOfCols];
	} 
	
	// ��ʼ������  1-10֮�������� 
	for(int i=0; i<numberOfRows; i++)
	{
		for(int j=0; j<numberOfCols; j++)
		{
			mat1[i][j] = 1 + rand()%(10-1+1);
			mat2[i][j] = 1 + rand()%(10-1+1);
		}
	}
	
	//matrix_print(mat1, matrix_n);    // ������� 
	//matrix_print(mat2, matrix_n);    // ������� 
	//matrix_print(mat3, matrix_n);
	
	double clocks_PerMills = double(CLOCKS_PER_SEC) / 1000.0;   // ������ÿ���Ӱ�����ʱ���� 

	
	// ѡ�����˷����� 
	//matrix_multiply_ijk(mat1, mat2, mat3, matrix_n);        // ����˷�
	for(int m=0;m<6;m++)
	{
		if(m=0)
		{
		clock_t start_time = clock();                            // ��ʼ��ʱ���� 	
		matrix_multiply_ikj(mat1, mat2, mat3, matrix_n);
	    double elapseMills1 = (clock()-start_time) / clocks_PerMills; 
	    cout << "ikj run time: " << elapseMills1<< "ms" << endl;
	    	
		}
		else if(m=1)
		{
		clock_t start_time = clock();                            // ��ʼ��ʱ���� 	
		matrix_multiply_ijk(mat1, mat2, mat3, matrix_n);
	    double elapseMills2 = (clock()-start_time) / clocks_PerMills; 
	    cout << "ijk run time: " << elapseMills2<< "ms" << endl;
	   	
		}
		else if(m=2)
		{
			clock_t start_time = clock();                            // ��ʼ��ʱ���� 	
		matrix_multiply_kij(mat1, mat2, mat3, matrix_n);
	    double elapseMills3 = (clock()-start_time) / clocks_PerMills; 
	    cout << "kij run time: " << elapseMills3<< "ms" << endl;	
		}
		
		else if(m=3)
		{
			clock_t start_time = clock();                            // ��ʼ��ʱ���� 	
		matrix_multiply_jki(mat1, mat2, mat3, matrix_n);
	    double elapseMills4 = (clock()-start_time) / clocks_PerMills; 
	    cout << "jki run time: " << elapseMills4<< "ms" << endl;	
		}
		else if(m=4)
		{
			clock_t start_time = clock();                            // ��ʼ��ʱ���� 	
		matrix_multiply_kji(mat1, mat2, mat3, matrix_n);
	    double elapseMills5 = (clock()-start_time) / clocks_PerMills; 
	    cout << "kji run time: " << elapseMills5<< "ms" << endl;	
		}
		
		else if(m=5)
		{
			clock_t start_time = clock();                            // ��ʼ��ʱ���� 	
		matrix_multiply_jik(mat1, mat2, mat3, matrix_n);
	    double elapseMills6 = (clock()-start_time) / clocks_PerMills; 
	    cout << "jik run time: " << elapseMills6<< "ms" << endl;	
		}
		
		 cout << "clock_perMils: " << clocks_PerMills << endl;	 
		 
	}
	 
	//matrix_print(mat3, matrix_n);
	// matrix_multiply_ikj(mat1, mat2, mat3, matrix_n);
	// matrix_print(mat3, matrix_n);
	// �ͷ��ڴ� 
	for(int i=0; i<numberOfRows; i++)
	{
		delete mat1[i];
		delete mat2[i];
		delete mat3[i];
	}
	delete mat1;
	delete mat2;
	delete mat3;
	return 0;
}
 
// �������˷� ijk
void matrix_multiply_ijk(int **a, int **b, int **c, int n)  // n��ʾ����Ľ��� 
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int sum = 0;
			for(int k=0; k<n; k++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
}
 
// �������˷� ikj
void matrix_multiply_ikj(int **a, int **b, int **c, int n)  // n��ʾ����Ľ��� 
{
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
		{
			int sum = 0;
			int j;
			for(j=0; j<n; j++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
}

// �������˷� kij
void matrix_multiply_kij(int **a, int **b, int **c, int n)  // n��ʾ����Ľ��� 
{
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		{
			int sum = 0;
			int j;
			for(j=0; j<n; j++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
}

// �������˷� kji
void matrix_multiply_kji(int **a, int **b, int **c, int n)  // n��ʾ����Ľ��� 
{
	for(int k=0; k<n; k++)
	{
		for(int j=0; j<n; j++)
		{
			int sum = 0;
			int i;
			for(i=0; i<n; i++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
}

// �������˷� jki
void matrix_multiply_jki(int **a, int **b, int **c, int n)  // n��ʾ����Ľ��� 
{
	for(int j=0; j<n; j++)
	{
		for(int k=0; k<n; k++)
		{
			int sum = 0;
			int i;
			for(i=0; i<n; i++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
}

// �������˷� jik
void matrix_multiply_jik(int **a, int **b, int **c, int n)  // n��ʾ����Ľ��� 
{
	for(int j=0; j<n; j++)
	{
		for(int i=0; i<n; i++)
		{
			int sum = 0;
			int k;
			for(k=0; k<n; k++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
}
 
// �������
void matrix_print(int **a, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
} 

