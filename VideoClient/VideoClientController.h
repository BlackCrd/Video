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
	//如果strUrl中包含中文符号或者字符，则使用utf-8编码
	int SetMedia(const std::string & strUrl);
	//返回-1.0表示错误
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

