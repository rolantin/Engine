#include "EUtil.h"

#include <stdio.h>

namespace E3D{
	//ofstream fout( "d:\\mytest.txt" ); �����
	std::ofstream *GlogStream = NULL;

	bool InitLog (const EString &fileName){
		if(GlogStream == NULL){
			GlogStream = new std::ofstream();
			GlogStream->open(fileName.c_str());
			if (GlogStream->good()) //good()������Ƿ�ͨ��.   ��ͨ��Ϊtrue��
				return true;

			return false;
		}
		return true;
	}
	
	void Log(const EChar *string , ... ){
	if (GlogStream == NULL)
		return;

	EChar buffer[256];

	//��֤���߲�Ϊ��
	if (!string || !GlogStream)
		return;

	va_list arglist; //�ɱ�Ĳ����б�
	//������ջ�ϵĿɱ�Ĳ�����ӡ����ַ�
	va_start(arglist, string);
	vsprintf_s(buffer, string, arglist);
	va_end(arglist);

	EString info(buffer);
	//�������Ϣ
	*GlogStream << info << std::endl;
	GlogStream->flush();
	}

	void	CloseLog(){
	GlogStream->close();
	SafeDelete(GlogStream);
	}

}