#ifndef		RTOS_INTERFACE_H
#define		RTOS_INTERFACE_H


void	RTOS_voidInit(void);
void	RTOS_voidCreatTask(u8 priority , u16 period, void (*ptr_f)(void));


#endif