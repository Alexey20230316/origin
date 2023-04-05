#include<iostream>
#include<fstream>


int main() {

	setlocale(LC_ALL, "Russian");

	int N = 0;
	int M = 0;


	std::ifstream fin;           //  ������� ������ fin �� ������
	fin.open("in.txt");          //  ����� ������  open ��� �������� ����� in.txt.

	if (!fin.is_open()) {        //  is_open  ����������  true ��� false
		std::cout << "������ �������� �����!" << std::endl;
	}
	else
	{
		fin >> N;
		int* arr_N = new int[N];       // �������  ������������ ������ arr_N.

		for (int i = 0; i < N; i++) {   // ��������� ��� ������� �� ����� 
			fin >> arr_N[i];
		}

		fin >> M;
		int* arr_M = new int[M];       // ������� ������������ ������ arr_M.

		for (int i = 0; i < M; i++) {   // ��������� ��� ������� �� ����� 
			fin >> arr_M[i];
		}

		

	fin.close();

	//  ����� ������� � ������, � ������� N �����
	
	int buf_M = arr_M[M - 1];
	for (int i = M - 2; i >= 0; i--){
		arr_M[i + 1] = arr_M[i];
     }
	arr_M[0] = buf_M;
	
	
	int buf_N = arr_N[0];
	for (int i = 1; i < N; i++){
		arr_N[i -1] = arr_N[i];
     }
	arr_N[N - 1] = buf_N;


//  ����� �������� � ���� out.txt. ������� ������� � � ����� ������� N

	std::ofstream fout;
	fout.open("out.txt");

	    fout << M << "\n";
		for (int i = 0; i < M; i++) {
			fout << arr_M[i] << " ";
		}
		fout << "\n";

		fout << N << "\n";
		for (int i = 0; i < N; i++) {
			fout << arr_N[i] << " ";
		}


		fout.close();
	
	  //  ������� ������ arr_N � arr_M
		delete[] arr_N;
		arr_N = nullptr;
		
		delete[] arr_M;
		arr_M = nullptr;
	
		std::cout << "\n" << "   ������!\n\n";


	}
}