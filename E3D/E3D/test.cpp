#pragma once

#include <iostream>
#include <string>

using namespace std;



int main() {

	double one(0.5);
	double two(0.15);
	double three(0.25);
	double four(0.115);
	double	 five(0.1115);		
	//cout.precision(2);
//	cout << "This\tis\ta\tC++\tprogram";
//	string day;
////	day = "mr.ax";
//cin >> day;
//	cout << day;
	//int a;
	//cin >> a;

	//while(a > 0){
	//	cout << "hello";
	//	a = a - 1;

	//}
//	double balance = 50;
//	int count=0;
//while(balance < 100){
//	balance = balance + balance *0.02;
//	count++;
//
//}
	//int grade;
	//do {

	//	cin >> grade;
	//	switch (grade)
	//	{
	//	case  1:
	//		cout << "b";
	//		break;
	//	case 2:
	//		cout << "c";
	//		break;
	//	case 3:
	//		cout << "c";
	//		break;
	//	case 4:
	//		cout << "c";
	//		break;

	//	default:
	//		cout << "end";
	//		break;
	//	}
	//} while (grade != 4);
	//	

	//int number = 222;
	//{
	//	int number = 345
	
		//	cout << number;
		//}
		//cout << number;
	 //  

	//for (int n = 9; n >= 0; n--) {
	//	cout << n;
	//}

	// int k=10;
	//while (k >=0)
	//{
	//	
	//	k--;
	//	if (k < 0) {

	//		break;
	//	}
	//	cout << k;

	//}

	int sum = 0;
	int next;
	for (int count = 1; count <= 5; count++) {
		cin >> next;
		sum = sum + next;
		cout << sum;
	}



	system("pause");
	return 0;
	

}