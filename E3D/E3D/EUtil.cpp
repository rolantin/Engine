#include "EUtil.h"

#include <stdio.h>

namespace E3D{
	//ofstream fout( "d:\\mytest.txt" ); 输出流
	std::ofstream *GlogStream = NULL;

	bool InitLog (const EString &fileName){
		if(GlogStream == NULL){
			GlogStream = new std::ofstream();
			GlogStream->open(fileName.c_str());
			if (GlogStream->good()) //good()检测流是否通过.   流通过为true；
				return true;

			return false;
		}
		return true;
	}
	
	void Log(const EChar *string , ... ){
	if (GlogStream == NULL)
		return;

	EChar buffer[256];

	//保证两者不为空
	if (!string || !GlogStream)
		return;

	va_list arglist; //可变的参数列表
	//利用在栈上的可变的参数打印输出字符
	va_start(arglist, string);
	vsprintf_s(buffer, string, arglist);
	va_end(arglist);

	EString info(buffer);
	//输出流信息
	*GlogStream << info << std::endl;
	GlogStream->flush();
	}

	void	CloseLog(){
	GlogStream->close();
	SafeDelete(GlogStream);
	}

}