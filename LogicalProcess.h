#pragma once
/*****************************************************************************
*                                                  *
*  Copyright (C) 2017 zhaozhiyuan  1457321461@qq.com                         *
*
*                                                                            *
*  @file     LinkGamgeMainWnd.h                                                       *
*  @brief    ���ļ��ļ���                                                      *
*  Details.                                                                  *
*                                                                            *
*  @author   zhaozhiyuan                                                       *
*  @email    1457321461@qq.com                                              *
*  @version  1.0.0.1(�汾��)                                                  *
*  @date     2017.08.31                                              *
*  @license  GNU General Public License (GPL)                                *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : Description                                              *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>
| <Description>                   *
*----------------------------------------------------------------------------*
*  2017/08/30 | 1.0.0.1   | zhaozhiyuan      | Create file                     *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/

//����������ϵ
//0 | 1  2  3  4
//1	|	|	|	|
//2	|	|	|	|
//3	|	|	|	|
#include "BaseHeader.h"
#include "windows.h"
#include "time.h"
//#include "afx.h"
#include <vector>
#include <map>
#include <utility>  
#include <assert.h>
#include <string>
#define EASYXLENGTH 10
#define EASYYLENGTH 10
#define HARDXLENGTH 20
#define HARDYLENGTH 20
enum LINKGAMEGAMEMODE
{
	easy = 0,
	hard = 1,
	other
};

enum Orientation
{
	horizontal = 0,
	vertical
};
typedef struct tagBaseData
{
	void * pUserData;
	int		nIndex;
}BaseDataST;

typedef struct tagBlockBase
{
	void *					pUserData;
	int						nIndex;
	bool					isExist;
	tagBlockBase()
	{
		pUserData = 0;
		nIndex = 0;
		isExist = false;//Ĭ�ϲ�����
	}
}BlockBaseST;

typedef struct tagRectangleArea
{
	int nHeght;
	int nWidth;
	int nBorderSize;
	//top left corner point coordinate
	int tlcX;
	int tlcY;
	//
}RectangleAreaST;

typedef struct tagBlockInfomation : public BlockBaseST, public RectangleAreaST
{
	const char* lpszNormalImg;//normal show img
	const char* lpszHotImg;
	const char* lpszPushImg;
	const char* lpszForbidImg;
	const char* lpszBorderImg;
	tagBlockInfomation & operator= (const tagBlockInfomation & tbi)
	{
		pUserData = tbi.pUserData;
		nIndex = tbi.nIndex;
		isExist = tbi.isExist;
		nHeght = tbi.nHeght;
		nWidth = tbi.nWidth;
		nBorderSize = tbi.nBorderSize;
		tlcX = tbi.tlcX;
		tlcY = tbi.tlcY;
		if (tbi.lpszNormalImg)
		{
			std::string * str1 = new std::string;  *str1 = tbi.lpszNormalImg; lpszNormalImg = (*str1).c_str();
		}
		if (tbi.lpszHotImg)
		{
			std::string * str2 = new std::string; *str2 = tbi.lpszHotImg; lpszHotImg = (*str2).c_str();
		}
		if (tbi.lpszPushImg)
		{
			std::string * str3 = new std::string; *str3 = tbi.lpszPushImg; lpszPushImg = (*str3).c_str();
		}
		if (tbi.lpszForbidImg)
		{
			std::string * str4 = new std::string; *str4 = tbi.lpszForbidImg; lpszForbidImg = (*str4).c_str();
		}
		if (tbi.lpszForbidImg)
		{
			std::string * str5 = new std::string; *str5 = tbi.lpszBorderImg; lpszBorderImg = (*str5).c_str();
		}
		return *this;
	}
}BlockInfomationST;


typedef struct tagLG_ConvertInfo
{
	int realX;
	int realY;
	int realWidth;
	int realHeight;
}LG_ConvertInfo;
class CLogicalProcess
{
public:
	CLogicalProcess();

	~CLogicalProcess();

	LGErrorStates InitData(int x, int y);

	/**
	* @brief SetData
	* @param int        x @
	* @param int        y @
	* @param int        nIndex @
	* @param void *        pUserData @
	* @return LGErrorStates��xyΪ����������
	*        -<em>LGErrorStates</em> fail
	*
	*/
	LGErrorStates SetData(int x, int y, int nIndex, void * pUserData);//only test
																	  /**
																	  * @brief SetDataEx
																	  * @param int        x @
																	  * @param int        y @
																	  * @param BlockInfomationST*        pInfo @
																	  * @return LGErrorStates��xyΪ������������pInfoΪ���������Ϣ������״̬ͼƬ������Ĵ�С
																	  *        -<em>LGErrorStates</em> fail
																	  *
																	  */
	LGErrorStates SetDataEx(int x, int y, BlockInfomationST * pInfo);
	/**
	* @brief GetConnectInfo
	* @param LG_Path        path @
	* ...
	* @return LGErrorStates�����ص�path����Ϊ������꣬��Ҫת������������ſ��Ի���ʵ��·��
	*        -<em>LGErrorStates</em> fail
	*
	*/
	LGErrorStates GetConnectInfo(/*OUT*/LG_Path & path, int x1, int y1, int x2, int y2);

	LGErrorStates ConvertPath(/*IN*/LG_Path & logicPath, /*OUT*/LG_Path & realPath, LG_ConvertInfo info);


	void SetGameMode(LINKGAMEGAMEMODE lggm);

	LINKGAMEGAMEMODE GetGameMode();

	bool GetBlockInformation(BlockInfomationST ** pInfo, int x, int y);//memory release outside must
public:
	BlockInfomationST m_easyMode[EASYXLENGTH][EASYYLENGTH];
	BlockInfomationST m_hardMode[HARDXLENGTH][HARDYLENGTH];
	BlockInfomationST m_UDMode[16][9];
	LINKGAMEGAMEMODE m_GameMode;
protected:

	bool IsBlockExist(int x, int y);


private:
	/*BaseDataST **/
	//һ��·��ʱ����жϵ������㶼����ʱ���������������Ϊ������ʱ����Ҫ�����ָ��������Բſ��������ж�
	bool IsOneLoadConnect(int x1, int y1, int x2, int y2);
	bool IsTwoLoadConnect(int x1, int y1, int x2, int y2, LG_Path & path);
	bool IsTwoLoadConnect(int x1, int y1, int x2, int y2, /*OUT*/std::vector<LG_Path> * vec);//Ϊ�˱�֤�ٶȣ�ֻ�����ж�����·����ʱ��Ż�ʹ�����������ȡ���������������
	bool IsThreeLoadConnect(int x1, int y1, int x2, int y2, LG_Path & path);
	void SetPointInformation(int x, int y, bool isExist);//���õ��Ƿ����
	bool IsHaveobstacle(int x1, int y1, int x2, int y2, Orientation ori);//�ж�����֮���Ƿ���һ�����������
	void ClearPoint(int x1, int y1, int x2, int y2);
	//new add at 20170914 by zy
	void SetPointIndex(int x , int y , int nIndex);
};
class CLinkGameGenerate
{
public:
	typedef struct tagRANGE
	{
		int n;
		int m;
		tagRANGE()
		{
			n = 0;
			m = 0;
		}
	}RangeST;
public:
	//Ҫ�󷽸��������Ϊż��
	/*********************************/
	//����һ��ָ����Χ�������
	//��Χ n~m;������������ΪM
	//��ʽΪ��[M%(m-n+1)]+n
	/*********************************/
	LGErrorStates Methods1(int nx, int ny);//
	LGErrorStates Methods2(int nx, int ny, /*OUT*/void * p, int nTypes);//1.���������һ���Ԫ��2.����3.�������provide by shangji

																		//@note ע�����ﴫ��Ķ�ά����Ĭ���Ѿ��洢����ָ�벢���������Ϊ-1
	LGErrorStates Methods3(int nx, int ny, /*OUT*/void * p, RangeST & _range);//1.���������һ���Ԫ��2.����3.�������
																			  //@note end

	LGErrorStates RandomDisturb1(void * p, int nx, int ny);//ϴ���㷨ʵ��
														   //LGErrorStates GetMethods1Result(/*type rlt*/);
private:
	int GenerateRandNum(int * pInt, bool & b, RangeST & range);

};