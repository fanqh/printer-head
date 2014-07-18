#ifndef __printer_h__
#define __printer_h__
#include<reg52.h>


typedef struct 
{
	char no_paper;
	char over_hot;
	char step_count;
	char thermal_head_count;            	 //�������ݱ���
	char data_ready;
	char time0_count;
}PRT_STM;
extern PRT_STM prt_stm;


void PRT_DotLine(char *str, int length);
void PRT_STM_init (void);
void timer0_start(void);
void timer0_stop(void);
void PRT_dry_run(int line_num);

#endif
