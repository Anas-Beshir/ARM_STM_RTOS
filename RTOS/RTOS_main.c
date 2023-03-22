#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"STK_interface.h"
#include	"RTOS_interface.h"

void	Task1(void);
void	Task2(void);
void	Task3(void);

int	main(void)
{
	/*	Initialization Part		*/
	
	/*	System Clk init			*/
	MRCC_voidSysClkInit();
	
	/*	Toggle Led C13	GPIOC	*/
	/*	1- Enable Per Clk "RCC" Port C		*/
	MRCC_voidEnablePerClk(RCC_APB2,4);
	
	/*	Direction for C13 is output Push Pull */
	MDIO_voidSetPinDirection(PORTC, PIN13, OUT_2MHZ_PP);
	MDIO_voidSetPinDirection(PORTC, PIN14, OUT_2MHZ_PP);
	MDIO_voidSetPinDirection(PORTC, PIN15, OUT_2MHZ_PP);
	
	RTOS_voidCreatTask(0,1000,Task1);
	RTOS_voidCreatTask(1,2000,Task2);
	RTOS_voidCreatTask(2,3000,Task3);
	/*	RTOS initilaization	*/
	RTOS_voidInit();
	
	
	while(1)
	{

	}
	return 0;
}


void	Task1(void)
{
	static u8	flag1 = 0;
	if(flag1 == 0)
	{
		MDIO_voidSetPinValue(PORTC, PIN13, DIO_LOW);
		flag1 = 1;
	}else
	{
		MDIO_voidSetPinValue(PORTC, PIN13, DIO_HIGH);
		flag1 = 0;
	}
}

void	Task2(void)
{
	static u8	flag2 = 0;
	if(flag2 == 0)
	{
		MDIO_voidSetPinValue(PORTC, PIN14, DIO_LOW);
		flag2 = 1;
	}else
	{
		MDIO_voidSetPinValue(PORTC, PIN14, DIO_HIGH);
		flag2 = 0;
	}
}

void	Task3(void)
{
	static u8	flag3 = 0;
	if(flag3 == 0)
	{
		MDIO_voidSetPinValue(PORTC, PIN15, DIO_LOW);
		flag3 = 1;
	}else
	{
		MDIO_voidSetPinValue(PORTC, PIN15, DIO_HIGH);
		flag3 = 0;
	}
}