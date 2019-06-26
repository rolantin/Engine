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
	double balance = 50;
	int count=0;
while(balance < 100){
	balance = balance + balance *0.02;
	count++;

}
cout << count;

	//cout << i + c;
	system("pause");
	return 0;


}