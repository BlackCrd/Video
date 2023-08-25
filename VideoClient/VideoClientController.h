#pragma once
#include "BVlc.h"
#include "VideoClientDlg.h"
enum BVlcCommand{
	BVLC_PLAY,
	BVLC_PAUSE,
	BVLC_STOP,
	BVLC_GET_VOLUME,
	BVLC_GET_POSITION,
	BVLC_GET_LENGTH
};
class VideoClientController
{
public:
	VideoClientController();
	~VideoClientController();
	int Init(CWnd*& pWnd);
	int Invoke();
	//���strUrl�а������ķ��Ż����ַ�����ʹ��utf-8����
	int SetMedia(const std::string & strUrl);
	//����-1.0��ʾ����
	float VideoCtrl(BVlcCommand cmd);
	void SetPosition(float pos);
	int SetWnd(HWND hWnd);
	int SetVolume(int volume);
	VlcSize GetMediaInfo();
	std::string Unicode2Utf8(const std::wstring& strIn);
protected:
	BVlc m_vlc;
	CVideoClientDlg m_dlg;
};

