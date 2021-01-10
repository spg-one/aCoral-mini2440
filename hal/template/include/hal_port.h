#ifndef HAL_PORT_H
#define HAL_PORT_H
//�ڴ���ص�Ӳ������ӿ�
#define HAL_MEM_INIT() 
#define HAL_HEAP_START 0
#define HAL_HEAP_END 1
//�߳���ص�Ӳ������ӿ�
#define	HAL_STACK_INIT(stack,route,exit,args)
#define	HAL_SWITCH_TO(stack)
#define	HAL_INTR_SWITCH_TO(stack) 
#define	HAL_CONTEXT_SWITCH(prev_stack,next_stack) 
#define	HAL_INTR_CTX_SWITCH(prev_stack,next_stack) 

//�ж���ص�Ӳ������ӿ�
#define HAL_INTR_INIT()
#define	HAL_INTR_ENABLE()
#define	HAL_INTR_DISABLE()
#define	HAL_INTR_DISABLE_SAVE() 1
#define	HAL_INTR_RESTORE(sr) 

#define HAL_INTR_NUM 1
#define HAL_INTR_MIN 0
#define HAL_INTR_MAX 1
//ticksʱ����ص�Ӳ������ӿ�
#define HAL_TICKS_INTR 0
#define	HAL_TICKS_INIT() 
#define HAL_BOARD_INIT() 

//�����ص�Ӳ������ӿڣ�����ڵ����²���ʵ��
#ifdef CFG_CMP
#define HAL_IPI_SEND(cpu,vector)
#define HAL_CMD_IPI 0
#define HAL_CPU_IS_ACTIVE(cpu)
#define HAL_PREPARE_CPUS()
#define HAL_START_CPU(cpu)
#define HAL_CMP_ACK() 
#define HAL_WAIT_ACK()
#define HAL_CORE_CPU_INIT()
#define HAL_FOLLOW_CPU_INIT()
#endif

#endif
