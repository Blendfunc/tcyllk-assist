#pragma once

#define TINYNUM 0.000001
typedef struct tagLGRANGE
{
	float left;
	float right;
}LGRANGE;
enum LGErrorStates
{
	LG_ERR_ILLEGALiMG = 0,/*!< �Ƿ�ͼ�� */
	LG_ERR_MEMORYERR,/*!< �ڴ���� */
	LG_ERR_NOPATHCONNECT,/*!< ����������û��·���������� */
	LG_ERR_ONEPATHCONNECT,/*!< һ��·������ */
	LG_ERR_TWOPATHCONNECT,/*!< ����·������ */
	LG_ERR_THREEPATHCONNECT,/*!< ����·������ */
	LG_ERR_ILLEGALPOINT,/*!< ����Ƿ� */
	LG_ERR_SQUARESNUMILLEGALiMG,/*!< ���̷����������ȷ */
	LG_ERR_NULLPOINTER,/*!< ��ָ�� */
	LG_ERR_VALUETOOSMALL,/*!< ֵ��С */
	LG_ERR_NOINTERSECT,/*!< û�н��� */
	LG_ERR_HAVEINTERSECT,/*!< �н��� */
	LG_ERR_ERRID,/*!< ����id */
	LG_ERR_PARAM,/*!< �������� */
	LG_ERR_OTHER/*!< ���� */
};

/**
* @brief LG_Point������һ��·��
*/
typedef struct tagLG_Point
{
	int x;
	int y;
	tagLG_Point * pNext;/*!< ͷ�ڵ�Ϊ0��β�ڵ�Ϊ1 */
	tagLG_Point()
	{
		x = 0;
		y = 0;
		pNext = 0;
	}
}LG_Point;

typedef struct tagLG_Path
{
	LG_Point pointBegin;
	LG_Point pointEnd;
	int nPoint;
}LG_Path;