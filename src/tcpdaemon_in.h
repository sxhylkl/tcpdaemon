#ifndef _H_TCPDAEMON_IN_
#define _H_TCPDAEMON_IN_

/*
 * tcpdaemon - TCP���ӹ����ػ�
 * author      : calvin
 * email       : calvinwilliams@163.com
 *
 * Licensed under the LGPL v2.1, see the file LICENSE in base directory.
 */

#include "LOGC.h"

#include "tcpdaemon.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TCPDAEMON_CALLMODE_CALLBACK		1 /* ����ģʽ:���ػ�ģʽ */

/* �ź���ֵ�ṹ */
union semun
{
	int		val ;
	struct semid_ds	*buf ;
	unsigned short	*array ;
	struct seminfo	*__buf ;
};

/* �ػ������ṹ */
typedef struct
{
	int		fd[ 2 ] ;
} PIPE_T ;

struct TcpdaemonServerEnvirment
{
	struct TcpdaemonEntryParameter	*p_para ;
	
	OBJECTHANDLE			so_handle ; /* ��̬��򿪾�� */
	func_tcpmain			*pfunc_tcpmain ; /* ��̬�����:ͨѶ����Э�鼰Ӧ�ô����ص����� */
	void				*param_tcpmain ; /* ��ڲ��� */
	int				listen_sock ; /* �����׽��� */
	
	/* ��Instance-Fork����ģ��ʹ�� */
	long				process_count ;
	
	/* ��Leader-Follow���̳�ģ��ʹ�� */
	int				accept_mutex ; /* accept�ٽ��� */
	
	long				index ; /* ����������� */
	
	long				requests_per_process ; /* �������̵�ǰ�������� */
	
	PID_T				*pids ;
	PIPE_T				*alive_pipes ; /* �������̻�֪�������̻��ܵ�������˵�ǹ�������֪ͨ�������̽���������ܵ� */
					/* parent fd[1] -> child fd[0] */
	
	/* ��Leader-Follow�̳߳�ģ��ʹ�� */
	THANDLE_T			*thandles ;
	TID_T				*tids ;
} ;

#ifdef __cplusplus
}
#endif

#endif
