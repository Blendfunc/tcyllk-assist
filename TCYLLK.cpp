#include"stdio.h"
#include"windows.h"
#include "TlHelp32.h"
#include"LogicalProcess.h"
//#define QQLLK
#define excelso
//#pragma comment(lib,"Project1.lib")

#ifdef primary
#define XLENGTH
#define YLENGTH
#define BLANK 31
#endif // primary
#ifdef middlerank
#define XLENGTH
#define YLENGTH
#define BLANK 27
#endif // middlerank
#ifdef advanced
#define XLENGTH
#define YLENGTH
#define BLANK 23
#endif // advanced
#ifdef excelso
#define XLENGTH 16
#define YLENGTH 9
#define BLANK 0
#endif // Excelso
//�������������Ƶ�����λ��
#define firstpointx 356
#define firstpointy 437
//#define pid 12924
//#define hwnd 71968198
#define baseaddress 4480460
#define stepx 45
#define stepy 45
//
static int num = XLENGTH * YLENGTH;

void click(int x1, int y1, int x2, int y2, int numex , HWND llkwnd)
{
	///
	if (num == 2)
	{
		POINT oldpoint;
		GetCursorPos(&oldpoint);
		/*SetCursorPos(569, 472);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);*/
		int clickx = firstpointx + ((x1) * stepx);
		int clicky = firstpointy + ((y1) * stepy);
		SetCursorPos(clickx, clicky);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
//		SendMessage((HWND)llkwnd, WM_LBUTTONDOWN, NULL, MAKELPARAM(clickx, clicky));
		//	SendMessage((HWND)hwnd, WM_LBUTTONUP, NULL, MAKELPARAM(clickx, clicky));
		Sleep(100);
		///
		int _clickx = firstpointx + ((x2) * stepx);
		int _clicky = firstpointy + ((y2) * stepy);
		SetCursorPos(_clickx, _clicky);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
//		PostMessage((HWND)llkwnd, WM_LBUTTONDOWN, NULL, MAKELPARAM(_clickx, _clicky));
		//SendMessage((HWND)hwnd, WM_LBUTTONDOWN, NULL, MAKELPARAM(413, 335));
		//SendMessage((HWND)hwnd, WM_LBUTTONUP, NULL, MAKELPARAM(413, 335));

		Sleep(500);
		//SendMessage(FindWindow("#32770", "�ɹ�"), WM_LBUTTONDOWN, NULL, MAKELPARAM(95, 129));
		//SendMessage(FindWindow("#32770", "�ɹ�"), WM_LBUTTONUP, NULL, MAKELPARAM(95, 129));
//		HWND h = FindWindowEx(FindWindow("#32770", "�ɹ�"), NULL, NULL, NULL);
		//h = FindWindow("#32770", "�ɹ�");1019 854

		SetCursorPos(1019, 854);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);



//		SendMessage(h, WM_LBUTTONDOWN, NULL, MAKELPARAM(10, 10));
//		SendMessage(h, WM_LBUTTONUP, NULL, MAKELPARAM(10, 10));
		Sleep(100);


		SetCursorPos(oldpoint.x, oldpoint.y);

		char szfilename[MAX_PATH];
		GetModuleFileName(NULL, szfilename, MAX_PATH);

		WinExec(szfilename, SW_SHOW);

		HANDLE hself = GetCurrentProcess();
		TerminateProcess(hself, 0);
	}
	else
	{
		POINT oldpoint;
		GetCursorPos(&oldpoint);



		int clickx = firstpointx + ((x1) * stepx);
		int clicky = firstpointy + ((y1) * stepy);
		SetCursorPos(clickx, clicky);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		//SendMessage((HWND)llkwnd, WM_LBUTTONDOWN, NULL, MAKELPARAM(clickx, clicky));
		//SendMessage((HWND)llkwnd, WM_LBUTTONUP, NULL, MAKELPARAM(clickx, clicky));
		Sleep(100);
		///
		int _clickx = firstpointx + ((x2) * stepx);
		int _clicky = firstpointy + ((y2) * stepy);
//		SendMessage((HWND)llkwnd, WM_LBUTTONDOWN, NULL, MAKELPARAM(_clickx, _clicky));
//		SendMessage((HWND)llkwnd, WM_LBUTTONUP, NULL, MAKELPARAM(_clickx, _clicky));

		//	PostMessage((HWND)hwnd, WM_LBUTTONUP, NULL, MAKELPARAM(_clickx, _clicky));
		SetCursorPos(_clickx, _clicky);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		//getchar();
		//Sleep(1000);
		//Sleep(100);
		Sleep(100);

		SetCursorPos(oldpoint.x, oldpoint.y);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

		getchar();



	}
}
void readdata(CLogicalProcess & lp , DWORD LLKID)
{
	int matrix[XLENGTH][YLENGTH];
	//�������Ԫ�ظ�ֵ-1(����һ�У���һ�У����һ�У����һ��Ԫ�ظ�ֵ-1)
	//for (int i = 0; i < XLENGTH; i++)
	//{
	//	//��һ��
	//	matrix[i][0] = 88888;
	//	//
	//}
	//for (int i = 0; i < XLENGTH; i++)
	//{
	//	//���һ��
	//	matrix[i][YLENGTH - 1] = 88888;
	//	//
	//}
	//for (int i = 0; i < YLENGTH; i++)
	//{
	//	//��һ��
	//	matrix[0][i] = 88888;
	//	//
	//}
	//for (int i = 0; i < YLENGTH; i++)
	//{
	//	//���һ��
	//	matrix[XLENGTH - 1][i] = 88888;
	//	//
	//}

	LINKGAMEGAMEMODE lggm = LINKGAMEGAMEMODE::other;
	lp.SetGameMode(lggm);



	/*DWORD LLKID = pid;*/
	HANDLE hLLK = OpenProcess(PROCESS_VM_READ, FALSE, LLKID);
	if (hLLK == NULL)
	{
		//error
	}


	//��ֻ�Ƕ��ڴ棬Ӧ��Ĭ�϶��ж���Ȩ���˰ɣ��������Ӧ�ÿ���VirtualProtectEx


	LPCVOID lpBaseAddress = (LPCVOID)baseaddress;
	int nMem = ((XLENGTH ) * (YLENGTH)) + ((XLENGTH - 2 - 1) * BLANK);
	LPVOID lpBuffer = malloc(nMem);

	SIZE_T nSize = nMem;
	SIZE_T *lpNumberOfBytesRead = NULL;
	ReadProcessMemory(hLLK, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead);

	//��ʼ��ȡ�ڴ沢��ʼ������
	LPVOID address = lpBuffer;
	for (int i = 0; i < XLENGTH; i++)
	{
		for (int j = 0; j < YLENGTH; j++)
		{

			byte * pData = (byte *)address;
			byte data = *pData;
			*pData = 1;
			matrix[i + 0][j + 0] = (int)data;
			int nextAddress = int(address);
			nextAddress = nextAddress + 1;
			address = (LPVOID)nextAddress;
		}
		int newAddress = (int)address;
		newAddress = newAddress - 1 + BLANK + 1;
		address = (LPVOID)newAddress;
	}
	for (int i = 0; i < YLENGTH; i++)
	{
		for (int j = 0; j < XLENGTH; j++)
		{
			BlockInfomationST block;
			memset(&block, 0, sizeof(BlockInfomationST));
			//����������ÿ�������id����Ӧ��ͼƬ������
			block.nIndex = matrix[j][i];
			block.tlcX = j;
			block.tlcY = i;
			block.isExist = true;
			/*if (block.nIndex == 88888)
			{
				block.nIndex = -1;
				block.isExist = false;
			}*/
			if (block.nIndex == 0)
			{
				block.nIndex = -1;
				block.isExist = false;
				num--;
			}
			lp.SetDataEx(j, i, &block);
		}
	}


	//
	//������ʾ
	for (int i = 0; i < YLENGTH; i++)
	{
	for (int j = 0; j < XLENGTH; j++)
	{
	printf("%d          ", (lp.m_UDMode)[j][i].nIndex);
	}
	printf("\n");
	}

	//
	CloseHandle(hLLK);
	free(lpBuffer);
	//delete(lpBuffer);
}
DWORD GetProcessIDByName(const char* pName)
{

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return NULL;
	}
	PROCESSENTRY32 pe = { sizeof(pe) };
	for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
		if (strcmp(pe.szExeFile, pName) == 0) {
			CloseHandle(hSnapshot);
			return pe.th32ProcessID;
		}
		//printf("%-6d %s\n", pe.th32ProcessID, pe.szExeFile);
	}
	CloseHandle(hSnapshot);
	return 0;
}
void main()
{
	
	//���ö��㴰��
	char pszNewWindowTitle[1024]; // Contains fabricated
										   // WindowTitle.
	char pszOldWindowTitle[1024];
	GetConsoleTitle(pszOldWindowTitle, 1024);
	HWND hwndFound = FindWindow(NULL, pszOldWindowTitle);


	SetWindowPos(hwndFound, HWND_TOPMOST, 1920-300+1, 1080-300+1, 300,300, 0/*SWP_NOMOVE | SWP_NOSIZE*/);
	
	
	//char szfilename[MAX_PATH];
	//GetModuleFileName(NULL, szfilename, MAX_PATH);

	//WinExec(szfilename, SW_SHOW);
	//HANDLE hself = GetCurrentProcess();
	//TerminateProcess(hself, 0);
	POINT oldpoint;
	GetCursorPos(&oldpoint);
	SetCursorPos(oldpoint.x, oldpoint.y);
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);



	getchar();
	HWND mainwnd = FindWindow(NULL, "������");
	HWND childwnd = FindWindowEx(mainwnd, NULL, "AfxMDIFrame42", NULL);
	HWND llkwnd = FindWindowEx(childwnd, NULL, "#32770", NULL);
	DWORD id = GetProcessIDByName("llkk.exe");
	CLogicalProcess lp;
	readdata(lp , id);
	//��ʼ����
	//�ӣ�0��0������XLENGTH - 1�� YLENGTH - 1��
	int x = 0; int y = 0;
	int _x = 1; int _y = 0;
//	int num = (XLENGTH) * (YLENGTH);//��ȷ��
	LG_Path path;
	while (true)
	{
		x = -1; y = 0;
		while (x != XLENGTH - 1 || y != YLENGTH - 1)
		{
			if (x == XLENGTH - 1)
			{
				x = 0; y++;
				_y = y; _x = x;
				while (_x != XLENGTH - 1 || _y != YLENGTH - 1)
				{
					if (_x == XLENGTH - 1)
					{
						_x = 0; _y++;
						if (lp.m_UDMode[x][y].nIndex == lp.m_UDMode[_x][_y].nIndex)
						{
							if (lp.GetConnectInfo(path, x, y, _x, _y) != LG_ERR_NOPATHCONNECT)
							{
								//����������ѭ��
								click(x, y, _x, _y, num , llkwnd);
								num = num - 2;
								if (num == 0)
								{
									/*x = XLENGTH - 2; y = YLENGTH - 2;
									num = (XLENGTH - 2) * (YLENGTH - 2);*/
								}
								/*system("cls");
								for (int i = 0; i < YLENGTH; i++)
								{
								for (int j = 0; j < XLENGTH; j++)
								{
								printf("%d  ", (lp.m_UDMode)[j][i].nIndex);
								}
								printf("\n");
								}*/
								//readdata(lp);
								break;
							}
						}

					}
					else if (_y == YLENGTH - 1)
					{
						_x++;
						if (lp.m_UDMode[x][y].nIndex == lp.m_UDMode[_x][_y].nIndex)
						{
							if (lp.GetConnectInfo(path, x, y, _x, _y) != LG_ERR_NOPATHCONNECT)
							{
								//����������ѭ��
								click(x, y, _x, _y, num , llkwnd);
								num = num - 2;
								if (num == 0)
								{
									/*x = XLENGTH - 2; y = YLENGTH - 2;
									num = (XLENGTH - 2) * (YLENGTH - 2);*/
								}
								//readdata(lp);
								/*system("cls");
								for (int i = 0; i < YLENGTH; i++)
								{
									for (int j = 0; j < XLENGTH; j++)
									{
										printf("%d  ", (lp.m_UDMode)[j][i].nIndex);
									}
									printf("\n");
								}*/
								break;
							}
						}
					}
					else
					{
						_x++;
						if (lp.m_UDMode[x][y].nIndex == lp.m_UDMode[_x][_y].nIndex)
						{
							if (lp.GetConnectInfo(path, x, y, _x, _y) != LG_ERR_NOPATHCONNECT)
							{
								//����������ѭ��
								click(x, y, _x, _y, num , llkwnd);
								num = num - 2;
								if (num == 0)
								{
									/*x = XLENGTH - 2; y = YLENGTH - 2;
									num = (XLENGTH - 2) * (YLENGTH - 2);*/
								}
								//readdata(lp);
								/*system("cls");
								for (int i = 0; i < YLENGTH; i++)
								{
									for (int j = 0; j < XLENGTH; j++)
									{
										printf("%d  ", (lp.m_UDMode)[j][i].nIndex);
									}
									printf("\n");
								}*/
								break;
							}
						}
					}
				}
			}
			else if (y == YLENGTH - 1)
			{
				x++;
				_y = y; _x = x;
				while (_x != XLENGTH - 1 || _y != YLENGTH - 1)
				{
					if (_x == XLENGTH - 1)
					{
						_x = 0; _y++;
						if (lp.m_UDMode[x][y].nIndex == lp.m_UDMode[_x][_y].nIndex)
						{
							if (lp.GetConnectInfo(path, x, y, _x, _y) != LG_ERR_NOPATHCONNECT)
							{
								//����������ѭ��
								click(x, y, _x, _y, num , llkwnd);
								num = num - 2;
								if (num == 0)
								{
									/*x = XLENGTH - 2; y = YLENGTH - 2;
									num = (XLENGTH - 2) * (YLENGTH - 2);*/
								}
								//readdata(lp);
							/*	system("cls");
								for (int i = 0; i < YLENGTH; i++)
								{
									for (int j = 0; j < XLENGTH; j++)
									{
										printf("%d  ", (lp.m_UDMode)[j][i].nIndex);
									}
									printf("\n");
								}*/
								break;
							}
						}

					}
					else if (_y == YLENGTH - 1)
					{
						_x++;
						if (lp.m_UDMode[x][y].nIndex == lp.m_UDMode[_x][_y].nIndex)
						{
							if (lp.GetConnectInfo(path, x, y, _x, _y) != LG_ERR_NOPATHCONNECT)
							{
								//����������ѭ��
								click(x, y, _x, _y, num , llkwnd);
								num = num - 2;
								if (num == 0)
								{
									/*x = XLENGTH - 2; y = YLENGTH - 2;
									num = (XLENGTH - 2) * (YLENGTH - 2);*/
								}
								/*system("cls");
								for (int i = 0; i < YLENGTH; i++)
								{
									for (int j = 0; j < XLENGTH; j++)
									{
										printf("%d  ", (lp.m_UDMode)[j][i].nIndex);
									}
									printf("\n");
								}*/
								//readdata(lp);
								break;
							}
						}
					}
					else
					{
						_x++;
						if (lp.m_UDMode[x][y].nIndex == lp.m_UDMode[_x][_y].nIndex)
						{
							if (lp.GetConnectInfo(path, x, y, _x, _y) != LG_ERR_NOPATHCONNECT)
							{
								//����������ѭ��
								click(x, y, _x, _y, num , llkwnd);
								num = num - 2;
								if (num == 0)
								{
									/*x = XLENGTH - 2; y = YLENGTH - 2;
									num = (XLENGTH - 2) * (YLENGTH - 2);*/
								}
								/*system("cls");
								for (int i = 0; i < YLENGTH; i++)
								{
									for (int j = 0; j < XLENGTH; j++)
									{
										printf("%d  ", (lp.m_UDMode)[j][i].nIndex);
									}
									printf("\n");
								}*/
								//readdata(lp);
								break;
							}
						}
					}
				}
			}
			else
			{
				x++;
				_y = y; _x = x;
				while (_x != XLENGTH - 1 || _y != YLENGTH - 1)
				{
					if (_x == XLENGTH - 1)
					{
						_x = 0; _y++;
						if (lp.m_UDMode[x][y].nIndex == lp.m_UDMode[_x][_y].nIndex)
						{
							if (lp.GetConnectInfo(path, x, y, _x, _y) != LG_ERR_NOPATHCONNECT)
							{
								//����������ѭ��
								click(x, y, _x, _y, num , llkwnd);
								num = num - 2;
								if (num == 0)
								{
									/*x = XLENGTH - 2; y = YLENGTH - 2;
									num = (XLENGTH - 2) * (YLENGTH - 2);*/
								}
								/*system("cls");
								for (int i = 0; i < YLENGTH; i++)
								{
									for (int j = 0; j < XLENGTH; j++)
									{
										printf("%d  ", (lp.m_UDMode)[j][i].nIndex);
									}
									printf("\n");
								}*/
								//readdata(lp);
								break;
							}
						}

					}
					else if (_y == YLENGTH - 1)
					{
						_x++;
						if (lp.m_UDMode[x][y].nIndex == lp.m_UDMode[_x][_y].nIndex)
						{
							if (lp.GetConnectInfo(path, x, y, _x, _y) != LG_ERR_NOPATHCONNECT)
							{
								//����������ѭ��
								click(x, y, _x, _y, num , llkwnd);
								num = num - 2;
								if (num == 0)
								{
									/*x = XLENGTH - 2; y = YLENGTH - 2;
									num = (XLENGTH - 2) * (YLENGTH - 2);*/
								}
								/*system("cls");
								for (int i = 0; i < YLENGTH; i++)
								{
									for (int j = 0; j < XLENGTH; j++)
									{
										printf("%d  ", (lp.m_UDMode)[j][i].nIndex);
									}
									printf("\n");
								}*/
								//readdata(lp);
								break;
							}
						}
					}
					else
					{
						_x++;
						if (lp.m_UDMode[x][y].nIndex == lp.m_UDMode[_x][_y].nIndex)
						{
							if (lp.GetConnectInfo(path, x, y, _x, _y) != LG_ERR_NOPATHCONNECT)
							{
								//����������ѭ��
								click(x, y, _x, _y, num , llkwnd);
								num = num - 2;
								if (num == 0)
								{
									/*x = XLENGTH - 2; y = YLENGTH - 2;
									num = (XLENGTH - 2) * (YLENGTH - 2);*/

								}
								/*system("cls");
								for (int i = 0; i < YLENGTH; i++)
								{
									for (int j = 0; j < XLENGTH; j++)
									{
										printf("%d  ", (lp.m_UDMode)[j][i].nIndex);
									}
									printf("\n");
								}*/
								//readdata(lp);
								break;
							}
						}
					}
				}
			}
		}
		if (num == 0)
		{
			/*num = (XLENGTH - 2) * (YLENGTH - 2);
			SetCursorPos(569, 472);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);*/
		}

	}

	//
	getchar();
}