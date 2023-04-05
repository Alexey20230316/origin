#include<iostream>
#include<fstream>


int main() {

	setlocale(LC_ALL, "Russian");

	int N = 0;
	int M = 0;


	std::ifstream fin;           //  создаем обьект fin на чтение
	fin.open("in.txt");          //  вызов метода  open для открытия файла in.txt.

	if (!fin.is_open()) {        //  is_open  возвращает  true или false
		std::cout << "Ошибка открытия файла!" << std::endl;
	}
	else
	{
		fin >> N;
		int* arr_N = new int[N];       // Создали  динамический массив arr_N.

		for (int i = 0; i < N; i++) {   // заполнили его числами из файла 
			fin >> arr_N[i];
		}

		fin >> M;
		int* arr_M = new int[M];       // Создали динамический массив arr_M.

		for (int i = 0; i < M; i++) {   // заполнили его числами из файла 
			fin >> arr_M[i];
		}

		

	fin.close();

	//  сдвиг массива М вправо, а массива N влево
	
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


//  вывод массивов в файл out.txt. Сначало массива М а потом массива N

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
	
	  //  удаляем массив arr_N и arr_M
		delete[] arr_N;
		arr_N = nullptr;
		
		delete[] arr_M;
		arr_M = nullptr;
	
		std::cout << "\n" << "   Готово!\n\n";


	}
}