#include"bsp.h"
#include"delay.h"
#include"printer.h"
#include"test_case.h"

#define PRT_DOTLINE 1
#define PRT_DRYRUN 2
char UART_Data[48]={0x55,0x56,0x57,0x58};  //���յ�������



void main()
{
	char str_type=PRT_DOTLINE;
	int line_num=4;

	port_init();		//�˿ڵĳ�ʼ��//
	PRT_STM_init();		//״̬���ĳ�ʼ��//



//time0�ж�ʱ�侫�Ȳ���
#ifdef TEST_CASE_TIME0		
	timer0_start();
	while(1);
#endif



//����һ��dotline��������32��dot��
#ifdef TEST_CASE_DOTLINE
	UART_Data[0]=0x55;
	UART_Data[1]=0x00;
	UART_Data[2]=0xff;
	UART_Data[3]=0x55;
	while(1)
	{
		PRT_DotLine(UART_Data,4);
		delay(40);
	}

#endif

//MOTOR����
#ifdef TEST_CASE_MOTOR
	timer0_start();
	
	while(1)
	{
		prt_stm.data_ready=1;
		delay(500);
	}

#endif


//�������
#ifdef TEST_CASE_FF
	while(1)
	{
		PRT_dry_run(10);
		delay(500);
	}
#endif
	
	while(1)
	{	
		if(NO_PAPER!=0)	  //�ж��Ƿ���ֽ//
		{
			if(str_type == PRT_DOTLINE)
			{
				PRT_DotLine(UART_Data,4);
			}
		
			else 
			if(str_type == PRT_DRYRUN)
			{
				PRT_dry_run(line_num);
			}
		}
		else
		{
		
		}
	}
}


 