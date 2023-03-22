#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"RTOS_interface.h"
#include	"RTOS_private.h"
#include	"RTOS_config.h"


#ifndef		NULL
#define		NULL	(void *)0
#endif

static Task_TCB Tasks[NUM_OF_TASKS];
static u16 Ticks = 0 ;
void	RTOS_voidInit(void)
{
	/*	Tick Time = 1 msec				*/
	/*	SysTick Init, SysTick = 1usec	*/
	STK_voidInit();
	/*	SysTick call 1000usec = 1msec	*/
	STK_voidSetIntervalPeriodic(1000,RTOS_voidScheduler);
}
void	RTOS_voidCreatTask(u8 priority , u16 period, void (*ptr_f)(void))
{
	Tasks[priority].u16_Periodicity = 	period;
	Tasks[priority].pf = 	ptr_f;
}

static void RTOS_voidScheduler(void)
{
	for(u8 i = 0 ; i < NUM_OF_TASKS ; i++)
	{
		if((Ticks % Tasks[i].u16_Periodicity) == 0 )
		{
			Tasks[i].pf();
		}
	}
	Ticks++;
}